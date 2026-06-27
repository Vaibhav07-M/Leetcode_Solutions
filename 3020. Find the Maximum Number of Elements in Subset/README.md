# 3020. Find the Maximum Number of Elements in Subset

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Greedy`

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

[LeetCode — 3020. Find the Maximum Number of Elements in Subset](https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/)

---

## Problem Summary

You are given an array of positive integers `nums`.

Select the largest possible subset that can be arranged in the following form:

```text
[x, x², x⁴, ..., xᵏ⁄², xᵏ, xᵏ⁄², ..., x⁴, x², x]
```

where `k` is a non-negative power of `2`.

Each number in the subset can be used at most as many times as it appears in `nums`.

Return the maximum possible number of elements in such a subset.

---

## Examples

### Example 1

**Input:**

```cpp
nums = [5,4,1,2,2]
```

**Output:**

```cpp
3
```

**Explanation:**

Choose the subset:

```text
{2,4,2}
```

which forms:

```text
[2,4,2]
```

where:

```text
2² = 4
```

---

### Example 2

**Input:**

```cpp
nums = [1,3,2,4]
```

**Output:**

```cpp
1
```

**Explanation:**

No valid chain longer than one element can be formed, so selecting any single element is optimal.

---

## Intuition

A valid subset forms a symmetric chain:

```text
x → x² → x⁴ → ...
```

Every value except the center must appear **twice**—once on the left side and once on the right.

Therefore:

- If a value appears at least twice, it can extend the chain.
- If it appears exactly once, it can only serve as the center.
- If the next squared value does not exist, the chain ends.

The value `1` is a special case because:

```text
1² = 1
```

so all selected elements are identical. The maximum valid chain of `1`s must always have **odd length**.

---

## Approach

### 1. Count Frequencies

Store the frequency of every number using a hash map.

---

### 2. Handle the Special Case of `1`

Since:

```text
1² = 1
```

a valid sequence consists only of `1`s.

If there are:

- an odd number of `1`s, use all of them.
- an even number, use one fewer to keep the length odd.

---

### 3. Try Every Possible Starting Value

For every distinct value except `1`:

- Start building the chain.
- If the current value appears at least twice, use two copies.
- Move to its square.
- If the current value appears exactly once, use it as the center and stop.
- If the squared value does not exist, remove one previously counted element because a center cannot be formed.

The solution also checks for overflow before squaring.

---

### 4. Keep the Maximum Length

Update the answer with the longest valid chain found.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n log M)` (average), where `M` is the maximum value reached while squaring |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        // Special case for 1
        if (cnt.count(1)) {
            int c = cnt[1];
            ans = max(ans, (c % 2 == 0) ? c - 1 : c);
        }

        for (auto &[start, freq] : cnt) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (true) {
                if (!cnt.count(cur)) {
                    // No center exists
                    len--;
                    break;
                }

                if (cnt[cur] == 1) {
                    // Can use as center
                    len++;
                    break;
                }

                // Use two copies of cur
                len += 2;

                // Prevent overflow before squaring
                if (cur > 1000000000LL / cur) {
                    len--;
                    break;
                }

                cur = cur * cur;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Count the frequency of every number using a hash map.
- Every non-center value in the chain must appear at least twice.
- A value appearing exactly once can only serve as the center.
- Treat `1` separately since squaring it never changes its value.
- Check for overflow before repeatedly squaring numbers.
- Greedily extending each possible chain yields the maximum valid subset.