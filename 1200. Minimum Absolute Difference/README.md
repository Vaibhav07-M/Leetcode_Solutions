# 1200. Minimum Absolute Difference

**Difficulty:** `Easy`  
**Tags:** `Array`, `Sorting`

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

[LeetCode — 1200. Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/)

---

## Problem Summary

Given an array of **distinct integers** `arr`, find all pairs of elements with the **minimum absolute difference** of any two elements.

Return a list of pairs in **ascending order**, where each pair `[a, b]` follows:
- `a, b` are from `arr`
- `a < b`
- `b - a` equals the minimum absolute difference

---

## Examples

### Example 1
**Input:** `arr = [4,2,1,3]`  
**Output:** `[[1,2],[2,3],[3,4]]`  
**Explanation:**
- After sorting: [1,2,3,4]
- Minimum absolute difference is 1
- All pairs with difference 1: (1,2), (2,3), (3,4)

### Example 2
**Input:** `arr = [1,3,6,10,15]`  
**Output:** `[[1,3]]`  
**Explanation:**
- After sorting: [1,3,6,10,15]
- Consecutive differences: 2, 3, 4, 5
- Minimum difference is 2
- Only pair with difference 2: (1,3)

### Example 3
**Input:** `arr = [3,8,-10,23,19,-4,-14,27]`  
**Output:** `[[-14,-10],[19,23],[23,27]]`  
**Explanation:**
- After sorting: [-14,-10,-4,3,8,19,23,27]
- Consecutive differences: 4, 6, 7, 5, 11, 4, 4
- Minimum difference is 4
- Pairs with difference 4: (-14,-10), (19,23), (23,27)

---

## Intuition

To find the minimum absolute difference, we need to consider all pairs. However, **after sorting**, the minimum difference will always be between **consecutive elements**.

**Why?** Because if elements are sorted as `a < b < c`, then:
- `|c - a| = c - a` (since all distinct)
- `|b - a| = b - a` and `|c - b| = c - b`
- `c - a = (c - b) + (b - a) ≥ max(c - b, b - a)`

So we only need to check consecutive pairs after sorting.

**Strategy:**
1. Sort the array
2. Find minimum difference by checking consecutive elements
3. Collect all consecutive pairs that have this minimum difference

---

## Approach

### Two-Pass Strategy:
1. **Sort the array** in ascending order
2. **First pass:** Find the minimum absolute difference
   - Check all consecutive pairs: `arr[i+1] - arr[i]`
   - Track the minimum difference
3. **Second pass:** Collect all pairs with minimum difference
   - Check consecutive pairs again
   - If difference equals minimum, add `[arr[i], arr[i+1]]` to result

### Algorithm:
```
1. Sort arr in ascending order
2. Initialize minDiff = INT_MAX
3. For i from 0 to n-2:
   - diff = arr[i+1] - arr[i]
   - minDiff = min(minDiff, diff)
4. Initialize result = []
5. For i from 0 to n-2:
   - if arr[i+1] - arr[i] == minDiff:
     - result.push([arr[i], arr[i+1]])
6. Return result
```

### Why This Works:
- Sorting ensures `a < b` automatically in pairs
- Consecutive elements have the smallest possible differences
- All elements are distinct, so no duplicates in output

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — dominated by sorting, two O(n) passes afterward |
| **Space** | `O(1)` or `O(log n)` — excluding output array, depending on sort |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Sort the array
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int minDiff = INT_MAX;
        
        // First pass: find minimum difference
        for (int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            minDiff = min(minDiff, diff);
        }
        
        // Second pass: collect all pairs with minimum difference
        vector<vector<int>> result;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == minDiff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        
        return result;
    }
};
```

### Alternative Single-Pass (with revisit):

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> result;
        int minDiff = INT_MAX;
        
        // Find min difference and collect pairs in one pass
        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            
            if (diff < minDiff) {
                // Found new minimum, reset result
                minDiff = diff;
                result.clear();
                result.push_back({arr[i], arr[i + 1]});
            } else if (diff == minDiff) {
                // Same minimum, add to result
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        
        return result;
    }
};
```

### Optimized Clean Version:

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        vector<vector<int>> result;
        
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            
            if (diff < minDiff) {
                minDiff = diff;
                result = {{arr[i - 1], arr[i]}};
            } else if (diff == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return result;
    }
};
```

---

## Key Takeaways

1. **Sorting simplifies the problem** — only need to check consecutive elements
2. **Minimum difference** is always between consecutive elements in sorted array
3. **Two-pass approach** — first find minimum, then collect pairs (clear but not optimal)
4. **Single-pass optimization** — find minimum and collect pairs simultaneously
5. **Distinct elements** guarantee no duplicate pairs in output
6. **Ascending order** is automatically satisfied after sorting
7. **Edge case:** With n=2, only one pair possible
8. **Pattern:** This "consecutive elements" pattern applies to many sorted array problems

---
