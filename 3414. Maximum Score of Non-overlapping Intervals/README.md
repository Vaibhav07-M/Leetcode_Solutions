# 3414. Maximum Score of Non-overlapping Intervals

**Difficulty:** `Hard`  
**Tags:** `Array`, `Binary Search`, `Dynamic Programming`, `Sorting`

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

[LeetCode — 3414. Maximum Score of Non-overlapping Intervals](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/)

---

## Problem Summary

The problem involves selecting up to 4 non-overlapping intervals from a given set to maximize the total weight. The solution uses dynamic programming to efficiently compute the maximum score and the corresponding interval indices, ensuring the output is lexicographically smallest among optimal solutions.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to use a recursive dynamic programming approach where the state depends on the current interval index and the number of remaining slots. By sorting the intervals by their start time, we can efficiently determine the next valid interval (non-overlapping) for each step. The algorithm explores two options: skipping the current interval or taking it, updating the maximum score and the list of chosen indices accordingly.

---

## Approach

1. Sort the intervals by their start time to facilitate the search for non-overlapping intervals.
2. For each interval, use a binary search to find the index of the next interval that does not overlap with the current one.
3. Implement a recursive function `solve` that takes the current interval index and the number of remaining slots as parameters.
4. In the recursive function, compare the score of skipping the current interval with the score of taking it (adding its weight to the score of the next non-overlapping interval).
5. Store the results in a 2D table `t` to avoid redundant calculations (memoization).
6. Return the list of indices corresponding to the maximum score found.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * k * log n)` — The time complexity is dominated by the recursive calls and the binary search for the next interval. There are approximately n * k states to compute, and each state requires a binary search of O(log n) to find the next index, resulting in a total complexity of O(n * k * log n). |
| **Space** | `O(n * k)` — The space complexity is determined by the memoization table `t`, which stores the maximum score and indices for each combination of interval index and remaining slots. This results in a space requirement of O(n * k). |

---

## Code (C++)

```cpp
class Solution {
public:
    int n;
    vector<int> nextIdx;

    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    vector<vector<Node>> t;

    int findNext(vector<vector<int>>& intervals, int r) {
        int lo = 0, hi = n - 1;
        int result = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (intervals[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return result;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n)
            return Node();

        if (t[i][k].score != -1)
            return t[i][k];

        int weight = intervals[i][2];
        int idx    = intervals[i][3];
        int j      = nextIdx[i];

        //skip interval i
        Node skip = solve(intervals, i + 1, k);

        //take interval i
        Node temp = solve(intervals, j, k - 1);
        Node take;
        take.score = temp.score + weight;
        take.idxs  = temp.idxs;
        take.idxs.push_back(idx);
        sort(begin(take.idxs), end(take.idxs));

        Node result;
        if (skip.score > take.score) {
            result = skip;
        } else if (skip.score < take.score) {
            result = take;
        } else {
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return t[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            int r = intervals[i][1];
            nextIdx[i] = findNext(intervals, r);
        }

        const int K = 4;
        t.assign(n + 1, vector<Node>(K + 1));

        return solve(intervals, 0, K).idxs;
    }
};
```

---

## Key Takeaways

- The solution effectively combines binary search and dynamic programming to solve the interval selection problem.
- Sorting the intervals by start time is crucial for efficiently identifying non-overlapping intervals.
- The use of a 2D memoization table significantly reduces the time complexity by avoiding repeated calculations.
