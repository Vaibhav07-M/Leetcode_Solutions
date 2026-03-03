# 1536. Minimum Swaps to Arrange a Binary Grid

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Sorting`, `Matrix`

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

[LeetCode — 1536. Minimum Swaps to Arrange a Binary Grid](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/)

---

## Problem Summary

Given an `n x n` binary grid, in one step you can choose **two adjacent rows** and swap them.

A grid is **valid** if all cells **above the main diagonal** are `0`.

Return the **minimum number of swaps** needed to make the grid valid, or `-1` if it's impossible.

---

## Examples

### Example 1
**Input:** `grid = [[0,0,1],[1,1,0],[1,0,0]]`  
**Output:** `3`  
**Explanation:**
- Row 0 needs ≥ 2 trailing zeros → must use row `[1,0,0]` (2 trailing zeros)
- Row 1 needs ≥ 1 trailing zero  → must use row `[1,1,0]` (1 trailing zero)
- Row 2 needs ≥ 0 trailing zeros → any row works
- 3 adjacent swaps total to bubble the right rows into place.

### Example 2
**Input:** `grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]`  
**Output:** `-1`  
**Explanation:** All rows have the same trailing-zero count; no swap can satisfy the requirement.

### Example 3
**Input:** `grid = [[1,0,0],[1,1,0],[1,1,1]]`  
**Output:** `0`  
**Explanation:** Grid is already valid — no swaps needed.

---

## Intuition

For the grid to be valid, **row `i` must have at least `n - 1 - i` trailing zeros** (0-indexed), because those positions above the diagonal must all be `0`.

The greedy strategy is: for each row position `i`, find the **nearest row at or below `i`** that satisfies the trailing-zero requirement, then **bubble it up** with adjacent swaps.

---

## Approach

1. **Pre-compute trailing zeros** for each row — scan from right to left, count consecutive `0`s.
2. **Greedy placement** — for each row index `i` from `0` to `n - 1`:
   - We need a row with at least `n - 1 - i` trailing zeros.
   - Search downward from `i` for the first qualifying row `j`.
   - If none exists → return `-1`.
   - Bubble row `j` up to position `i` via adjacent swaps; increment swap counter by `j - i`.
3. Return the total swap count.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n²)` — for each of the `n` rows we scan up to `n` rows and perform up to `n` swaps |
| **Space** | `O(n)` — for the trailing-zeros array |

---

## Code (C++)

### Solution 1: Greedy Bubble-Up (Submitted)
```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n);

        // Step 1: Count trailing zeros for each row
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            trailing[i] = count;
        }

        int swaps = 0;

        // Step 2: For each row i, find nearest row with enough trailing zeros
        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;
            int j = i;

            // Find the closest qualifying row
            while (j < n && trailing[j] < need) j++;

            // No valid row found
            if (j == n) return -1;

            // Bubble row j up to position i
            while (j > i) {
                swap(trailing[j], trailing[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};
```

### Solution 2: Explicit Row Swap Tracking
```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        // Count trailing zeros per row
        auto countTrailing = [&](int row) {
            int cnt = 0;
            for (int j = n - 1; j >= 0 && grid[row][j] == 0; j--) cnt++;
            return cnt;
        };

        vector<int> tz(n);
        for (int i = 0; i < n; i++) tz[i] = countTrailing(i);

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;
            int j = i;
            while (j < n && tz[j] < need) j++;
            if (j == n) return -1;
            for (int k = j; k > i; k--) swap(tz[k], tz[k - 1]);
            swaps += j - i;
        }

        return swaps;
    }
};
```

### Solution 3: Early Termination Variant
```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> tz(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) tz[i]++;
                else break;
            }
            // Quick impossibility check: might catch -1 cases early
            if (tz[i] == 0 && i < n - 1) {
                // will still validate properly in main loop
            }
        }

        int swaps = 0;
        for (int i = 0; i < n - 1; i++) { // last row always fits (need = 0)
            int need = n - 1 - i;
            int j = i;
            while (j < n && tz[j] < need) j++;
            if (j == n) return -1;
            while (j > i) { swap(tz[j], tz[j - 1]); j--; swaps++; }
        }

        return swaps;
    }
};
```

---

## Key Takeaways

- The validity condition translates to a per-row trailing-zero requirement: row `i` needs ≥ `n - 1 - i` trailing zeros.
- Greedy is optimal here — always pick the nearest qualifying row to minimize swaps.
- Bubble-sort style upward movement is correct because only adjacent swaps are allowed.
- `-1` occurs when no row (at or below position `i`) has enough trailing zeros for that slot.
- Pre-computing trailing zeros reduces repeated work from `O(n³)` to `O(n²)`.
