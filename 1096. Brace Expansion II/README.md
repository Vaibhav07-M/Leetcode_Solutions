# 1096. Brace Expansion II

**Difficulty:** `Hard`  
**Tags:** `Hash Table`, `String`, `Backtracking`, `Stack`, `Breadth-First Search`, `Sorting`

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

[LeetCode — 1096. Brace Expansion II](https://leetcode.com/problems/brace-expansion-ii/)

---

## Problem Summary

The problem involves interpreting a string expression that represents a set of words using specific grammar rules. The expression can contain single letters, comma-separated lists (representing union), and nested braces (representing concatenation). The goal is to parse this expression and return a sorted list of all distinct words it represents.

---

## Examples

### Example 1
**Input:** `expression = "{a,b}{c,{d,e}}"`  
**Output:** `["ac","ad","ae","bc","bd","be"]`  

### Example 2
**Input:** `expression = "{{a,z},a{b,c},{ab,z}}"`  
**Output:** `["a","ab","ac","z"]`  
**Explanation:**
- Each distinct word is written only once in the final answer.

---

## Intuition

The solution uses a recursive parsing approach to handle the nested structure of the expression. It identifies two main types of elements: 'terms' (which can be single letters or nested expressions) and 'expressions' (which are sequences of terms separated by commas). The core logic involves iteratively concatenating the results of parsing terms to build the final set of words, while using a set to automatically handle duplicates.

---

## Approach

1. The `parseExpression` function handles the top-level parsing, iterating through the expression and processing each term separated by commas. It accumulates the results into a single set, effectively performing the union operation described in the grammar.
2. The `parseTerm` function is responsible for parsing individual terms. It starts with an empty string and iteratively appends characters or nested expressions. If it encounters a '{', it recursively calls `parseExpression` to handle the nested content. If it encounters a letter, it adds that letter to the current term.
3. After parsing each segment, the code performs a 'concatenation' step. It takes the current set of words and the newly parsed set, and creates a new set containing all possible combinations of these words (a + b for a in current, b in next). This implements the concatenation rule of the grammar.
4. The final result is converted from a set to a sorted vector to satisfy the output requirements.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * 2^n)` — The time complexity is exponential because the number of possible concatenations grows exponentially with the depth of the expression. In the worst case, where the expression is a long chain of single letters, the number of distinct words generated is 2^n, and the algorithm must process each of these possibilities. |
| **Space** | `O(2^n)` — The space complexity is also exponential, as the set used to store the results can contain up to 2^n distinct elements in the worst-case scenario. The recursion stack depth is limited by the nesting level, which is typically much smaller than n, so the dominant factor is the size of the output set. |

---

## Code (C++)

```cpp
class Solution {
public:

    string s;
    int pos;

    set<string> parseExpression() {

        set<string> result = parseTerm();

        while (pos < s.size() && s[pos] == ',') {
            pos++;

            set<string> next = parseTerm();

            // Union
            for (string word : next) {
                result.insert(word);
            }
        }

        return result;
    }

    set<string> parseTerm() {

        set<string> result;
        result.insert("");

        while (pos < s.size() &&
               s[pos] != '}' &&
               s[pos] != ',') {

            set<string> next;

            if (s[pos] == '{') {

                pos++; // skip '{'

                next = parseExpression();

                pos++; // skip '}'

            }
            else {

                // Single letter
                next.insert(string(1, s[pos]));
                pos++;
            }

            // Concatenation
            set<string> combined;

            for (string a : result) {
                for (string b : next) {
                    combined.insert(a + b);
                }
            }

            result = combined;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        s = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};
```

---

## Key Takeaways

- The solution demonstrates a recursive approach to parsing a context-free grammar, specifically handling nested expressions and concatenation.
- It highlights the use of a set data structure to efficiently manage the union of results and eliminate duplicate words.
- The exponential time and space complexity are inherent to the problem's nature, as the number of possible word combinations increases rapidly with the length of the input expression.
