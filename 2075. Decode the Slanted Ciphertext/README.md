# 2075. Decode the Slanted Ciphertext

**Difficulty:** `Medium`  
**Tags:** `String`, `Matrix`, `Simulation`

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

[LeetCode - 2075. Decode the Slanted Ciphertext](https://leetcode.com/problems/decode-the-slanted-ciphertext/)

---

## Problem Summary

A text was encoded by first placing characters in a matrix diagonally (top-left to bottom-right), then reading the matrix row by row to form `encodedText`.

Given `encodedText` and number of rows `rows`, return the original text.

Important note:
- original text has no trailing spaces, so trailing spaces after reconstruction must be removed.

---

## Examples

### Example 1
**Input:** `encodedText = "ch   ie   pr", rows = 3`  
**Output:** `"cipher"`

### Example 2
**Input:** `encodedText = "iveo    eed   l te   olc", rows = 4`  
**Output:** `"i love leetcode"`

### Example 3
**Input:** `encodedText = "coding", rows = 1`  
**Output:** `"coding"`

---

## Intuition

Since `encodedText` is row-wise flattening of the matrix, we can conceptually rebuild indexing as:
- `cols = encodedText.length / rows`
- character at matrix cell `(r, c)` corresponds to index `r * cols + c` in `encodedText`

To decode, we read diagonals starting from the first row:
- start at `(0, j)` for each column `j`
- move `(r + 1, c + 1)` until out of bounds

This reproduces the original insertion order.

---

## Approach

1. Handle edge case: if `rows == 1`, return `encodedText` directly.
2. Compute `cols = encodedText.size() / rows`.
3. For each starting column `j` in `[0, cols - 1]`:
   - Traverse diagonal `(0, j) -> (1, j+1) -> ...`
   - Append characters from `encodedText[r * cols + c]`.
4. Trim trailing spaces from the built result.
5. Return the result.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` where `n = encodedText.length` |
| **Space** | `O(n)` for the output string |

---

## Code (C++)

```cpp
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size();

        if (rows == 1) return encodedText; // edge case

        int cols = len / rows;

        string result = "";

        // Traverse diagonals
        for (int j = 0; j < cols; j++) {
            int i = 0, col = j;

            while (i < rows && col < cols) {
                result += encodedText[i * cols + col];
                i++;
                col++;
            }
        }

        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
```

---

## Key Takeaways

- Convert between flattened string index and matrix coordinates using `r * cols + c`.
- Diagonal traversal can reconstruct non-row-wise write order.
- Always respect post-processing constraints like trimming trailing spaces.
