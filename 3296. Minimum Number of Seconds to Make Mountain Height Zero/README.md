# 3296. Minimum Number of Seconds to Make Mountain Height Zero

**Difficulty:** `Medium`  
**Tags:** `Binary Search`, `Math`

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

[LeetCode - 3296. Minimum Number of Seconds to Make Mountain Height Zero](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/)

---

## Problem Summary

You are given:
- `mountainHeight`: total height to reduce
- `workerTimes[i]`: base time for worker `i`

If worker `i` reduces height by `x`, required time is:
- `workerTimes[i] * (1 + 2 + ... + x)`

All workers work in parallel.

Return the minimum number of seconds needed so total reduced height is at least `mountainHeight`.

---

## Examples

### Example 1
**Input:** `mountainHeight = 4, workerTimes = [2,1,1]`  
**Output:** `3`

### Example 2
**Input:** `mountainHeight = 10, workerTimes = [3,2,2,4]`  
**Output:** `12`

### Example 3
**Input:** `mountainHeight = 5, workerTimes = [1]`  
**Output:** `15`

---

## Intuition

If we fix a time `T`, we can check whether workers can reduce at least `mountainHeight` within `T`.

For one worker with base time `t`, reducing by `x` requires:

`t * x * (x + 1) / 2 <= T`

So for each worker, we can compute the maximum possible `x` in time `T`, sum all workers' contributions, and test feasibility.

Feasibility is monotonic:
- If time `T` works, any larger time also works.

So we can binary search the minimum feasible `T`.

---

## Approach

1. Binary search answer `T` in range `[0, 1e18]`.
2. For each middle time `T`, run `can(T)`:
- For each worker time `t`, compute max units `x` solvable from the quadratic inequality.
- Add all `x` values.
- Return `true` if total reduced height reaches `mountainHeight`.
3. If feasible, move left to find smaller time; otherwise move right.
4. Return smallest feasible time.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log 1e18)` where `n = workerTimes.size()` |
| **Space** | `O(1)` extra space |

---

## Code (C++)

### Solution 1 - Binary Search + Quadratic Inversion (Submitted)

```cpp
class Solution {
public:
    bool can(long long T, int h, vector<int>& wt) {
        long long reduced = 0;

        for(long long t : wt) {
            long long val = (2*T)/t;
            long long x = (sqrt(1 + 4*val) - 1) / 2;

            reduced += x;
            if(reduced >= h) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long lo = 0, hi = 1e18;
        long long ans = hi;

        while(lo <= hi) {
            long long mid = (lo + hi) / 2;

            if(can(mid, mountainHeight, workerTimes)) {
                ans = mid;
                hi = mid - 1;
            } 
            else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Use binary search when checking time feasibility is monotonic.
- Convert arithmetic series time into a quadratic bound per worker.
- Summing each worker's max contribution gives a fast feasibility test.
