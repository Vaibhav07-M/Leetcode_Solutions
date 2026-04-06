# 874. Walking Robot Simulation

**Difficulty:** `Medium`  
**Tags:** `Simulation`

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

[LeetCode - 874. Walking Robot Simulation](https://leetcode.com/problems/walking-robot-simulation/)

---

## Problem Summary

A robot starts at `(0, 0)` facing north.
You are given:
- `commands`, where `-2` means turn left, `-1` means turn right, and `1..9` means move forward that many steps
- `obstacles`, a list of blocked grid coordinates

The robot moves one step at a time, stopping early if a move would land on an obstacle.
Return the maximum squared Euclidean distance from the origin reached at any point during the simulation.

---

## Examples

### Example 1
**Input:** `commands = [4,-1,3], obstacles = []`  
**Output:** `25`

### Example 2
**Input:** `commands = [4,-1,4,-2,4], obstacles = [[2,4]]`  
**Output:** `65`

### Example 3
**Input:** `commands = [6,-1,-1,6], obstacles = [[0,0]]`  
**Output:** `36`

---

## Intuition

The robot has only four possible directions, so we can represent direction as an index in a small cycle.

The main challenge is obstacle detection. Since the robot moves one step at a time, we need constant-time membership checks for obstacles. A hash-based set of coordinates is enough.

Each command is then handled directly:
- turn commands update direction
- move commands advance step-by-step until blocked

---

## Approach

1. Store all obstacles in a `set<pair<int,int>>` for quick lookup.
2. Track direction using an index over the four compass directions: north, east, south, west.
3. For each command:
   - `-1`: rotate right
   - `-2`: rotate left
   - positive value: move forward step by step
4. After every successful step, update the squared distance from the origin.
5. Return the maximum squared distance seen.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(c + s)` where `c` is commands and `s` is total movement steps executed |
| **Space** | `O(o)` for obstacle storage |

---

## Code (C++)

```cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // Store obstacles in set
        set<pair<int,int>> obs;
        for(auto &o : obstacles) {
            obs.insert({o[0], o[1]});
        }
        
        // Directions: N, E, S, W
        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };
        
        int d = 0; // start facing North
        int x = 0, y = 0;
        int maxDist = 0;
        
        for(int cmd : commands) {
            
            if(cmd == -1) {
                // turn right
                d = (d + 1) % 4;
            }
            else if(cmd == -2) {
                // turn left
                d = (d + 3) % 4;
            }
            else {
                // move step-by-step
                for(int i = 0; i < cmd; i++) {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;
                    
                    // obstacle check
                    if(obs.count({nx, ny})) break;
                    
                    x = nx;
                    y = ny;
                    
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};
```

---

## Key Takeaways

- A small fixed direction state makes turn simulation simple.
- Hash sets make obstacle checks fast enough for large inputs.
- Move one step at a time when obstacles can interrupt movement mid-command.
