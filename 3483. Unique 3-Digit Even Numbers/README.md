# 3483. Unique 3-Digit Even Numbers

**Difficulty:** `Easy`  
**Tags:** `Array`, `Hash Table`, `Recursion`, `Enumeration`

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

[LeetCode — 3483. Unique 3-Digit Even Numbers](https://leetcode.com/problems/unique-3-digit-even-numbers/)

---

## Problem Summary

The problem requires counting the number of distinct three-digit even numbers that can be formed from a given array of digits. The solution uses a brute-force approach with nested loops to generate all possible combinations, filtering them based on the constraints (no leading zeros, last digit must be even, and no duplicate use of the same digit index).

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to systematically enumerate all possible three-digit numbers by iterating over the digit array for each position. The constraints are applied as filters within the loops to ensure only valid, distinct even numbers are added to the set.

---

## Approach

1. Iterate over the first digit position (i), ensuring it is not 0.
2. Iterate over the second digit position (j), ensuring it is different from the first.
3. Iterate over the third digit position (k), ensuring it is different from the first two and is an even number.
4. Construct the three-digit number by concatenating the digits.
5. Insert the number into a set to automatically remove duplicates.
6. Return the size of the set, which represents the count of distinct valid numbers.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^3)` — The solution uses three nested loops, each iterating over the array of digits (length n). This results in a total of O(n^3) operations to check all possible combinations. |
| **Space** | `O(n^3)` — In the worst case, where all digits are distinct and valid, the set could contain up to O(n^3) elements. The space complexity is driven by the storage of the generated numbers in the set. |

---

## Code (C++)

```cpp
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> numbers;

        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {

                    // Cannot use the same copy twice
                    if (i == j || i == k || j == k)
                        continue;

                    // First digit cannot be 0
                    if (digits[i] == 0)
                        continue;

                    // Last digit must be even
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    numbers.insert(num);
                }
            }
        }

        return numbers.size();
    }
};
```

---

## Key Takeaways

- A brute-force enumeration is effective for small input sizes to find distinct combinations.
- Using a set is a simple way to filter out duplicate results.
- The constraints (no leading zeros, even last digit) are critical for defining the valid search space.
