# 1411. Number of Ways to Paint N × 3 Grid

**Difficulty:** `Hard`  
**Tags:** `Dynamic Programming`, `Math`, `Combinatorics`

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

[LeetCode — 1411. Number of Ways to Paint N × 3 Grid](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/)

---

## Problem Summary

You have a grid of size `n x 3` and you want to paint each cell with exactly one of three colors: **Red**, **Yellow**, or **Green**.

**Constraint:** No two adjacent cells (sharing vertical or horizontal sides) can have the same color.

Given `n` (the number of rows), return the number of ways you can paint this grid. Since the answer may be large, return it modulo `10^9 + 7`.

---

## Examples

### Example 1
**Input:** `n = 1`  
**Output:** `12`  
**Explanation:**
- For a 1x3 grid, there are 12 possible valid color combinations
- Valid patterns include: RGB, RGR, RBR, RBG, GRG, GRB, etc.

### Example 2
**Input:** `n = 5000`  
**Output:** `30228214`  
**Explanation:**
- For a large grid with 5000 rows, the number of valid ways is calculated using dynamic programming

---

## Intuition

The key insight is recognizing that each row can be painted in specific patterns based on the constraint that no two adjacent cells can have the same color. 

For a single row (1x3), we can categorize valid patterns into two types:
1. **Two-Color Patterns** (ABA): Uses 2 colors, like RGR, GRG, BRB, etc. → **6 ways**
2. **Three-Color Patterns** (ABC): Uses 3 different colors, like RGB, RBG, GRB, etc. → **6 ways**

For subsequent rows, we need to ensure vertical adjacency constraint is satisfied. The number of valid ways for row `i` depends on the pattern of row `i-1`:

- A two-color row can transition to:
  - **3 two-color rows** (different patterns)
  - **2 three-color rows**

- A three-color row can transition to:
  - **2 two-color rows**
  - **2 three-color rows**

This forms a DP recurrence relation that we can solve iteratively.

---

## Approach

1. **Initialize Base Case**:
   - For the first row: `twoColorWays = 6` and `threeColorWays = 6`
   - Total ways for first row = 12

2. **Dynamic Programming Transition**:
   - For each subsequent row from 2 to n:
     - `nextTwoColorWays = (3 * twoColorWays + 2 * threeColorWays) % MOD`
     - `nextThreeColorWays = (2 * twoColorWays + 2 * threeColorWays) % MOD`
   - Update the values for the next iteration

3. **Calculate Result**:
   - After processing all n rows, return `(twoColorWays + threeColorWays) % MOD`

4. **Modulo Operation**:
   - Apply modulo `10^9 + 7` at each step to prevent overflow

---

## Complexity

- **Time Complexity**: `O(n)` where n is the number of rows.  
  We iterate through each row once, performing constant time operations.

- **Space Complexity**: `O(1)` - constant space.  
  We only use a fixed number of variables regardless of input size.

---

## Code (C++)

```cpp
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long twoColorWays = 6;
        long long threeColorWays = 6;

        for (int row = 2; row <= n; row++) {
            long long nextTwoColorWays = (3 * twoColorWays + 2 * threeColorWays) % MOD;
            long long nextThreeColorWays = (2 * twoColorWays + 2 * threeColorWays) % MOD;
            
            twoColorWays = nextTwoColorWays;
            threeColorWays = nextThreeColorWays;
        }

        return (twoColorWays + threeColorWays) % MOD;
    }
};
```

---

## Key Takeaways

- **Pattern Recognition**: Breaking down the problem into two-color and three-color patterns simplifies the state space.
- **State Transition DP**: Understanding how current row patterns can transition to next row patterns is crucial.
- **Space Optimization**: We only need to track the previous row's state, reducing space from O(n) to O(1).
- **Modular Arithmetic**: Applying modulo at each step prevents integer overflow for large inputs.
- **Combinatorial DP**: This problem demonstrates how combinatorics and dynamic programming work together in counting problems.
- **Mathematical Insight**: The transition formula comes from carefully analyzing which patterns can follow each other while respecting adjacency constraints.
