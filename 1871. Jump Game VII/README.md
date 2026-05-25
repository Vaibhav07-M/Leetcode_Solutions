# 1871. Jump Game VII

**Difficulty:** `Medium`  
**Tags:** `String`, `BFS`, `Prefix Sum`, `Sliding Window`

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

[LeetCode — 1871. Jump Game VII](https://leetcode.com/problems/jump-game-vii/)

---

## Problem Summary

You are given a 0-indexed binary string `s` and two integers `minJump` and `maxJump`. Initially you are at index `0` (which equals `'0'`). You can move from index `i` to index `j` if:

- `i + minJump <= j <= min(i + maxJump, s.length - 1)`, and
- `s[j] == '0'`.

Return `true` if you can reach the last index of `s`, otherwise return `false`.

---

## Examples

### Example 1
**Input:** `s = "011010", minJump = 2, maxJump = 3`  
**Output:** `true`

### Example 2
**Input:** `s = "01101110", minJump = 2, maxJump = 3`  
**Output:** `false`

---

## Intuition

We need to determine whether there exists a sequence of valid jumps from index `0` to the last index. A BFS from reachable positions works, but naively considering each target index in the interval `[i+minJump, i+maxJump]` leads to O(n * (maxJump - minJump)) behavior. We can optimize by maintaining a sliding window of prefix sums counting how many reachable positions fall into the valid range.

---

## Approach

1. Use a BFS (queue) over indices; `reachable[i]` indicates whether index `i` is reachable.
2. When processing index `i`, we only consider `j` in `[i+minJump, i+maxJump]` and mark `j` reachable if `s[j] == '0'` and the window shows at least one previously reachable index in range.
3. Maintain a prefix-sum or running `reachableCount` for the current sliding window so each index is considered O(1) amortized.
4. Return `reachable[n-1]`.

This yields O(n) time with O(n) space.

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
    bool canReach(string s, int minJ, int maxJ) {
        int n = s.size();
        vector<int> reachable(n, 0);
        reachable[0] = 1;
        deque<int> dq; // store indices of reachable positions
        dq.push_back(0);
        int left = 1, right = 0;
        int windowCount = 0;
        for (int i = 1; i < n; ++i) {
            // expand window to include positions that can reach i
            while (!dq.empty() && dq.front() < i - maxJ) dq.pop_front();
            // check if there exists a reachable index in [i - maxJ, i - minJ]
            if (!dq.empty() && i - dq.front() >= minJ && s[i] == '0') {
                reachable[i] = 1;
                dq.push_back(i);
            }
        }
        return reachable[n-1] == 1;
    }
};
```

---

## Key Takeaways

- Use BFS with a sliding-window/prefix-sum optimization to avoid quadratic behavior.
- Track reachable indices efficiently with a deque or prefix sums.
- This pattern applies to many constrained-jump problems on strings/arrays.
