# 1306. Jump Game III

**Difficulty:** `Medium`  
**Tags:** `Array`, `BFS`, `DFS`

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

[LeetCode — 1306. Jump Game III](https://leetcode.com/problems/jump-game-iii/)

---

## Problem Summary

Given a non-negative integer array `arr` and a starting index `start`, you can jump from index `i` to `i + arr[i]` or `i - arr[i]`. Determine whether you can reach any index with value `0`. You cannot jump outside the array bounds.

---

## Examples

### Example 1
**Input:** `arr = [4,2,3,0,3,1,2], start = 5`  
**Output:** `true`

### Example 2
**Input:** `arr = [4,2,3,0,3,1,2], start = 0`  
**Output:** `true`

### Example 3
**Input:** `arr = [3,0,2,1,2], start = 2`  
**Output:** `false`

---

## Intuition

This is a reachability problem on a small implicit graph where each index connects to at most two neighbors. BFS (or DFS) can explore reachable indices while marking visited nodes to avoid cycles.

---

## Approach

Use BFS starting from `start`:
1. Use a queue and a `visited` array.
2. Push `start`. While queue not empty:
   - Pop `i`. If `arr[i] == 0`, return true.
   - For each neighbor `j` in `{i + arr[i], i - arr[i]}`: if `0 <= j < n` and not visited, mark visited and push.
3. If BFS finishes without finding `0`, return false.

This runs in `O(n)` time and `O(n)` space.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<char> vis(n, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (arr[i] == 0) return true;
            int forward = i + arr[i];
            int backward = i - arr[i];
            if (forward < n && !vis[forward]) {
                vis[forward] = 1;
                q.push(forward);
            }
            if (backward >= 0 && !vis[backward]) {
                vis[backward] = 1;
                q.push(backward);
            }
        }
        return false;
    }
};
```

---

## Key Takeaways

- Model jumps as edges in a graph and use BFS/DFS for reachability.
- Mark visited indices to avoid infinite loops.
- Both BFS and DFS are acceptable; BFS may find the nearest zero sooner.
