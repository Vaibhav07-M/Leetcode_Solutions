# 2515. Shortest Distance to Target String in a Circular Array

**Difficulty:** `Easy`  
**Tags:** `Array`, `String`

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

[LeetCode - 2515. Shortest Distance to Target String in a Circular Array](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/)

---

## Problem Summary

You are given a circular array `words`, a string `target`, and a starting index `startIndex`.

From `startIndex`, you may move left or right by one position at a time, wrapping around the array.
Return the minimum number of steps needed to reach any index whose value equals `target`.
If `target` does not appear in `words`, return `-1`.

---

## Examples

### Example 1
**Input:** `words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1`  
**Output:** `1`

**Explanation:**
- The nearest `"hello"` is at index `0` or `4`.
- From index `1`, both are distance `1` in the circular array.

### Example 2
**Input:** `words = ["a","b","leetcode"], target = "leetcode", startIndex = 0`  
**Output:** `1`

### Example 3
**Input:** `words = ["i","eat","leetcode"], target = "ate", startIndex = 0`  
**Output:** `-1`

---

## Intuition

Because the array is circular, the best answer may be to move either left or right.
The distance from `startIndex` to any index `i` is the minimum of:
- direct distance `abs(i - startIndex)`
- wrapped distance `n - abs(i - startIndex)`

So we just scan every position and keep the smallest valid circular distance.

---

## Approach

1. Initialize `ans = INT_MAX`.
2. For every index `i` in `words`:
   - if `words[i] == target`, compute `d = abs(i - startIndex)`
   - update `ans = min(ans, min(d, n - d))`
3. If no match is found, return `-1`.
4. Otherwise, return `ans`.

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
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int d = abs(i - startIndex);
                ans = min(ans, min(d, n - d));
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
```

---

## Key Takeaways

- Circular distance is always the minimum of forward and backward travel.
- A single pass is enough when the array size is small.
- The logic stays simple by comparing every target occurrence directly.