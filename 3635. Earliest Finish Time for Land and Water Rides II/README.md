# 3635. Earliest Finish Time for Land and Water Rides II

**Difficulty:** `Medium`  
**Tags:** `Greedy`, `Simulation`, `Sorting`, `Binary Search` 

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

[LeetCode — 3635. Earliest Finish Time for Land and Water Rides II](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/)

---

## Problem Summary

Given two categories of rides — land and water — each ride has an earliest start time and a duration. A tourist must take exactly one ride from each category, in either order. A ride can start at its opening time or any later moment. If started at time `t`, it finishes at `t + duration`.

Return the earliest possible time when the tourist can finish both chosen rides.

Constraints: `1 <= n,m <= 5*10^4`, times and durations up to `1e5`.

---

## Examples

### Example 1
**Input:** `landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]`  
**Output:** `9`

### Example 2
**Input:** `landStartTime = [5], landDuration = [3], waterStartTime = [1], waterDuration = [10]`  
**Output:** `14`

---

## Intuition

We must consider both orders (land→water and water→land). For large `n,m` a brute-force O(n*m) is too slow. For a fixed finish time of the first ride `t`, the earliest possible finish of the second ride can be computed from preprocessed information about the other category: either start a ride already open at `t` (finish = `t + minDurOpen`) or wait for the next ride to open (finish = `min(start + dur)` among future rides). Precompute prefix minima and suffix minima after sorting by start times to answer each query in O(log m) or O(1) with two-pointer / binary search.

---

## Approach

1. Sort the water rides by `waterStart`. Build two arrays:
   - `prefMinDur[i]`: minimum `waterDuration` among rides with index ≤ i (i.e., those open at or before `waterStart[i]`).
   - `suffMinStartPlusDur[i]`: minimum `waterStart + waterDuration` among rides with index ≥ i.
2. For each land ride `i`, compute `landFinish = landStart[i] + landDur[i]`. Binary-search the last water index `idx` with `waterStart[idx] ≤ landFinish`.
   - If `idx >= 0`, earliest finish using an already-open water ride is `landFinish + prefMinDur[idx]`.
   - If `idx + 1 < m`, earliest finish by waiting for a future water ride is `suffMinStartPlusDur[idx+1]`.
   - The best finish when land→water is the min of the two (when available).
3. Symmetrically compute best finishes when water→land by preprocessing land rides the same way.
4. Answer is the minimum across both orderings.

This yields O((n+m) log(n+m)) dominated by sorting and binary searches.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((n+m) log(n+m))` — sorting + binary searches |
| **Space** | `O(n+m)` — for sorted arrays and prefix/suffix arrays |

---

## Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

int earliestFinish(const vector<int>& Astart, const vector<int>& Adur,
                   const vector<int>& Bstart, const vector<int>& Bdur) {
    int n = Astart.size(), m = Bstart.size();
    if (n==0 || m==0) return INT_MAX;

    // Build sorted indices for B by start
    vector<pair<int,int>> B;
    B.reserve(m);
    for (int i = 0; i < m; ++i) B.emplace_back(Bstart[i], Bdur[i]);
    sort(B.begin(), B.end());

    vector<int> prefMinDur(m), suffMinStartPlusDur(m);
    prefMinDur[0] = B[0].second;
    for (int i = 1; i < m; ++i) prefMinDur[i] = min(prefMinDur[i-1], B[i].second);

    suffMinStartPlusDur[m-1] = B[m-1].first + B[m-1].second;
    for (int i = m-2; i >= 0; --i) suffMinStartPlusDur[i] = min(suffMinStartPlusDur[i+1], B[i].first + B[i].second);

    int best = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int finishA = Astart[i] + Adur[i];
        // find last index in B with Bstart <= finishA
        int idx = upper_bound(B.begin(), B.end(), make_pair(finishA, INT_MAX)) - B.begin() - 1;
        if (idx >= 0) {
            best = min(best, finishA + prefMinDur[idx]);
        }
        if (idx + 1 < m) {
            best = min(best, suffMinStartPlusDur[idx+1]);
        }
    }

    return best;
}

class Solution {
public:
    int earliestFinishTime(vector<int>& landStart, vector<int>& landDur, vector<int>& waterStart, vector<int>& waterDur) {
        int ans1 = earliestFinish(landStart, landDur, waterStart, waterDur);
        int ans2 = earliestFinish(waterStart, waterDur, landStart, landDur);
        return min(ans1, ans2);
    }
};
```

---

## Key Takeaways

- Preprocessing with sorting + prefix/suffix minima can turn pairwise optimization into O(n log m) queries.  
- Consider both orderings when sequence matters.  
- Pay attention to edge cases: no open ride at finish time or all rides open after finish time.
