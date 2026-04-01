# 2751. Robot Collisions

**Difficulty:** `Hard`  
**Tags:** `Array`, `Stack`, `Sorting`, `Simulation`

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

[LeetCode - 2751. Robot Collisions](https://leetcode.com/problems/robot-collisions/)

---

## Problem Summary

You are given three inputs for `n` robots:
- `positions[i]`: unique position of robot `i`
- `healths[i]`: current health of robot `i`
- `directions[i]`: movement direction (`'L'` or `'R'`)

All robots move simultaneously at the same speed.
A collision happens when two robots reach the same position:
- Lower health robot is removed.
- Higher health robot survives and loses 1 health.
- If equal health, both are removed.

Return healths of surviving robots in the original input order.

---

## Examples

### Example 1
**Input:** `positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"`  
**Output:** `[2,17,9,15,10]`

### Example 2
**Input:** `positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"`  
**Output:** `[14]`

### Example 3
**Input:** `positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"`  
**Output:** `[]`

---

## Intuition

Robots only collide when a right-moving robot is to the left of a left-moving robot.
So if we process robots from left to right (by position):
- `'R'` robots can be collision candidates for future `'L'` robots.
- A `'L'` robot may collide with the most recent unmatched `'R'` robot first.

This is exactly a stack pattern:
- Push indices of right-moving robots.
- When a left-moving robot appears, repeatedly resolve collisions with stack top until no collision remains or the left robot is destroyed.

---

## Approach

1. Build index array `idx = [0..n-1]` and sort it by `positions[idx[i]]`.
2. Maintain a stack of indices for alive right-moving robots encountered so far.
3. Traverse robots in sorted-position order:
   - If direction is `'R'`, push index into stack.
   - If direction is `'L'`, collide with stack top while stack is non-empty and current left robot is alive:
     - If right robot health > left robot health:
       - right health--, left dies.
     - If right robot health < left robot health:
       - left health--, right dies and pop stack.
     - If equal:
       - both die, pop stack, stop this left robot.
4. After processing all collisions, collect robots with `health > 0` in original input order.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` due to sorting indices |
| **Space** | `O(n)` for index array and stack |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> stk;

        for(int i : idx) {
            if(directions[i] == 'R') {
                stk.push_back(i);
                continue;
            }

            while(!stk.empty() && healths[i] > 0) {
                int j = stk.back();

                if(healths[j] > healths[i]) {
                    healths[j]--;
                    healths[i] = 0;
                } 
                else if(healths[j] < healths[i]) {
                    healths[i]--;
                    healths[j] = 0;
                    stk.pop_back();
                } 
                else {
                    healths[i] = healths[j] = 0;
                    stk.pop_back();
                    break;
                }
            }
        }

        vector<int> ans;
        for(int h : healths) {
            if(h > 0) {
                ans.push_back(h);
            }
        }
        return ans;
    }
};
```

---

## Key Takeaways

- Sort by spatial order before simulating collisions on a line.
- Use a stack to track unresolved right-moving robots.
- Each robot is pushed/popped at most once, keeping collision simulation linear after sorting.
- Return results in original index order by updating `healths` in place.
