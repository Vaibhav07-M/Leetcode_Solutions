# 2091. Removing Minimum and Maximum From Array

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`

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

[LeetCode — 2091. Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/)

---

## Problem Summary

Given an array of distinct integers, you must remove both the minimum and maximum elements using deletions that can only occur from the front or the back of the array. Each deletion removes exactly one element from either end.  
The goal is to compute the minimum total number of deletions needed. Since only the positions of the minimum and maximum matter, the answer depends purely on their indices relative to the array boundaries.

---

## Examples

### Example 1
**Input:** `nums = [2,10,7,5,4,1,8,6]`  
**Output:** `5`  
**Explanation:**
- The minimum element in the array is nums[5], which is 1.
- The maximum element in the array is nums[1], which is 10.
- We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
- This results in 2 + 3 = 5 deletions, which is the minimum number possible.

### Example 2
**Input:** `nums = [0,-4,19,1,8,-2,-3,5]`  
**Output:** `3`  
**Explanation:**
- The minimum element in the array is nums[1], which is -4.
- The maximum element in the array is nums[2], which is 19.
- We can remove both the minimum and maximum by removing 3 elements from the front.
- This results in only 3 deletions, which is the minimum number possible.

### Example 3
**Input:** `nums = [101]`  
**Output:** `1`  
**Explanation:**
- There is only one element in the array, which makes it both the minimum and maximum element.
- We can remove it with 1 deletion.

---

## Intuition

Because deletions only happen from the ends, removing an element at index i costs either i+1 deletions (from the front) or n-i deletions (from the back). With two target elements at positions left < right, there are only three structurally distinct strategies: delete everything up to and including right from the front, delete everything down to and including left from the back, or peel left from the front and right from the back simultaneously.  
The key insight is that any optimal sequence of deletions falls into exactly one of these three patterns, since mixing deletions beyond what is needed to reach both targets is wasteful. Computing all three costs and taking the minimum is a direct greedy enumeration over a constant-size strategy space.

---

## Approach

1. Scan the array once, tracking the indices of the minimum and maximum elements using simple comparisons.
2. Normalize the two indices so that left is the smaller position and right is the larger position, which simplifies the cost formulas.
3. Compute the cost of removing both elements purely from the front: right + 1 deletions, since everything up to and including the rightmost target must be popped.
4. Compute the cost of removing both purely from the back: n - left deletions, since everything from the end down to the leftmost target must be popped.
5. Compute the mixed strategy: (left + 1) deletions from the front to reach the left target plus (n - right) deletions from the back to reach the right target.
6. Return the minimum of the three candidate costs using std::min over an initializer list.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — A single linear pass finds the min and max indices; the remaining work is constant-time arithmetic. |
| **Space** | `O(1)` — Only a handful of integer variables (indices and candidate costs) are stored regardless of input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minPos = 0;
        int maxPos = 0;

        // Find positions of minimum and maximum
        for (int i = 1; i < n; i++) {

            if (nums[i] < nums[minPos])
                minPos = i;

            if (nums[i] > nums[maxPos])
                maxPos = i;
        }

        // Make left = smaller position
        // and right = larger position
        int left = min(minPos, maxPos);
        int right = max(minPos, maxPos);

        // Case 1: Remove both from the front
        int front = right + 1;

        // Case 2: Remove both from the back
        int back = n - left;

        // Case 3: Remove one from front and one from back
        int both = (left + 1) + (n - right);

        return min({front, back, both});
    }
};
```

---

## Key Takeaways

- When operations are restricted to the ends of an array, the cost of reaching an element is determined solely by its distance from each boundary.
- Ordering the two target indices (left, right) collapses symmetric cases and makes the three strategy formulas clean and branch-free.
- Greedy enumeration over a small, exhaustive set of strategies (front-only, back-only, mixed) guarantees optimality without dynamic programming.
- std::min with an initializer list provides a concise way to take the minimum of multiple candidates in C++.
