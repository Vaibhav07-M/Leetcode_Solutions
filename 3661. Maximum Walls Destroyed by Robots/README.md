# 3661. Maximum Walls Destroyed by Robots

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

[LeetCode - 3661. Maximum Walls Destroyed by Robots](https://leetcode.com/problems/maximum-walls-destroyed-by-robots/)

---

## Problem Summary

You are given robots on a number line, each with:
- a unique position
- a bullet distance
- a firing direction choice of left or right

You are also given wall positions.

Each robot can fire one bullet either to the left or to the right, up to its maximum distance. A bullet destroys every wall in its path within range, but another robot blocks the bullet immediately if it is hit first.

Return the maximum number of unique walls that can be destroyed.

---

## Examples

### Example 1
**Input:** `robots = [4], distance = [3], walls = [1,10]`  
**Output:** `1`

### Example 2
**Input:** `robots = [10,2], distance = [5,1], walls = [5,2,7]`  
**Output:** `3`

### Example 3
**Input:** `robots = [1,2], distance = [100,1], walls = [10]`  
**Output:** `0`

---

## Intuition

The robots must be considered in order of position, because a robot can only be blocked by the nearest robot in that direction.

For each robot:
- its actual left and right shooting limits are clipped by neighboring robots
- from that clipped interval, we count how many walls can be destroyed if the robot shoots left or right

This creates a small state transition per robot:
- previous robot shot left
- previous robot shot right

Memoization then avoids recomputing the same suffix decisions.

---

## Approach

1. Pair each robot position with its distance and sort the robots by position.
2. Sort the wall positions as well.
3. For every robot, compute its reachable interval after accounting for neighboring robots.
4. Use recursion with memoization:
   - `solve(i, prevDir)` returns the best answer from robot `i` onward
   - `prevDir` tracks whether the previous robot shot to the right, which affects the current left boundary
5. For robot `i`, try both choices:
   - shoot left and count walls in `[leftStart, robotPos]`
   - shoot right and count walls in `[robotPos, rightEnd]`
6. Return the maximum of those options.

The helper `countWallsInRange` uses binary search to count walls inside a closed interval efficiently.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n + m log m)` for sorting and binary search based counting |
| **Space** | `O(n)` for memoization and robot ranges |

---

## Code (C++)

```cpp
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> t;

    int countWalls(vector<int>& walls, int l, int r) {
        int left  = lower_bound(begin(walls), end(walls), l) - begin(walls);
        int right = upper_bound(begin(walls), end(walls), r) - begin(walls);

        return right - left;

    }

    int solve(vector<int>& walls, vector<P>& roboDist, vector<P>& range, int i, int prevDir) {

        if(i == roboDist.size())
            return 0;
        
        if(t[i][prevDir] != -1)
            return t[i][prevDir];

        int leftStart = range[i].first;

        if(prevDir == 1) { // prev robot fired bullet towards right
            leftStart = max(leftStart, range[i-1].second + 1);
        }

        int leftTake = countWalls(walls, leftStart, roboDist[i].first) 
                        + solve(walls, roboDist, range, i+1, 0);
                    
        int rightTake = countWalls(walls, roboDist[i].first, range[i].second) 
                        + solve(walls, roboDist, range, i+1, 1);

        
        return t[i][prevDir] = max(leftTake, rightTake);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<P> roboDist(n);
        for (int i = 0; i < n; i++) {
            roboDist[i] = {robots[i], distance[i]};
        }

        sort(begin(roboDist), end(roboDist));
        sort(begin(walls), end(walls));

        // Prepare range vector for each robot
        vector<P> range(n);

        for(int i = 0; i < n; i++) {
            int pos = roboDist[i].first;
            int d   = roboDist[i].second;

            int leftLimit  = (i == 0)   ? 1   : roboDist[i-1].first + 1;
            int rightLimit = (i == n-1) ? 1e9 : roboDist[i+1].first - 1;

            int L = max(pos - d, leftLimit);
            int R = min(pos + d, rightLimit);

            range[i] = {L, R};
        }

        t.assign(n + 1, vector<int>(2, -1));

        // prev = 0/1 (previous robot hit bullet to left/right)
        return solve(walls, roboDist, range, 0, 0);
    }
};
```

---

## Key Takeaways

- Sorting by position turns the line into a left-to-right dynamic process.
- Binary search lets you count walls in a range in logarithmic time.
- Memoization reduces repeated choices across robot states.
- Always clip a robot's shooting range by neighboring robots when obstacles block bullets.
