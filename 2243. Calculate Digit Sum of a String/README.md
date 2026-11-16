# 2243. Calculate Digit Sum of a String

**Difficulty:** `Easy`  
**Tags:** `String`, `Simulation`

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

[LeetCode — 2243. Calculate Digit Sum of a String](https://leetcode.com/problems/calculate-digit-sum-of-a-string/)

---

## Problem Summary

The problem requires iteratively compressing a string of digits by grouping them into segments of length k and replacing each segment with the sum of its digits. This process repeats until the resulting string is shorter than or equal to the specified segment length k.

---

## Examples

### Example 1
**Input:** `s = "11111222223", k = 3`  
**Output:** `"135"`  
**Explanation:**
- For the first round, we divide s into groups of size 3: "111", "112", "222", and "23".
- ​​​​​Then we calculate the digit sum of each group: 1 + 1 + 1 = 3, 1 + 1 + 2 = 4, 2 + 2 + 2 = 6, and 2 + 3 = 5.
- So, s becomes "3" + "4" + "6" + "5" = "3465" after the first round.
- For the second round, we divide s into "346" and "5".
- Then we calculate the digit sum of each group: 3 + 4 + 6 = 13, 5 = 5.
- So, s becomes "13" + "5" = "135" after second round.
- Now, s.length <= k, so we return "135" as the answer.

### Example 2
**Input:** `s = "00000000", k = 3`  
**Output:** `"000"`  
**Explanation:**
- We divide s into "000", "000", and "00".
- Then we calculate the digit sum of each group: 0 + 0 + 0 = 0, 0 + 0 + 0 = 0, and 0 + 0 = 0.
- s becomes "0" + "0" + "0" = "000", whose length is equal to k, so we return "000".

---

## Intuition

The solution employs a simulation approach, repeatedly applying the compression rule until the string becomes sufficiently short. It uses nested loops to calculate the sum of digits for each segment and concatenates these sums to form the new, compressed string.

---

## Approach

1. Initialize a temporary string to store the compressed result.
2. Iterate over the input string in steps of k, treating each block as a segment.
3. For each segment, calculate the sum of its digits.
4. Convert the sum to a string and append it to the temporary result.
5. Update the input string to the temporary result and repeat the process until the string length is less than or equal to k.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * log(n / k))` — In each iteration, the string length is reduced by a factor of approximately k (since we sum k digits into one). The loop runs until the length is <= k, which takes roughly log(n / k) iterations. Within each iteration, we process the entire string, leading to the stated complexity. |
| **Space** | `O(n / k)` — The temporary string stores the compressed result. Since the compression reduces the length by a factor of k in each step, the maximum size of the temporary string is proportional to the original length divided by k. |

---

## Code (C++)

```cpp

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string temp = "";

            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;

                for (int j = i; j < i + k && j < s.length(); j++) {
                    sum += s[j] - '0';
                }

                temp += to_string(sum);
            }

            s = temp;
        }

        return s;
    }
};
```

---

## Key Takeaways

- This is a classic example of a 'reduce and conquer' or iterative simulation problem where a transformation is applied repeatedly until a termination condition is met.
- The time complexity is dominated by the number of iterations required to reach the base case, which is logarithmic relative to the initial string length.
