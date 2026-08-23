# 1927. Sum Game

**Difficulty:** `Medium`  
**Tags:** `Math`, `String`, `Greedy`, `Game Theory`

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

[LeetCode — 1927. Sum Game](https://leetcode.com/problems/sum-game/)

---

## Problem Summary

The problem involves determining the winner of a game between Alice and Bob. The game is played with a string of even length consisting of digits and '?' characters. The goal is to determine if Alice will win or Bob will win based on the sum of the digits in the first half and second half of the string. The game ends when there are no more '?' characters in the string. Alice wins if the sums are not equal, and Bob wins if the sums are equal.

---

## Examples

### Example 1
**Input:** `num = "5023"`  
**Output:** `false`  
**Explanation:**
- There are no moves to be made.
- The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.

### Example 2
**Input:** `num = "25??"`  
**Output:** `true`  
**Explanation:**
- Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.

### Example 3
**Input:** `num = "?3295???"`  
**Output:** `false`  
**Explanation:**
- It can be proven that Bob will always win. One possible outcome is:
- Alice replaces the first '?' with '9'. num = "93295???".
- Bob replaces one of the '?' in the right half with '9'. num = "932959??".
- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
- Bob replaces the last '?' in the right half with '7'. num = "93295927".
- Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.

---

## Intuition

The core insight of this solution is to calculate the difference in sums between the first half and the second half of the string, taking into account the '?' characters. The solution uses the fact that the '?' characters can be replaced with any digit between '0' and '9'. By calculating the difference in sums and considering the number of '?' characters in each half, the solution determines if Alice or Bob will win.

---

## Approach

1. Calculate the length of the input string. Initialize variables to keep track of the difference in sums and the number of '?' characters in each half. Iterate through the first half of the string, updating the difference in sums and the number of '?' characters. Iterate through the second half of the string, updating the difference in sums and the number of '?' characters. Check if the total number of '?' characters is odd, in which case Alice will win. Otherwise, check if the difference in sums is equal to the expected difference based on the number of '?' characters, and return the result accordingly.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — where n is the length of the input string, because we iterate through the string twice |
| **Space** | `O(1)` — because we use a constant amount of space to store the variables |

---

## Code (C++)

```cpp
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int diff = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                q1++;
            else
                diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                q2++;
            else
                diff -= num[i] - '0';
        }

        if ((q1 + q2) % 2 == 1)
            return true;

        return diff != 9 * (q2 - q1) / 2;
    }
};
```

---

## Key Takeaways

- The solution uses a greedy approach to calculate the difference in sums and determine the winner. The key insight is to consider the '?' characters and their impact on the sums. The solution also uses basic arithmetic operations to calculate the expected difference in sums based on the number of '?' characters.
