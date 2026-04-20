# 2078. Two Furthest Houses With Different Colors

**Difficulty:** `Easy`  
**Tags:** `Array`

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

[LeetCode - 2078. Two Furthest Houses With Different Colors](https://leetcode.com/problems/two-furthest-houses-with-different-colors/)

---

## Problem Summary

You are given an array `colors` where `colors[i]` is the color of house `i`.

Return the maximum distance `abs(i - j)` between two houses with different colors.

---

## Examples

### Example 1
**Input:** `colors = [1,1,1,6,1,1,1]`  
**Output:** `3`

### Example 2
**Input:** `colors = [1,8,3,8,3]`  
**Output:** `4`

### Example 3
**Input:** `colors = [0,1]`  
**Output:** `1`

---

## Intuition

The farthest valid pair must include one end of the array.

So only two checks are needed:
- farthest index from the left end (`0`) with a different color
- farthest index from the right end (`n - 1`) with a different color

The answer is the maximum of those two distances.

---

## Approach

1. Start from the right and find first `j` such that `colors[j] != colors[0]`; candidate distance is `j`.
2. Start from the left and find first `i` such that `colors[i] != colors[n - 1]`; candidate distance is `(n - 1) - i`.
3. Return the larger of both candidates.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        // Compare with first element
        for(int j = n - 1; j >= 0; j--) {
            if(colors[j] != colors[0]) {
                ans = max(ans, j);
                break;
            }
        }

        // Compare with last element
        for(int i = 0; i < n; i++) {
            if(colors[i] != colors[n - 1]) {
                ans = max(ans, (n - 1) - i);
                break;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Endpoints are enough to find the maximum possible distance.
- Two linear scans solve the problem with constant extra space.
- The first mismatch from each opposite end gives the farthest valid partner.