# 1970. Last Day Where You Can Still Cross

**Difficulty:** `Hard`  
**Tags:** `Array`, `Binary Search`, `BFS`, `DFS`, `Union Find`, `Matrix`

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

[LeetCode — 1970. Last Day Where You Can Still Cross](https://leetcode.com/problems/last-day-where-you-can-still-cross/)

---

## Problem Summary

You have a binary matrix where `0` represents land and `1` represents water. Initially (day 0), the entire matrix is land.

Each day, one new cell becomes flooded with water according to the array `cells`, where `cells[i] = [ri, ci]` means on day `i+1`, the cell at row `ri` and column `ci` becomes water.

**Goal:** Find the **last day** where you can walk from **any cell in the top row** to **any cell in the bottom row** by only walking on land cells (moving in 4 cardinal directions).

---

## Examples

### Example 1
**Input:** `row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]`  
**Output:** `2`  
**Explanation:**
- Day 0: All land
- Day 1: [1,1] becomes water
- Day 2: [2,1] becomes water → Still can cross via [1,2] → [2,2]
- Day 3: [1,2] becomes water → Cannot cross anymore
- Last day to cross: Day 2

### Example 2
**Input:** `row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]`  
**Output:** `1`  
**Explanation:**
- Day 1: Top row cell [1,1] floods, can still cross via [1,2] → [2,2]
- Day 2: [1,2] floods → Cannot cross
- Last day: Day 1

### Example 3
**Input:** `row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]`  
**Output:** `3`

---

## Intuition

The problem asks for the **last day** we can still cross, which suggests:
1. Early days → easy to cross (less water)
2. Later days → harder to cross (more water)
3. There's a **turning point** where crossing becomes impossible

This monotonic property is perfect for **binary search**:
- If we can cross on day X, we might be able to cross on day X-1 too
- If we cannot cross on day X, we definitely cannot cross on day X+1

For each day candidate, we need to check if crossing is possible using **BFS/DFS** from the top row to the bottom row.

---

## Approach

### Binary Search + BFS Strategy

1. **Binary Search on Days:**
   - Search space: day 0 to day `cells.size() - 1`
   - For each middle day, check if crossing is possible
   - If possible → try later days (search right half)
   - If not possible → try earlier days (search left half)

2. **Check if Crossing is Possible on Day X:**
   - Build grid state up to day X by marking flooded cells as water (1)
   - Try BFS from every land cell in the top row
   - If any BFS reaches the bottom row → crossing is possible

3. **BFS Implementation:**
   - Start from a top-row land cell
   - Explore 4 cardinal directions
   - Mark visited cells to avoid revisiting
   - If we reach any cell in the bottom row → return true

4. **Return Result:**
   - Convert 0-indexed day to 1-indexed (add 1)

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(row * col * log(row * col))` |
| **Space** | `O(row * col)` |

**Breakdown:**
- Binary search: `O(log(row * col))` iterations
- Each iteration: BFS takes `O(row * col)` to check all cells
- Grid state: `O(row * col)` space

---

## Code (C++)

```cpp
class Solution {
public:
    int totalRows;
    int totalCols;
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool bfsCheck(vector<vector<int>>& mapState, int startRow, int startCol) {
        queue<pair<int,int>> q;
        q.push({startRow, startCol});
        mapState[startRow][startCol] = 1; // mark visited
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int row = current.first;
            int col = current.second;
            
            // Reached bottom row - crossing successful
            if (row == totalRows - 1)
                return true;
            
            // Explore neighbors in 4 directions
            for (auto& step : directions) {
                int nextRow = row + step[0];
                int nextCol = col + step[1];
                
                // Check bounds and if cell is land
                if (nextRow >= 0 && nextRow < totalRows &&
                    nextCol >= 0 && nextCol < totalCols &&
                    mapState[nextRow][nextCol] == 0) 
                {
                    mapState[nextRow][nextCol] = 1; // mark visited
                    q.push({nextRow, nextCol});
                }
            }
        }
        
        return false;
    }
    
    bool canWalkOnDay(vector<vector<int>>& cells, int dayIndex) {
        // Initialize grid as all land
        vector<vector<int>> gridState(totalRows, vector<int>(totalCols, 0));
        
        // Mark flooded cells up to dayIndex
        for (int d = 0; d <= dayIndex; d++) {
            int r = cells[d][0] - 1; // convert to 0-indexed
            int c = cells[d][1] - 1;
            gridState[r][c] = 1;
        }
        
        // Try BFS from every land cell in top row
        for (int col = 0; col < totalCols; col++) {
            if (gridState[0][col] == 0) {
                // Make a copy for this BFS attempt
                vector<vector<int>> tempGrid = gridState;
                if (bfsCheck(tempGrid, 0, col))
                    return true;
            }
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        totalRows = row;
        totalCols = col;

        int left = 0;
        int right = cells.size() - 1;
        int lastPossibleDay = 0;
        
        // Binary search on days
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canWalkOnDay(cells, mid)) {
                lastPossibleDay = mid + 1; // convert to 1-indexed
                left = mid + 1; // try later days
            } 
            else {
                right = mid - 1; // try earlier days
            }
        }
        
        return lastPossibleDay;
    }
};
```

---

## Key Takeaways

- Binary search works well on problems with monotonic properties (if X fails, X+1 also fails).
- BFS is efficient for finding paths in grid problems with 4-directional movement.
- Combining binary search with BFS reduces time complexity from O(n²) to O(n log n).
- Always check boundary conditions and convert between 0-indexed and 1-indexed coordinates carefully.
