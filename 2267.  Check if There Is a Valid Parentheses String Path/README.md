# 2267.  Check if There Is a Valid Parentheses String Path

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`, `Matrix`, `Bracket Sequences`

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

[LeetCode — 2267.  Check if There Is a Valid Parentheses String Path](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)

---

## Problem Summary

The problem requires determining if a valid parentheses string can be formed by traversing a 2D grid from the top-left to the bottom-right. The path must follow a specific sequence of '(', ')' characters that satisfy the standard rules of a valid parentheses expression, such as '()', '()()', or '(())'.

---

## Examples

### Example 1
**Input:** `grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]`  
**Output:** `true`  
**Explanation:**
- The above diagram shows two possible paths that form valid parentheses strings.
- The first path shown results in the valid parentheses string "()(())".
- The second path shown results in the valid parentheses string "((()))".
- Note that there may be other valid parentheses string paths.

### Example 2
**Input:** `grid = [[")",")"],["(","("]]`  
**Output:** `false`  
**Explanation:**
- The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.

---

## Intuition

The solution employs a depth-first search (DFS) with memoization to explore all possible paths. The key insight is to track the 'balance' of parentheses (the difference between the number of '(' and ')') at each step. If the balance ever becomes negative (meaning there are more ')' than '('), the path is invalid. The goal is to reach the bottom-right corner with a balance of zero, indicating a perfectly matched parentheses string.

---

## Approach

1. Initialize a 3D memoization array to store the results of sub-problems, preventing redundant calculations.
2. Define a recursive function that takes the current position (i, j) and the current balance k. If the balance is negative or the position is out of bounds, return false.
3. If the current cell is a '(', increase the balance; if it's a ')', decrease it.
4. If the current position is the bottom-right corner, check if the balance is zero. If so, return true; otherwise, return false.
5. Recursively explore the two possible directions (down and right) and return true if either path leads to a valid solution.
6. Store the result of the current state in the memoization array before returning.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n * (m + n))` — The time complexity is determined by the number of unique states. There are m * n positions, and for each position, the balance can range from 0 to m + n (since the maximum imbalance is bounded by the total number of steps). Thus, the total number of states is m * n * (m + n). |
| **Space** | `O(m * n * (m + n))` — The space complexity is dominated by the memoization array, which has dimensions m, n, and m+n. Additionally, there is a stack space for the recursion, which is proportional to the maximum path length, O(m + n). |

---

## Code (C++)

```cpp
class Solution {
 public:
  bool hasValidPath(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<vector<int>>> mem(
        m, vector<vector<int>>(n, vector<int>(m + n, -1)));
    return hasValidPath(grid, 0, 0, 0, mem);
  }

 private:
  // Returns true if there's a path from grid[i][j] to grid[m - 1][n - 1], where
  // the number of '(' - the number of ')' == k.
  bool hasValidPath(const vector<vector<char>>& grid, int i, int j, int k,
                    vector<vector<vector<int>>>& mem) {
    if (i == grid.size() || j == grid[0].size())
      return false;
    k += grid[i][j] == '(' ? 1 : -1;
    if (k < 0)
      return false;
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
      return k == 0;
    if (mem[i][j][k] != -1)
      return mem[i][j][k];
    return mem[i][j][k] = hasValidPath(grid, i + 1, j, k, mem) |
                          hasValidPath(grid, i, j + 1, k, mem);
  }
};
```

---

## Key Takeaways

- This problem demonstrates the application of dynamic programming (memoization) to solve a path-finding problem with a specific constraint (parentheses balance).
- The use of a 3D array to store the state of the problem (position and balance) is a standard technique for optimizing recursive solutions.
- The solution highlights the importance of tracking intermediate states (balance) to determine the validity of a sequence, rather than just the final result.
