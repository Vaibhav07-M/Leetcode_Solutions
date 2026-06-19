# 1732. Find the Highest Altitude

**Difficulty:** `Easy`  
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

[LeetCode — 1732. Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)

---

## Problem Summary

A biker starts a road trip at altitude `0`.

You are given an array `gain` where:

```cpp
gain[i]
```

represents the net change in altitude between points `i` and `i + 1`.

Return the **highest altitude** reached during the trip.

---

## Examples

### Example 1
**Input:** `gain = [-5,1,5,0,-7]`  
**Output:** `1`

**Explanation:**

Altitudes:

```text
0 → -5 → -4 → 1 → 1 → -6
```

Highest altitude = `1`

### Example 2
**Input:** `gain = [-4,-3,-2,-1,4,3,2]`  
**Output:** `0`

**Explanation:**

Altitudes:

```text
0 → -4 → -7 → -9 → -10 → -6 → -3 → -1
```

The biker never goes above the starting altitude.

Highest altitude = `0`

---

## Intuition

The altitude at any point is simply the cumulative sum of all gains seen so far.

As we traverse the array:

- Keep track of the current altitude.
- Update the highest altitude whenever the current altitude becomes larger.

Since the biker starts at altitude `0`, the answer should initially be `0`.

---

## Approach

1. Initialize:
   - `curr = 0` to represent the current altitude.
   - `ans = 0` since the starting altitude is also a valid point.
2. Traverse the `gain` array.
3. For each value:
   - Add it to `curr`.
   - Update `ans` with the maximum of `ans` and `curr`.
4. Return `ans`.

This effectively computes the maximum prefix sum of the gain array.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int curr = 0;
        int ans = 0;

        for(int x : gain) {
            curr += x;
            ans = max(ans, curr);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The altitude at each point is a running cumulative sum.
- The problem reduces to finding the maximum prefix sum.
- The starting altitude `0` must be considered.
- A single traversal is sufficient.
- The solution runs in `O(n)` time with `O(1)` extra space.