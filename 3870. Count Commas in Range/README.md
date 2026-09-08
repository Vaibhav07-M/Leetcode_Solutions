# 3870. Count Commas in Range

**Difficulty:** `Easy`  
**Tags:** `Math`

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

[LeetCode — 3870. Count Commas in Range](https://leetcode.com/problems/count-commas-in-range/)

---

## Problem Summary

The problem requires counting the total number of commas used in the standard decimal representation of integers from 1 to n. A comma is inserted after every three digits from the right, meaning numbers with fewer than 4 digits have no commas, while larger numbers have commas based on their digit count.

---

## Examples

_No examples provided._

---

## Intuition

The solution observes that commas only appear in numbers with at least 4 digits. Since the first number with a comma is 1000, the count of commas is simply the number of integers greater than or equal to 1000 within the range [1, n].

---

## Approach

1. Initialize a counter variable 'ans' to 0.
2. Iterate through the range of integers from 1000 to n (inclusive).
3. For each integer in this range, increment the 'ans' counter by 1, as each of these numbers contains at least one comma.
4. Return the final value of 'ans', which represents the total number of commas.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n - 1000)` — The loop iterates from 1000 to n, performing a constant-time operation (increment) for each step. The number of iterations is proportional to the difference between n and 1000. |
| **Space** | `O(1)` — The solution uses only a single integer variable ('ans') to store the count, requiring constant space regardless of the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int countCommas(int n) {
        int ans = 0;

        for (int i = 1000; i <= n; i++) {
            ans++;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The presence of commas in number formatting is directly related to the number of digits; specifically, commas are required for numbers with 4 or more digits.
- The problem can be efficiently solved by counting the number of elements in a specific subset of the range (integers >= 1000), rather than analyzing the digit structure of every single number.
