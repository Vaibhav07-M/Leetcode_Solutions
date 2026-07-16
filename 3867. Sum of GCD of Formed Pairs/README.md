# 3867. Sum of GCD of Formed Pairs

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`, `Number Theory`, `GCD`, `Sorting`, `Two Pointers`

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

[LeetCode – 3867. Sum of GCD of Formed Pairs](https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/)

---

## Problem Summary

Given an integer array `nums`:

1. Construct an array `prefixGcd` where:
   - `mxi` is the maximum element among `nums[0...i]`.
   - `prefixGcd[i] = gcd(nums[i], mxi)`.
2. Sort `prefixGcd`.
3. Pair the smallest and largest elements, then the second smallest and second largest, and so on.
4. Compute the GCD of every formed pair.
5. Return the sum of all pair GCDs.

If the array length is odd, the middle element remains unpaired.

---

## Examples

### Example 1

**Input:**

```text
nums = [2,6,4]
```

**Output:**

```text
2
```

**Explanation:**

```text
prefixGcd = [2,6,2]
Sorted = [2,2,6]

Pair:
gcd(2,6)=2

Answer = 2
```

---

### Example 2

**Input:**

```text
nums = [3,6,2,8]
```

**Output:**

```text
5
```

**Explanation:**

```text
prefixGcd = [3,6,2,8]
Sorted = [2,3,6,8]

Pairs:
gcd(2,8)=2
gcd(3,6)=3

Answer = 5
```

---

## Intuition

The prefix GCD array depends on the maximum value seen so far.

Once constructed, the pairing strategy is fixed by the problem:

- Sort the values.
- Always pair the smallest remaining value with the largest remaining value.

A simple two-pointer traversal computes the required GCD for every pair.

---

## Approach

1. Traverse `nums` while maintaining the maximum element seen so far.
2. Build the `prefixGcd` array using `gcd(current, maximum)`.
3. Sort the `prefixGcd` array.
4. Use two pointers:
   - Left pointer starts from the beginning.
   - Right pointer starts from the end.
5. Add `gcd(prefixGcd[left], prefixGcd[right])` for every pair.
6. Return the accumulated sum.

---

## Proof

The algorithm correctly constructs the required `prefixGcd` array because each element is computed using the maximum value seen up to that position.

Sorting arranges the array exactly as required by the problem statement.

Using two pointers always forms:

- smallest with largest
- second smallest with second largest
- ...

which matches the required pairing rule.

Computing the GCD for every formed pair and summing them therefore produces the required answer.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n log n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;
        prefixGcd.reserve(n);

        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
            prefixGcd.push_back(gcd(x, mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int i = 0, j = n - 1;

        while (i < j) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Maintain the prefix maximum while traversing the array.
- Build the `prefixGcd` array using the running maximum.
- Sorting enables the required smallest-largest pairing.
- Two pointers efficiently process all pairs in linear time after sorting.
- Overall complexity is dominated by sorting: **O(n log n)**.