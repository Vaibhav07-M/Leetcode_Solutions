# 1665. Minimum Initial Energy to Finish Tasks

**Difficulty:** `Hard`  
**Tags:** `Array`, `Greedy`, `Sorting`

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

[LeetCode — 1665. Minimum Initial Energy to Finish Tasks](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/)

---

## Problem Summary

You are given an array `tasks` where `tasks[i] = [actual_i, minimum_i]`:
- `actual_i` is the energy spent to finish the i-th task.
- `minimum_i` is the minimum energy required to start the i-th task.

You may finish the tasks in any order. Return the minimum initial energy required to finish all tasks.

---

## Examples

### Example 1
**Input:** `tasks = [[1,2],[2,4],[4,8]]`  
**Output:** `8`

### Example 2
**Input:** `tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]`  
**Output:** `32`

### Example 3
**Input:** `tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]`  
**Output:** `27`

---

## Intuition

To minimize initial energy, do tasks in an order that reduces the largest "buffer" requirements first. Each task needs at least `minimum_i` energy before starting and consumes `actual_i`. Tasks with large `(minimum - actual)` impose stricter starting constraints and should be prioritized.

---

## Approach

Greedy ordering: sort tasks by `(actual - minimum)` ascending (equivalently by `(minimum - actual)` descending). Then simulate completing tasks in that order, increasing initial energy only when current energy is insufficient to meet a task's `minimum`.

Steps:
1. Sort `tasks` with comparator `a[0] - a[1] < b[0] - b[1]`.
2. Maintain `cur` = current energy (starts at 0) and `ans` = total initial energy added.
3. For each task `(a, m)`: if `cur < m`, increase `ans` by `m - cur` and set `cur = m`. Then `cur -= a`.
4. Return `ans`.

This yields the minimum initial energy.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` for sorting |
| **Space** | `O(1)` extra |

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](const auto& a, const auto& b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        int ans = 0, cur = 0;
        for (auto& task : tasks) {
            int a = task[0], m = task[1];
            if (cur < m) {
                ans += m - cur;
                cur = m;
            }
            cur -= a;
        }
        return ans;
    }
};
```

---

## Key Takeaways

- Greedy ordering by starting buffer `(minimum - actual)` minimizes extra initial energy.
- Simulate with a running energy counter and add only when needed.
- Sorting reduces the problem to a linear simulation.
