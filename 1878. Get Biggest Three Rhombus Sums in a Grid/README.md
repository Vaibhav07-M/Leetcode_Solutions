# 1878. Get Biggest Three Rhombus Sums in a Grid

**Difficulty:** `Medium`  
**Tags:** `Array`, `Matrix`, `Prefix Sum`

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

[LeetCode - 1878. Get Biggest Three Rhombus Sums in a Grid](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/)

---

## Problem Summary

Given an `m x n` matrix `grid`, a rhombus sum is the sum of cells on the border of a valid rhombus (diamond) centered on some cell.

A rhombus can also have size `0` (just one cell).

Return the largest three distinct rhombus sums in descending order. If fewer than three distinct sums exist, return all of them.

---

## Examples

### Example 1
**Input:** `grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]`  
**Output:** `[228,216,211]`

### Example 2
**Input:** `grid = [[1,2,3],[4,5,6],[7,8,9]]`  
**Output:** `[20,9,8]`

### Example 3
**Input:** `grid = [[7,7,7]]`  
**Output:** `[7]`

---

## Intuition

Try every possible rhombus center `(i, j)`:
- size `0` contributes `grid[i][j]`
- for larger size `k`, check bounds first
- if valid, walk the 4 border edges and accumulate the sum

Keep all sums in a descending set so we automatically keep unique values and can extract top 3 quickly.

---

## Approach

1. Initialize a descending set `set<int, greater<int>>` to store distinct sums.
2. For each center `(i, j)` in the grid:
- Insert size `0` rhombus sum (`grid[i][j]`).
- Expand size `k = 1, 2, ...` while all four corners stay inside grid bounds.
- For each valid `k`, traverse border in 4 directed parts:
  - top to right
  - right to bottom
  - bottom to left
  - left to top
- Insert computed border sum into the set.
3. Iterate through set and take the first 3 values.
4. Return them as vector.

---

## Complexity

Let `R = min(m, n) / 2` (max possible rhombus radius).

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n * R^2)` (for each center, sum over radii, each border walk is `O(k)`) |
| **Space** | `O(U)` where `U` is number of distinct rhombus sums |

---

## Code (C++)

### Solution 1 - Enumerate Centers and Border Walk (Submitted)

```cpp
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> s;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                // size 0 rhombus
                s.insert(grid[i][j]);

                for(int k = 1; ; k++){

                    if(i-k < 0 || i+k >= m || j-k < 0 || j+k >= n)
                        break;

                    int sum = 0;

                    int x = i-k, y = j;

                    // top -> right
                    while(x < i && y < j+k){
                        sum += grid[x][y];
                        x++; y++;
                    }

                    // right -> bottom
                    while(x < i+k && y > j){
                        sum += grid[x][y];
                        x++; y--;
                    }

                    // bottom -> left
                    while(x > i && y > j-k){
                        sum += grid[x][y];
                        x--; y--;
                    }

                    // left -> top
                    while(x > i-k && y < j){
                        sum += grid[x][y];
                        x--; y++;
                    }

                    s.insert(sum);
                }
            }
        }

        vector<int> ans;

        for(int x : s){
            ans.push_back(x);
            if(ans.size() == 3)
                break;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Rhombus border can be handled by four directional edge walks.
- A descending set naturally enforces distinctness and sorted order.
- Since constraints are small (`m, n <= 50`), full center-radius enumeration is feasible.
