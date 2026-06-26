# 3739. Count Subarrays With Majority Element II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Prefix Sum`, `Binary Tree`, `Coordinate Compression`

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

[LeetCode — 3739. Count Subarrays With Majority Element II](https://leetcode.com/problems/count-subarrays-with-majority-element-ii/)

---

## Problem Summary

You are given:

- An integer array `nums`.
- An integer `target`.

Return the number of subarrays in which `target` is the **majority element**.

An element is considered a majority element if it appears **strictly more than half** the number of times in the subarray. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:**

```cpp
nums = [1,2,2,3]
target = 2
```

**Output:**

```cpp
5
```

**Explanation:**

Valid subarrays are:

```text
[2]
[2]
[2,2]
[1,2,2]
[2,2,3]
```

So the answer is `5`. :contentReference[oaicite:1]{index=1}

---

### Example 2

**Input:**

```cpp
nums = [1,1,1,1]
target = 1
```

**Output:**

```cpp
10
```

**Explanation:**

Every subarray has `1` as the majority element. :contentReference[oaicite:2]{index=2}

---

### Example 3

**Input:**

```cpp
nums = [1,2,3]
target = 4
```

**Output:**

```cpp
0
```

**Explanation:**

Since `target` does not appear in the array, no valid subarray exists. :contentReference[oaicite:3]{index=3}

---

## Intuition

Just like Part I, convert the array into:

- `+1` if the element equals `target`
- `-1` otherwise

A subarray has `target` as the majority element if its transformed sum is **positive**.

Instead of checking every subarray, observe that:

```cpp
prefix[r + 1] - prefix[l] > 0
```

is equivalent to:

```cpp
prefix[l] < prefix[r + 1]
```

Therefore, for each prefix sum, we only need to count how many previous prefix sums are **strictly smaller**.

A **Binary Indexed Tree (Fenwick Tree)** together with **coordinate compression** allows these queries to be answered efficiently.

---

## Approach

### 1. Build Prefix Sum

Transform the array:

```cpp
target -> +1
others -> -1
```

Then compute:

```cpp
prefix[i]
```

where each value represents the cumulative transformed sum.

---

### 2. Coordinate Compression

Prefix sums may be negative, so compress all unique prefix values into the range:

```cpp
1 ... m
```

This allows them to be used as Fenwick Tree indices.

---

### 3. Process Prefix Sums

Traverse every prefix sum in order.

For the current prefix value:

- Find its compressed index.
- Query the Fenwick Tree for the number of previous prefix sums that are **strictly smaller**.
- Add that count to the answer.
- Insert the current prefix sum into the Fenwick Tree.

This efficiently counts all valid subarrays ending at the current position.

---

### 4. Return the Answer

After processing all prefix sums, return the accumulated count.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n log n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick bit(vals.size());

        long long ans = 0;

        for (int x : prefix) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            // Count previous prefix sums strictly smaller than current
            ans += bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Transform the problem using:
  - `target → +1`
  - `others → -1`
- A positive subarray sum implies `target` is the majority element.
- The condition becomes counting previous prefix sums that are **strictly smaller** than the current one.
- Coordinate compression enables prefix sums to be stored in a Binary Indexed Tree.
- Fenwick Tree supports prefix count queries and updates in `O(log n)`.
- The overall solution runs in `O(n log n)` time.