# 3737. Count Subarrays With Majority Element I

**Difficulty:** `Medium`  
**Tags:** `Array`, `Prefix Sum`

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

[LeetCode — 3737. Count Subarrays With Majority Element I](https://leetcode.com/problems/count-subarrays-with-majority-element-i/)

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

Since `4` never appears in the array, it cannot be the majority element of any subarray. :contentReference[oaicite:3]{index=3}

---

## Intuition

Treat every occurrence of `target` as:

```cpp
+1
```

and every other element as:

```cpp
-1
```

For any subarray:

- A positive sum means there are more occurrences of `target` than all other elements combined.
- This is exactly the condition for `target` to be the majority element.

Using prefix sums allows us to compute each subarray sum in constant time.

---

## Approach

### 1. Build Prefix Sum

Create a prefix sum array where:

```cpp
target     -> +1
others     -> -1
```

So:

```cpp
prefix[i + 1]
```

stores the transformed sum of the first `i + 1` elements.

---

### 2. Check Every Subarray

Enumerate every pair:

```cpp
(l, r)
```

The transformed sum is:

```cpp
prefix[r + 1] - prefix[l]
```

If this value is positive:

```cpp
> 0
```

then `target` is the majority element of that subarray.

Increase the answer.

---

### 3. Return the Count

After checking all subarrays, return the total count.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n²)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        int ans = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (prefix[r + 1] - prefix[l] > 0)
                    ans++;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Convert the problem into a prefix sum by mapping:
  - `target → +1`
  - `others → -1`
- A positive subarray sum means `target` is the majority element.
- Prefix sums allow each subarray to be checked in `O(1)` time.
- Enumerating all subarrays results in an `O(n²)` solution.
- This approach is sufficient for the given constraints.