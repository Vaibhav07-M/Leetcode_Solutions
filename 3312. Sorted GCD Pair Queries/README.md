# 3312. Sorted GCD Pair Queries

**Difficulty:** `Hard`  
**Tags:** `Array`, `Math`, `Number Theory`, `GCD`, `Sorting`, `Binary Search`, `Prefix Sum`, `Inclusion-Exclusion`

---

## Table of Contents

- [Problem Link](#problem-link)
- [Problem Summary](#problem-summary)
- [Examples](#examples)
- [Intuition](#intuition)
- [Approach](#approach)
- [Proof](#proof)
- [Complexity](#complexity)
- [Code (C++)](#code-c)
- [Key Takeaways](#key-takeaways)

---

## Problem Link

[LeetCode – 3312. Sorted GCD Pair Queries](https://leetcode.com/problems/sorted-gcd-pair-queries/)

---

## Problem Summary

Given an integer array `nums`, construct an array containing the GCD of every unordered pair.

Sort this array in ascending order.

For each query `q`, return the value located at index `q` in the sorted GCD array.

---

## Examples

### Example 1

**Input**

```text
nums = [2,3,4]
queries = [0,2,2]
```

**Output**

```text
[1,2,2]
```

**Explanation**

```text
Pair GCDs:
gcd(2,3)=1
gcd(2,4)=2
gcd(3,4)=1

Sorted:
[1,1,2]
```

---

### Example 2

**Input**

```text
nums = [4,4,2,1]
queries = [5,3,1,0]
```

**Output**

```text
[4,2,1,1]
```

---

## Intuition

Instead of explicitly generating all `O(n²)` GCD pairs, count how many pairs have each possible GCD.

This can be done efficiently by:

- Counting frequencies of each value.
- Counting how many numbers are divisible by every divisor.
- Using inclusion-exclusion to compute the number of pairs whose GCD is exactly `d`.
- Building a prefix sum over these counts.
- Binary searching the prefix sums to answer each query.

---

## Approach

1. Count the frequency of every value.
2. For every divisor `d`, compute how many numbers are divisible by `d`.
3. Compute the number of pairs with GCD exactly `d` using inclusion-exclusion.
4. Build a prefix array where:

```text
pref[d] = number of pairs with GCD ≤ d
```

5. For each query:
   - Binary search the prefix array.
   - The first divisor whose prefix count exceeds the query index is the answer.

---

## Proof

Let `cnt[d]` denote the number of array elements divisible by `d`.

Then,

```text
Pairs divisible by d

= C(cnt[d],2)
```

This counts every pair whose GCD is a multiple of `d`.

Subtracting the counts of larger multiples gives:

```text
exact[d]

= C(cnt[d],2)
− Σ exact[multiple of d]
```

Thus `exact[d]` equals the number of pairs whose GCD is exactly `d`.

The prefix sums store the cumulative counts of sorted GCD values.

Binary searching this cumulative frequency directly identifies the GCD at any queried index.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(M log M + Q log M)` |
| **Space** | `O(M)` |

Where:

- `M = max(nums)`
- `Q = queries.size()`

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d)
                cnt[d] += freq[j];
        }

        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            long long pairs = cnt[d] * (cnt[d] - 1) / 2;

            for (int j = d + d; j <= mx; j += d)
                pairs -= exact[j];

            exact[d] = pairs;
        }

        vector<long long> pref(mx + 1, 0);
        for (int d = 1; d <= mx; d++)
            pref[d] = pref[d - 1] + exact[d];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {
            int lo = 1, hi = mx;

            while (lo < hi) {
                int mid = (lo + hi) / 2;

                if (pref[mid] > q)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            ans.push_back(lo);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Avoid generating all `O(n²)` GCD pairs.
- Count divisible elements for every divisor.
- Use inclusion-exclusion (Möbius-style counting) to compute exact GCD frequencies.
- Prefix sums transform frequencies into sorted positions.
- Binary search answers each query efficiently.