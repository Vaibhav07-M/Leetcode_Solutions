# 3727. Maximum Alternating Sum of Squares

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Sorting`

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

[LeetCode — 3727. Maximum Alternating Sum of Squares](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)

---

## Problem Summary

The problem requires rearranging an integer array to maximize its alternating score, which is calculated by summing the squares of elements with alternating signs (positive for even indices, negative for odd indices). The goal is to find the optimal permutation that yields the highest possible score.

---

## Examples

_No examples provided._

---

## Intuition

To maximize the alternating sum, we want to place the largest squares in the positive positions (even indices) and the smallest squares in the negative positions (odd indices). Since the score is a linear combination of squares, sorting the elements allows us to systematically assign the largest values to the positive terms and the smallest values to the negative terms, ensuring the maximum possible difference.

---

## Approach

1. Compute the square of each element in the input array and store them in a new vector.
2. Sort the vector of squares in ascending order.
3. Iterate through the sorted squares: for the first half of the elements (up to the middle index), add the square (since it corresponds to a positive term in the alternating sequence). For the second half, subtract the square (since it corresponds to a negative term).
4. The final sum represents the maximum alternating score achievable with the given elements.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — The dominant operation is sorting the vector of squares, which has a time complexity of O(n log n). The subsequent iteration to calculate the sum is linear, O(n), but the sorting step determines the overall bound. |
| **Space** | `O(n)` — The solution creates a new vector to store the squares of the input elements, requiring O(n) additional space. The sorting is performed in-place, so no extra space is needed for the sorting algorithm itself. |

---

## Code (C++)

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;

        for (int num : nums) {
            squares.push_back(1LL * num * num);
        }

        sort(squares.begin(), squares.end());

        int n = squares.size();
        long long answer = 0;

        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2) {
                answer += squares[n - 1 - i];
            } else {
                answer -= squares[n - 1 - i];
            }
        }

        return answer;
    }
};
```

---

## Key Takeaways

- The problem can be solved by transforming the input into a form suitable for linear optimization (squares) and then sorting.
- The key insight is that the optimal arrangement involves pairing the largest positive terms with the smallest negative terms (or vice versa, depending on the specific sign pattern), which is facilitated by sorting.
- This technique of sorting and alternating signs is a common strategy for maximizing or minimizing linear combinations of squared terms.
