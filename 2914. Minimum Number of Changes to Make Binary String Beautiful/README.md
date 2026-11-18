# 2914. Minimum Number of Changes to Make Binary String Beautiful

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

[LeetCode — 2914. Minimum Number of Changes to Make Binary String Beautiful](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/)

---

## Problem Summary

The problem requires transforming a binary string into a 'beautiful' state, where it can be partitioned into even-length substrings of identical characters. The goal is to minimize the number of character changes needed to achieve this condition.

---

## Examples

### Example 1
**Input:** `s = "1001"`  
**Output:** `2`  
**Explanation:**
- We change s[1] to 1 and s[3] to 0 to get string "1100".
- It can be seen that the string "1100" is beautiful because we can partition it into "11|00".
- It can be proven that 2 is the minimum number of changes needed to make the string beautiful.

### Example 2
**Input:** `s = "10"`  
**Output:** `1`  
**Explanation:**
- We change s[1] to 1 to get string "11".
- It can be seen that the string "11" is beautiful because we can partition it into "11".
- It can be proven that 1 is the minimum number of changes needed to make the string beautiful.

### Example 3
**Input:** `s = "0000"`  
**Output:** `0`  
**Explanation:**
- We don't need to make any changes as the string "0000" is beautiful already.

---

## Intuition

The solution employs a greedy, state-tracking approach. It iterates through the string, maintaining a count of consecutive identical characters. When a character change is detected, it checks if the current run is even-length. If it is, the run is reset; if it is odd, a change is recorded to force the next run to start even, ensuring the overall string remains partitionable into even-length segments.

---

## Approach

1. Initialize a counter for changes and a variable to track the current character.
2. Iterate through the string, incrementing a 'count' for each consecutive character.
3. When a different character is encountered, check if the current count is even. If even, reset the count to 1 (starting a new run). If odd, increment the change counter and reset the count to 0, effectively 'fixing' the odd-length run.
4. Update the current character to the new value and continue iterating.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm performs a single linear scan of the input string, with constant-time operations at each step, resulting in a linear time complexity relative to the string length. |
| **Space** | `O(1)` — The solution uses only a few integer variables (count, changes, curr) to track state, requiring no additional data structures or dynamic memory allocation that scales with input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minChanges(string s) {
        char curr = s[0];

        int count = 0;
        int changes = 0;
        int n = s.length();

        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {

            if (s[i] == curr) {
                count++;
                continue;
            }

            if (count % 2 == 0) { //Even
                count = 1;
            } else { //Odd
                count = 0;
                changes++;
            }
            
            curr = s[i];
        }

        return changes;
    }
};
```

---

## Key Takeaways

- A greedy, linear-time algorithm can efficiently solve the partitioning problem by tracking character runs.
- The key insight is to detect odd-length runs and force them to even length by recording a change, ensuring the final string is partitionable.
