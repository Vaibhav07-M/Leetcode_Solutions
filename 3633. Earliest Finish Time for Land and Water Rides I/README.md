# 3633. Earliest Finish Time for Land and Water Rides I

**Difficulty:** `Easy`  
**Tags:** `Greedy`, `Simulation`

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

[LeetCode — 3633. Earliest Finish Time for Land and Water Rides I](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/)

---

## Problem Summary

You are given two sets of rides: land rides and water rides. Each ride has an earliest start time and a duration. A tourist must take exactly one land ride and one water ride, in either order. Rides may start at their opening time or any later time. If a ride is started at time `t`, it finishes at `t + duration`.

Return the earliest possible time at which the tourist can finish both rides.

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

Try both orders (land→water and water→land). For each order, pair a chosen land ride with a chosen water ride and compute the finish time considering possible waiting times. The earliest overall finish time across all valid pairs is the answer.

---

## Approach

1. For each land ride `i` and each water ride `j`, compute:
   - Finish time if land first: `max(landStartTime[i], 0) + landDuration[i]` → then start water at `max(waterStartTime[j], landFinish)` → finish at `start + waterDuration[j]`.
   - Finish time if water first: symmetric computation.
2. Track the minimum finish time across all pairs and both orders.
3. Return that minimum.

Brute force over pairs is acceptable since `n,m <= 100`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n*m)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int earliestFinishTime(vector<int>& landStart, vector<int>& landDur, vector<int>& waterStart, vector<int>& waterDur) {
        int ans = INT_MAX;
        for (int i = 0; i < (int)landStart.size(); ++i) {
            for (int j = 0; j < (int)waterStart.size(); ++j) {
                int landStartT = landStart[i];
                int landFinish = landStartT + landDur[i];
                int startWater = max(waterStart[j], landFinish);
                ans = min(ans, startWater + waterDur[j]);

                int waterStartT = waterStart[j];
                int waterFinish = waterStartT + waterDur[j];
                int startLand = max(landStart[i], waterFinish);
                ans = min(ans, startLand + landDur[i]);
            }
        }
        return ans;
    }
};
```

---

## Key Takeaways

- Try both ordering permutations when sequence can vary.
- Brute force is fine for small input sizes; optimize only if necessary.
