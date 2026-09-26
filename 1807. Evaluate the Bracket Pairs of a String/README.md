# 1807. Evaluate the Bracket Pairs of a String

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `String`

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

[LeetCode — 1807. Evaluate the Bracket Pairs of a String](https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/)

---

## Problem Summary

The problem involves evaluating a string with bracketed placeholders (keys) by replacing them with corresponding values from a provided knowledge base. If a key is not found, it is replaced with a '?'. The goal is to return the fully evaluated string.

---

## Examples

### Example 1
**Input:** `s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]`  
**Output:** `"bobistwoyearsold"`  
**Explanation:**
- The key "name" has a value of "bob", so replace "(name)" with "bob".
- The key "age" has a value of "two", so replace "(age)" with "two".

### Example 2
**Input:** `s = "hi(name)", knowledge = [["a","b"]]`  
**Output:** `"hi?"`  
**Explanation:**
- As you do not know the value of the key "name", replace "(name)" with "?".

### Example 3
**Input:** `s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]`  
**Output:** `"yesyesyesaaa"`  
**Explanation:**
- The same key can appear multiple times.
- The key "a" has a value of "yes", so replace all occurrences of "(a)" with "yes".
- Notice that the "a"s not in a bracket pair are not evaluated.

---

## Intuition

The solution uses a hash map to store the key-value pairs from the knowledge array for fast lookup. It then iterates through the input string, identifying bracket pairs and extracting the keys. Each key is checked against the hash map to determine the replacement value, ensuring efficient evaluation of the string.

---

## Approach

1. Create an unordered map to store the key-value pairs from the knowledge array.
2. Iterate through the input string character by character.
3. If a character is not a '(', append it to the answer string.
4. If a '(' is encountered, find the corresponding ')' to extract the key.
5. Check if the extracted key exists in the hash map; if so, append the value, otherwise append '?'.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + m)` — The time complexity is linear relative to the total length of the input string (n) and the number of key-value pairs in the knowledge array (m). The iteration over the string is O(n), and the initial population of the hash map is O(m). |
| **Space** | `O(m)` — The space complexity is determined by the size of the hash map, which stores all the key-value pairs from the knowledge array. The input string is processed in-place without significant additional storage. |

---

## Code (C++)

```cpp
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;

        // Store key -> value
        for (auto& item : knowledge) {
            mp[item[0]] = item[1];
        }

        string answer;

        for (int i = 0; i < s.size(); i++) {

            // Normal character
            if (s[i] != '(') {
                answer += s[i];
            }

            // Bracket pair
            else {
                int j = i + 1;

                // Find closing bracket
                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Check if key exists
                if (mp.find(key) != mp.end()) {
                    answer += mp[key];
                }
                else {
                    answer += "?";
                }

                // Move past ')'
                i = j;
            }
        }

        return answer;
    }
};
```

---

## Key Takeaways

- Hash maps are an efficient data structure for fast key-value lookups in string evaluation problems.
- Iterative parsing of a string can effectively handle nested or structured data (like bracket pairs) by tracking state.
