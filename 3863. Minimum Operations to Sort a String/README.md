# 3863. Minimum Operations to Sort a String

**Difficulty:** `Medium`  
**Tags:** `String`

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

[LeetCode — 3863. Minimum Operations to Sort a String](https://leetcode.com/problems/minimum-operations-to-sort-a-string/)

---

## Problem Summary

The problem requires sorting a given string of lowercase letters by performing operations that sort non-full substrings. The goal is to determine the minimum number of such operations needed to achieve a fully sorted string in non-descending order. If the string cannot be sorted under these constraints, the output should be -1.

---

## Examples

_No examples provided._

---

## Intuition

The solution employs a greedy, case-based approach to minimize the number of sorting operations. It identifies the global minimum and maximum characters in the string and checks their positions relative to the rest of the data. The logic is based on the observation that if the first character is the minimum or the last character is the maximum, only one operation is needed to sort the rest. If the extremes are swapped, multiple operations are required to move them to their correct positions.

---

## Approach

1. Check if the string is already sorted; if so, return 0.
2. If the string length is 2, return -1 because no valid substring can be sorted to change the order.
3. Identify the minimum and maximum characters in the string.
4. If the first character is the minimum or the last character is the maximum, return 1, as only one operation is needed to sort the remaining substring.
5. If the first character is greater than the maximum of the middle characters and the last character is less than the minimum of the middle characters, return 3, indicating a complex swap scenario.
6. Otherwise, return 2, which covers the general case where two operations are typically sufficient to sort the string.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm iterates through the string to find the minimum and maximum elements, which takes linear time. The rest of the logic involves constant-time comparisons, making the overall complexity O(n). |
| **Space** | `O(1)` — The solution uses a fixed amount of extra space for variables (like min_char and max_char) regardless of the input size, resulting in constant space complexity. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if(is_sorted(begin(s), end(s)))
            return 0;
        
        if(n == 2) {
            return -1;
        }

        char min_char = *min_element(begin(s), end(s));
        char max_char = *max_element(begin(s), end(s));

        if(s[0] == min_char || s[n-1] == max_char)
            return 1;

        char max_mid = *max_element(begin(s)+1, end(s)-1);
        char min_mid = *min_element(begin(s)+1, end(s)-1);

        if(s[0] > max_mid && s[n-1] < min_mid) {
            return 3;
        }

        return 2;
    }
};
```

---

## Key Takeaways

- The solution demonstrates a greedy strategy for minimizing operations by leveraging the positions of extreme values.
- It highlights the importance of checking boundary conditions (like string length 2) to avoid invalid operations.
- The approach effectively breaks down the problem into specific cases based on the relative positions of the min and max characters.
