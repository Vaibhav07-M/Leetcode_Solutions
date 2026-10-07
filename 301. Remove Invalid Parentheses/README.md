# 301. Remove Invalid Parentheses

**Difficulty:** `Hard`  
**Tags:** `String`, `Backtracking`, `Breadth-First Search`

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

[LeetCode — 301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)

---

## Problem Summary

The problem requires removing the minimum number of parentheses from a string to make it valid. A valid string has balanced parentheses (equal number of opening and closing) and no closing parenthesis before its corresponding opening one. The goal is to find all unique valid strings with the fewest possible removals.

---

## Examples

### Example 1
**Input:** `s = "()())()"`  
**Output:** `["(())()","()()()"]`  

### Example 2
**Input:** `s = "(a)())()"`  
**Output:** `["(a())()","(a)()()"]`  

### Example 3
**Input:** `s = ")("`  
**Output:** `[""]`  

---

## Intuition

The solution uses a Breadth-First Search (BFS) approach to systematically explore all possible ways to remove parentheses. Starting with the original string, it generates new candidate strings by removing one parenthesis at a time. The BFS ensures that the first valid string found (with the minimum number of removals) is identified quickly, and all other valid strings with the same minimum number of removals are also collected.

---

## Approach

1. Initialize a queue with the original string and a set to track visited strings.
2. Perform BFS: For each string in the queue, check if it is valid. If valid, add it to the answer list. If not, generate new candidate strings by removing each parenthesis and add them to the queue if not already visited.
3. Continue until a valid string is found or the queue is empty.
4. Return the list of valid strings.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(2^n)` — In the worst case, the number of possible strings to check grows exponentially with the length of the input string (n), as there are 2^n possible subsets of parentheses to remove. |
| **Space** | `O(2^n)` — The space complexity is dominated by the queue and the visited set, which can store up to 2^n different strings in the worst case. |

---

## Code (C++)

```cpp
class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                count++;
            }
            else if (c == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> answer;
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();

            while (size--) {
                string current = q.front();
                q.pop();

                if (isValid(current)) {
                    answer.push_back(current);
                    found = true;
                    continue;
                }

                // Generate strings by removing one parenthesis
                for (int i = 0; i < current.size(); i++) {

                    if (current[i] != '(' && current[i] != ')')
                        continue;

                    string next = current.substr(0, i) +
                                  current.substr(i + 1);

                    if (visited.count(next))
                        continue;

                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return answer;
    }
};
```

---

## Key Takeaways

- BFS is an effective algorithm for finding the minimum number of operations required to reach a valid state.
- The `isValid` function provides a simple linear-time check for parenthesis balance.
- The solution efficiently prunes the search space by avoiding duplicate strings using a visited set.
