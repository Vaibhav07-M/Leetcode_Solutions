# 2069. Walking Robot Simulation II

**Difficulty:** `Medium`  
**Tags:** `Design`, `Simulation`, `Math`

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

[LeetCode - 2069. Walking Robot Simulation II](https://leetcode.com/problems/walking-robot-simulation-ii/)

---

## Problem Summary

Design a `Robot` class that moves on a `width x height` boundary grid.

- Initial position is `(0, 0)` facing `East`.
- `step(num)` moves the robot `num` steps.
- If the next forward cell is out of bounds, robot turns 90 degrees counterclockwise and retries the step.
- `getPos()` returns current `[x, y]`.
- `getDir()` returns current facing direction.

---

## Examples

### Example 1
**Input:**
`["Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"]`  
`[[6, 3], [2], [2], [], [], [2], [1], [4], [], []]`

**Output:**
`[null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]`

---

## Intuition

The robot only walks on the perimeter of the rectangle.
So after reaching the boundary path, movement repeats in a cycle of perimeter length:

`cycle = 2 * (width + height - 2)`

Instead of simulating every step globally, we can reduce by modulo:
- `num %= cycle`

Then simulate only the reduced steps with directional edge-limited moves.

A special case appears when `num % cycle == 0` at origin: by definition of this problem's movement state, direction becomes `South`.

---

## Approach

1. Store grid dimensions and current state `(x, y, dir)`.
2. Precompute `cycle = 2 * (w + h - 2)`.
3. In `step(num)`:
   - reduce steps: `num %= cycle`
   - handle special case `num == 0 && at origin` -> set direction to `South`
   - otherwise, while `num > 0`:
     - move as far as possible on current edge using `min(num, distance_to_edge)`
     - subtract moved steps
     - if steps remain, turn counterclockwise
4. `getPos()` returns current coordinates.
5. `getDir()` maps direction index to string.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(1)` amortized per `step` due to perimeter modulo reduction |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Robot {
public:
    int w, h;
    int x, y, dir; // 0=E, 1=N, 2=W, 3=S
    int cycle;
    
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
        cycle = 2 * (w + h - 2);
    }
    
    void step(int num) {
        num %= cycle;
        
        // special case
        if(num == 0 && x == 0 && y == 0) {
            dir = 3; // South
            return;
        }
        
        while(num > 0) {
            int move = 0;
            
            if(dir == 0) { // East
                move = min(num, w - 1 - x);
                x += move;
            }
            else if(dir == 1) { // North
                move = min(num, h - 1 - y);
                y += move;
            }
            else if(dir == 2) { // West
                move = min(num, x);
                x -= move;
            }
            else { // South
                move = min(num, y);
                y -= move;
            }
            
            num -= move;
            
            if(num > 0) {
                dir = (dir + 1) % 4; // turn CCW
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(dir == 0) return "East";
        if(dir == 1) return "North";
        if(dir == 2) return "West";
        return "South";
    }
};
```

---

## Key Takeaways

- Perimeter cycle reduction is the key optimization.
- Grid-walk problems with boundaries often become cycle problems.
- Be careful with state conventions when `num % cycle == 0`.
