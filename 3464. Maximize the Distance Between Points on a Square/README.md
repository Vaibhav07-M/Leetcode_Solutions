# 3464. Maximize the Distance Between Points on a Square

**Difficulty:** `Hard`  
**Tags:** `Array`, `Binary Search`, `Geometry`, `Sorting`

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

[LeetCode — 3464. Maximize the Distance Between Points on a Square](https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/)

---

## Problem Summary

You are given points on the boundary of a square of side length `side`.  
Pick exactly `k` points such that the minimum Manhattan distance among chosen points is as large as possible.

Return that maximum possible minimum distance.

---

## Examples

### Example 1
**Input:** `side = 2, points = [[0,2],[2,0],[2,2],[0,0]], k = 4`  
**Output:** `2`

### Example 2
**Input:** `side = 2, points = [[0,0],[1,2],[2,0],[2,2],[2,1]], k = 4`  
**Output:** `1`

### Example 3
**Input:** `side = 2, points = [[0,0],[0,1],[0,2],[1,2],[2,0],[2,2],[2,1]], k = 5`  
**Output:** `1`

---

## Intuition

A boundary point on a square can be mapped to a 1D position along the perimeter.
After this transformation, selecting points with pairwise Manhattan-distance constraints becomes a circular spacing problem.

We can binary search the answer `d` (minimum distance) and check if it is feasible to pick `k` points with perimeter positions at least `d` apart.

To handle circular wrap-around, duplicate the sorted perimeter positions by adding one full perimeter length and run checks on windows of length `n`.

---

## Approach

1. **Map each point to a perimeter coordinate** in `[0, 4*side)`:
   - bottom edge: `x`
   - right edge: `side + y`
   - top edge: `3*side - x`
   - left edge: `4*side - y`
2. Sort mapped positions.
3. Build a doubled array `doubled[i+n] = positions[i] + perimeter` for circular handling.
4. **Binary search** candidate minimum distance `mid`.
5. For each start index `i`, greedily pick next points using `lower_bound` for `last + mid`.
6. If `k` points are picked and the wrap-around gap also satisfies `mid`, feasibility is true.
7. Return the largest feasible `mid`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n + log(side) * n * k * log n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    typedef long long ll;

    ll get1D(int side, int x, int y) {
        if(y == 0) return x;
        if(x == side) return side + y;
        if(y == side) return 3LL * side - x;
        return 4LL * side - y;
    }

    bool check(vector<ll>& doubled, int n, int k, int side, int mid) {
        ll perimeter = 4LL * side;

        for(int i = 0; i < n; i++) {
            int count = 1;
            int idx = i;
            ll lastPos = doubled[idx];

            for(int j = 2; j <= k; j++) {
                ll target = lastPos + mid;
                auto it = lower_bound(begin(doubled) + idx + 1, begin(doubled) + i + n, target);

                if(it == begin(doubled) + i + n) break;

                idx = int(it - begin(doubled));
                lastPos = doubled[idx];
                count++;
            }

            if(count == k && (doubled[i] + perimeter - lastPos >= mid)) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        ll perimeter = 4LL * side;
        int n = points.size();

        vector<ll> positions(n);
        for(int i = 0; i < n; i++) {
            positions[i] = get1D(side, points[i][0], points[i][1]);
        }

        sort(begin(positions), end(positions));

        vector<ll> doubled(2 * n);
        for(int i = 0; i < n; i++) {
            doubled[i] = positions[i];
            doubled[i + n] = positions[i] + perimeter;
        }

        int l = 0, r = 2 * side;
        int result = 0;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(doubled, n, k, side, mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
```

---

## Key Takeaways

- Convert boundary geometry to a 1D perimeter index to simplify distance constraints.
- Binary search on answer + greedy feasibility is effective for max-min distance problems.
- Doubling the perimeter array is a clean way to handle circular wrap-around intervals.
