# 835. Image Overlap

**Difficulty:** `Medium`  
**Tags:** `Array`, `Matrix`

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

[LeetCode — 835. Image Overlap](https://leetcode.com/problems/image-overlap/)

---

## Problem Summary

The problem involves two binary images, img1 and img2, of size n x n. The goal is to find the maximum number of overlapping 1-bits by translating one image (shifting rows and columns). The solution iterates through all possible shifts to calculate the overlap for each, returning the maximum value found.

---

## Examples

### Example 1
**Input:** `img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]`  
**Output:** `3`  
**Explanation:**
- We translate img1 to right by 1 unit and down by 1 unit.
- The number of positions that have a 1 in both images is 3 (shown in red).

### Example 2
**Input:** `img1 = [[1]], img2 = [[1]]`  
**Output:** `1`  

### Example 3
**Input:** `img1 = [[0]], img2 = [[0]]`  
**Output:** `0`  

---

## Intuition

To find the largest overlap, we need to consider all possible relative positions of the two images. Since we can shift in both the row (dr) and column (dc) directions, we perform a double loop over all possible shift values. For each shift, we count the number of 1-bits in img1 that align with 1-bits in img2 at the shifted coordinates. The maximum count across all shifts represents the largest possible overlap.

---

## Approach

1. Iterate over all possible row shifts (dr) from -(n-1) to n-1.
2. For each row shift, iterate over all possible column shifts (dc) from -(n-1) to n-1.
3. For each combination of dr and dc, calculate the overlap by iterating through the cells of img1.
4. If a cell in img1 contains a 1, check if the corresponding shifted cell (i+dr, j+dc) is within the bounds of img2 and contains a 1. If so, increment the overlap counter.
5. Update the global maximum overlap (ans) with the current overlap value if it is larger.
6. Return the final maximum overlap value.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^4)` — The solution involves three nested loops: two for iterating over the shift parameters (dr and dc), and one for iterating over the cells of the image. Since the image size is n x n, the total number of operations is proportional to n^4. |
| **Space** | `O(1)` — The algorithm uses a constant amount of extra space for variables like dr, dc, overlap, and ans. No additional data structures or arrays are created that scale with the input size, making the space complexity constant. |

---

## Code (C++)

```cpp
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        // Try every possible row shift
        for (int dr = -(n - 1); dr <= n - 1; dr++) {

            // Try every possible column shift
            for (int dc = -(n - 1); dc <= n - 1; dc++) {

                int overlap = 0;

                // Check every cell of img1
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        if (img1[i][j] == 0)
                            continue;

                        int ni = i + dr;
                        int nj = j + dc;

                        // Check if shifted position is inside img2
                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < n &&
                            img2[ni][nj] == 1) {
                            
                            overlap++;
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The problem requires a brute-force approach to test all possible translations to find the maximum overlap.
- The time complexity is high (O(n^4)) because of the multiple nested loops, which is acceptable for the small input sizes typically seen in such problems.
- The space complexity is low (O(1)) as the solution relies on simple arithmetic and does not require storing intermediate results in large data structures.
