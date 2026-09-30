# 1111. Maximum Nesting Depth of Two Valid Parentheses Strings

**Difficulty:** `Medium`  
**Tags:** `String`, `Stack`, `Bracket Sequences`

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

[LeetCode — 1111. Maximum Nesting Depth of Two Valid Parentheses Strings](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/)

---

## Problem Summary

The problem requires splitting a valid parentheses string into two subsequences, A and B, such that the maximum nesting depth of either subsequence is minimized. The goal is to find a distribution of parentheses between the two sets that balances the depth, effectively minimizing the peak depth of the resulting strings.

---

## Examples

### Example 1
**Input:** `seq = "(()())"`  
**Output:** `[0,1,1,1,1,0]`  

### Example 2
**Input:** `seq = "()(())()"`  
**Output:** `[0,0,0,1,1,0,1,1]`  

---

## Intuition

The solution leverages the observation that the nesting depth of a string is determined by the balance of opening and closing parentheses. By assigning each new opening parenthesis to the set with the lower current depth (alternating between A and B), the algorithm ensures that the depth growth is distributed evenly between the two subsequences. This strategy prevents any single subsequence from accumulating excessive depth, thereby minimizing the maximum depth of the split.

---

## Approach

1. Initialize an empty vector 'answer' to store the assignment of each character (0 for A, 1 for B) and a variable 'depth' to track the current nesting depth.
2. Iterate through each character in the input string 'seq'.
3. If the character is an opening parenthesis '(', increment the 'depth' and assign the character to the set corresponding to the current depth modulo 2 (e.g., if depth is 0, assign to A; if depth is 1, assign to B).
4. If the character is a closing parenthesis ')', decrement the 'depth' and assign the character to the set corresponding to the new depth modulo 2.
5. The final 'answer' vector represents the optimal split where the maximum depth of A and B is minimized.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm consists of a single loop that iterates through the 'n' characters of the input string, performing constant-time operations (comparison and assignment) for each character. Therefore, the time complexity is linear. |
| **Space** | `O(n)` — The space complexity is determined by the output vector 'answer', which stores an integer for each of the 'n' characters in the input string. While the depth variable uses constant space, the primary space requirement is for the result storage. |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        vector<int> answer;

        int depth = 0;

        for (char c : seq) {

            if (c == '(') {

                // Assign based on current depth
                answer.push_back(depth % 2);

                depth++;
            }

            else {

                depth--;

                // Assign based on new depth
                answer.push_back(depth % 2);
            }
        }

        return answer;
    }
};
```

---

## Key Takeaways

- The key to minimizing the maximum depth is to distribute the parentheses evenly between the two sets, preventing one set from becoming significantly deeper than the other.
- The solution employs a simple modulo-based assignment strategy to alternate the distribution of parentheses, effectively balancing the depth growth across the two subsequences.
