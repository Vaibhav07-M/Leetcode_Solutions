# 22. Generate Parentheses

**Difficulty:** `Medium`  
**Tags:** `String`, `Dynamic Programming`, `Backtracking`, `Bracket Sequences`

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

[LeetCode — 22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

---

## Problem Summary

The problem requires generating all possible combinations of well-formed parentheses for a given number of pairs (n). A valid combination must have balanced brackets, meaning the number of opening brackets should never exceed the number of closing brackets at any point, and the total number of each type of bracket should be n.

---

## Examples

### Example 1
**Input:** `n = 3`  
**Output:** `["((()))","(()())","(())()","()(())","()()()"]`  

### Example 2
**Input:** `n = 1`  
**Output:** `["()"]`  

---

## Intuition

The solution uses a backtracking approach to recursively build the string of parentheses. It maintains two counters: 'open' for the number of opening brackets used and 'close' for the number of closing brackets used. The key insight is to only add an opening bracket if there are still fewer than n opening brackets available, and to only add a closing bracket if there are fewer closing brackets than opening brackets (ensuring the sequence remains valid).

---

## Approach

1. Initialize an empty vector 'answer' to store the generated combinations.
2. Define a recursive function 'backtrack' that takes the current string, the count of open brackets, the count of close brackets, and the total number of pairs n.
3. In the 'backtrack' function, check if the current string length is 2*n. If so, add the string to the 'answer' vector as it represents a complete, valid combination.
4. If the string is not complete, recursively call 'backtrack' with an additional opening bracket ('(') if the 'open' count is less than n.
5. Also, recursively call 'backtrack' with an additional closing bracket (')') if the 'close' count is less than the 'open' count.
6. The 'generateParenthesis' function starts the recursion by calling 'backtrack' with an empty string and zero counts, and returns the collected 'answer' vector.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(4^n / sqrt(n))` — The time complexity is derived from the number of possible sequences. In the worst case, the algorithm explores all possible arrangements of 2n characters, which is O(2^(2n)). However, due to the constraints (open <= n and close <= open), the number of valid sequences is significantly reduced, typically to approximately 4^n / sqrt(n), which is the standard result for generating Catalan numbers via backtracking. |
| **Space** | `O(n)` — The space complexity is determined by the depth of the recursion stack, which is proportional to the length of the generated string (2n). Additionally, the 'answer' vector stores the results, but the primary space overhead is the recursive call stack. |

---

## Code (C++)

```cpp
class Solution {
public:

    vector<string> answer;

    void backtrack(string current, int open, int close, int n) {

        // We have used all brackets
        if (current.size() == 2 * n) {
            answer.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // Add closing bracket
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {

        backtrack("", 0, 0, n);

        return answer;
    }
};
```

---

## Key Takeaways

- Backtracking is an effective method for generating combinatorial sequences like parentheses, where constraints must be satisfied at each step.
- The use of counters for open and close brackets allows for efficient pruning of invalid sequences, ensuring the algorithm only explores valid paths.
- The problem is closely related to Catalan numbers, which describe the number of valid bracket sequences for a given n.
