# 1840. Maximum Building Height

**Difficulty:** `Hard`  
**Tags:** `Greedy`, `Math`, `Sorting`

---

## Table of Contents
- [Problem Link](#problem-link)
- [Problem Summary](#problem-summary)
- [Examples](#examples)
- [Intuition](#intuition)
- [Approach](#approach)
- [Complexity](#complexity)
- [Code (C++)](#code-c)
- [Key Takeaways](#key-takeaways)

---

## Problem Link

[LeetCode — 1840. Maximum Building Height](https://leetcode.com/problems/maximum-building-height/)

---

## Problem Summary

You want to build `n` buildings numbered from `1` to `n`.

The following conditions must hold:

- Building `1` must have height `0`.
- Heights are non-negative integers.
- The height difference between adjacent buildings cannot exceed `1`.
- Some buildings have maximum height restrictions.

Each restriction is given as:

```cpp
[id, maxHeight]
```

meaning building `id` cannot exceed `maxHeight`.

Return the **maximum possible height of the tallest building**. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:**

```cpp
n = 5
restrictions = [[2,1],[4,1]]
```

**Output:**

```cpp
2
```

**Explanation:**

One valid arrangement is:

```text
[0,1,2,1,2]
```

The tallest building has height `2`. :contentReference[oaicite:1]{index=1}

---

### Example 2

**Input:**

```cpp
n = 6
restrictions = []
```

**Output:**

```cpp
5
```

**Explanation:**

A valid arrangement is:

```text
[0,1,2,3,4,5]
```

The tallest building has height `5`. :contentReference[oaicite:2]{index=2}

---

### Example 3

**Input:**

```cpp
n = 10
restrictions = [[5,3],[2,5],[7,4],[10,3]]
```

**Output:**

```cpp
5
```

**Explanation:**

One valid arrangement is:

```text
[0,1,2,3,3,4,4,5,4,3]
```

The tallest building has height `5`. :contentReference[oaicite:3]{index=3}

---

## Intuition

The restriction values may not be mutually consistent.

For example, if one building is forced to be very low, nearby buildings cannot suddenly become very high because adjacent heights can differ by at most `1`.

Therefore, before finding the answer, we must propagate restrictions:

- From left to right.
- From right to left.

After these adjustments, every restriction becomes achievable.

Once all restrictions are valid, the maximum height between two consecutive restricted buildings can be computed mathematically.

---

## Approach

### 1. Add Boundary Restrictions

Building `1` must always have height `0`:

```cpp
restrictions.push_back({1, 0});
```

If building `n` is not restricted, add:

```cpp
{n, n - 1}
```

because the tallest possible height at building `n` cannot exceed `n - 1`.

---

### 2. Sort Restrictions

Sort by building index so neighboring restrictions can be processed easily.

---

### 3. Left-to-Right Pass

For every restriction:

```cpp
height[i] <= height[i-1] + distance
```

Update each restriction to satisfy the previous one.

---

### 4. Right-to-Left Pass

Similarly:

```cpp
height[i] <= height[i+1] + distance
```

Update each restriction to satisfy the next one.

After both passes, all restrictions become consistent.

---

### 5. Compute Maximum Peak

For two consecutive restricted buildings:

```cpp
(x1, h1)
(x2, h2)
```

with distance:

```cpp
dist = x2 - x1
```

The highest achievable peak between them is:

```cpp
(h1 + h2 + dist) / 2
```

This represents climbing from the lower side and descending toward the other restriction as much as possible.

Take the maximum over all segments.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(m log m)` due to sorting |
| **Space** | `O(1)` extra space (excluding input storage) |

Where `m` is the number of restrictions.

---

## Code (C++)

```cpp
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});

        bool hasN = false;
        for (auto &r : restrictions) {
            if (r[0] == n) {
                hasN = true;
                break;
            }
        }

        if (!hasN)
            restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left -> Right
        for (int i = 1; i < m; i++) {
            long long dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] =
                min((long long)restrictions[i][1],
                    (long long)restrictions[i - 1][1] + dist);
        }

        // Right -> Left
        for (int i = m - 2; i >= 0; i--) {
            long long dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] =
                min((long long)restrictions[i][1],
                    (long long)restrictions[i + 1][1] + dist);
        }

        long long ans = 0;

        for (int i = 1; i < m; i++) {

            long long x1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long x2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long dist = x2 - x1;

            ans = max(ans, (h1 + h2 + dist) / 2);
        }

        return (int)ans;
    }
};
```

---

## Key Takeaways

- Add boundary restrictions for building `1` and building `n`.
- Use two passes to make all restrictions consistent.
- Adjacent buildings differing by at most `1` creates a slope constraint.
- The maximum height between two restricted points can be computed mathematically.
- Greedy propagation + interval peak calculation yields the optimal answer.
- Time complexity is dominated by sorting: `O(m log m)`.