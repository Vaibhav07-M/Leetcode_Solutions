# 1541. Minimum Insertions to Balance a Parentheses String

**Difficulty:** `Medium`  
**Tags:** `String`, `Stack`, `Greedy`, `Bracket Sequences`

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

[LeetCode — 1541. Minimum Insertions to Balance a Parentheses String](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)

---

## Problem Summary

The problem requires balancing a parentheses string where each opening parenthesis '(' must be matched by two consecutive closing parentheses ')). The goal is to determine the minimum number of insertions needed to achieve this balance, considering that unmatched openings require two insertions and unmatched closings require one.

---

## Examples

### Example 1
**Input:** `s = "(()))"`  
**Output:** `1`  
**Explanation:**
- The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.

### Example 2
**Input:** `s = "())"`  
**Output:** `0`  
**Explanation:**
- The string is already balanced.

### Example 3
**Input:** `s = "))())("`  
**Output:** `3`  
**Explanation:**
- Add '(' to match the first '))', Add '))' to match the last '('.

---

## Intuition

The solution employs a greedy approach by iterating through the string and maintaining a count of unmatched opening parentheses. It checks for complete '))' pairs and matches them with existing openings. If a closing parenthesis is found without a pair, an insertion is required. Similarly, if an opening parenthesis is found without a corresponding closing pair at the end, two insertions are needed to complete the match.

---

## Approach

1. Initialize a counter for unmatched opening parentheses ('open') and a variable for the total number of insertions ('answer').
2. Iterate through the string. For each character:
3. If it is '(', increment the 'open' counter.
4. If it is ')', check if the next character is also ')'. If so, skip the next character to form the '))' pair. If not, increment 'answer' to insert a missing ')' to complete the pair.
5. After forming a potential pair, if there are unmatched openings ('open > 0'), decrement the counter to match them. Otherwise, increment 'answer' to insert a missing '('.
6. After the loop, calculate the remaining unmatched openings and add twice their count to 'answer' since each requires two ')' to balance.
7. Return the total number of insertions.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm performs a single pass through the string, processing each character once. The operations (checking characters, updating counters) are constant time, leading to a linear time complexity relative to the string length. |
| **Space** | `O(1)` — The solution uses only a few integer variables (open and answer) to track state, requiring no additional data structures or dynamic memory allocation. Therefore, the space complexity is constant. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int answer = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // If the next character is ')',
                // we have a complete '))' pair
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // Insert one ')' to complete the pair
                    answer++;
                }

                // Match this '))' with an opening '('
                if (open > 0) {
                    open--;
                }
                else {
                    // Insert a missing '('
                    answer++;
                }
            }
        }

        // Each remaining '(' needs two ')'
        answer += open * 2;

        return answer;
    }
};
```

---

## Key Takeaways

- The problem demonstrates a specific balancing rule where a single opening parenthesis corresponds to a double closing parenthesis, which is distinct from standard bracket matching.
- The greedy strategy of matching pairs as they are encountered and tracking unmatched elements is effective for minimizing insertions.
- The final step of multiplying the remaining open count by 2 is crucial for accounting for the specific requirement of two closing parentheses per opening.
