# 799. Champagne Tower

**Difficulty:** `Medium`  
**Tags:** `Dynamic Programming`, `Simulation`, `Math`

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

[LeetCode — 799. Champagne Tower](https://leetcode.com/problems/champagne-tower/)

---

## Problem Summary

We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row. Each glass holds one cup of champagne.

When champagne is poured into the first glass at the top:
- When the topmost glass is full, any excess liquid falls equally to the glass immediately to the left and right of it
- When those glasses become full, any excess champagne falls equally to the left and right of those glasses, and so on
- A glass at the bottom row has its excess champagne fall on the floor

Given:
- `poured`: The amount of champagne poured (in cups)
- `query_row`: The row index (0-indexed)
- `query_glass`: The glass index within that row (0-indexed)

Return how full the `j`th glass in the `i`th row is.

---

## Examples

### Example 1
**Input:** `poured = 1, query_row = 1, query_glass = 1`  
**Output:** `0.00000`  
**Explanation:**
- We poured 1 cup of champagne to the top glass (0, 0)
- There is no excess liquid, so all glasses below remain empty

### Example 2
**Input:** `poured = 2, query_row = 1, query_glass = 1`  
**Output:** `0.50000`  
**Explanation:**
- We poured 2 cups of champagne to the top glass (0, 0)
- There is 1 cup of excess liquid
- Glass (1, 0) and glass (1, 1) share the excess equally
- Each gets half cup (0.5)

### Example 3
**Input:** `poured = 100000009, query_row = 33, query_glass = 17`  
**Output:** `1.00000`  
**Explanation:**
- With such a large amount poured, glass (33, 17) is completely full

---

## Intuition

This is a **simulation problem** where we need to track how champagne flows through the pyramid.

**Key observations:**
1. Each glass can hold at most 1 cup
2. When a glass has more than 1 cup, the excess flows equally to two glasses below
3. Each glass at position (i, j) overflows to (i+1, j) and (i+1, j+1)
4. We only need to simulate up to `query_row` since we don't care about rows below

**Visual representation:**
```
Row 0:        [0,0]
Row 1:      [1,0] [1,1]
Row 2:    [2,0] [2,1] [2,2]
Row 3:  [3,0] [3,1] [3,2] [3,3]
```

Each glass (i, j) receives overflow from:
- Glass (i-1, j-1) if it exists (right overflow from left parent)
- Glass (i-1, j) if it exists (left overflow from right parent)

---

## Approach

### Approach: Dynamic Programming with Simulation

1. **Initialize DP table:**
   - Create a 2D array `dp[query_row+2][query_row+2]` to store champagne amount in each glass
   - Set `dp[0][0] = poured` (all champagne starts at the top)

2. **Simulate overflow row by row:**
   - For each glass (i, j) from top to bottom:
     - If `dp[i][j] > 1.0`:
       - Calculate excess: `excess = dp[i][j] - 1.0`
       - Set current glass to full: `dp[i][j] = 1.0`
       - Distribute excess equally to two glasses below:
         - `dp[i+1][j] += excess / 2.0`
         - `dp[i+1][j+1] += excess / 2.0`

3. **Return result:**
   - After simulation, return `min(1.0, dp[query_row][query_glass])`
   - The min ensures we return at most 1.0 for a full glass

**Why this works:**
- We process glasses level by level, ensuring all overflow from upper levels is accounted for
- Each glass naturally accumulates champagne from its parents
- We cap each glass at 1.0 and distribute excess

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(query_row²)` |
| **Space** | `O(query_row²)` |

- **Time:** We process all glasses up to row `query_row`. Row i has (i+1) glasses, so total is 1+2+3+...+(query_row+1) = O(query_row²)
- **Space:** 2D array of size (query_row+2) × (query_row+2)

Since `query_row < 100`, the complexity is O(100²) = O(10,000) which is very fast.

---

## Code (C++)

### Solution 1: Dynamic Programming Simulation

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0.0));
        dp[0][0] = poured;

        for(int i = 0; i <= query_row; i++) {
            for(int j = 0; j <= i; j++) {
                if(dp[i][j] > 1.0) {
                    double excess = dp[i][j] - 1.0;
                    dp[i][j] = 1.0;
                    dp[i + 1][j] += excess / 2.0;
                    dp[i + 1][j + 1] += excess / 2.0;
                }
            }
        }

        return dp[query_row][query_glass];
    }
};
```

---

### Solution 2: Space Optimized with Two Rows

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> curr(1, poured);
        
        for(int row = 0; row < query_row; row++) {
            vector<double> next(row + 2, 0.0);
            
            for(int col = 0; col <= row; col++) {
                if(curr[col] > 1.0) {
                    double excess = (curr[col] - 1.0) / 2.0;
                    next[col] += excess;
                    next[col + 1] += excess;
                }
            }
            
            curr = next;
        }
        
        return min(1.0, curr[query_glass]);
    }
};
```

---

### Solution 3: In-place Overflow Distribution

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(102, vector<double>(102, 0.0));
        tower[0][0] = poured;

        for(int r = 0; r <= query_row; r++) {
            for(int c = 0; c <= r; c++) {
                double overflow = (tower[r][c] - 1.0) / 2.0;
                if(overflow > 0) {
                    tower[r + 1][c] += overflow;
                    tower[r + 1][c + 1] += overflow;
                }
            }
        }

        return min(1.0, tower[query_row][query_glass]);
    }
};
```

---

### Solution 4: Compact Version

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2));
        dp[0][0] = poured;
        for(int i = 0; i <= query_row; i++)
            for(int j = 0; j <= i; j++)
                if(dp[i][j] > 1) {
                    double ex = (dp[i][j] - 1) / 2.0;
                    dp[i+1][j] += ex; dp[i+1][j+1] += ex;
                }
        return min(1.0, dp[query_row][query_glass]);
    }
};
```

---

## Key Takeaways

- **Simulation with DP:** Track the state of each glass as champagne flows through the pyramid
- **Overflow mechanics:** Each glass distributes excess equally to two children (left and right)
- **Level-by-level processing:** Process row by row to ensure parent overflow is recorded before processing children
- **Capping values:** Each glass holds at most 1.0, excess flows down
- **Pyramid indexing:** Row i has (i+1) glasses indexed from 0 to i
- **Space optimization possible:** Only need current and next row, not entire pyramid
- **Early termination:** No need to process rows beyond `query_row`
- **Floating point precision:** Use `double` for fractional amounts
- **Physics simulation:** Problem models real-world liquid flow behavior
- **Similar to Pascal's triangle:** Structure follows triangular pattern
- **Greedy flows naturally:** No need to track paths, just simulate flow
- Related problems: Triangle path sum, Pascal's triangle generation, water flow simulation

---
