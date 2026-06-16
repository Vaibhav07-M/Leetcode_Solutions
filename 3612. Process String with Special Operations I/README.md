# 3612. Process String with Special Operations I

**Difficulty:** `Medium`  
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

[LeetCode — 3612. Process String with Special Operations I](https://leetcode.com/problems/process-string-with-special-operations-i/)

---

## Problem Summary

You are given a string `s` consisting of lowercase English letters and the special characters:

- `'*'` → Remove the last character from the current result (if it exists).
- `'#'` → Duplicate the current result and append it to itself.
- `'%'` → Reverse the current result.

Process the string from left to right and build a new string called `result`.

Return the final string after all operations have been applied. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1
**Input:** `s = "a#b%*"`  
**Output:** `"ba"`

**Explanation:**

| Character | Operation | Result |
|------------|------------|----------|
| `a` | Append | `"a"` |
| `#` | Duplicate | `"aa"` |
| `b` | Append | `"aab"` |
| `%` | Reverse | `"baa"` |
| `*` | Remove last character | `"ba"` |

Final result = `"ba"` :contentReference[oaicite:1]{index=1}

### Example 2
**Input:** `s = "z*#"`  
**Output:** `""`

**Explanation:**

| Character | Operation | Result |
|------------|------------|----------|
| `z` | Append | `"z"` |
| `*` | Remove last character | `""` |
| `#` | Duplicate | `""` |

Final result = `""` :contentReference[oaicite:2]{index=2}

---

## Intuition

The problem directly describes how to build the final string.

We simply maintain a string `result` and process each character one by one:

- Letters are appended.
- `'*'` removes the last character if possible.
- `'#'` doubles the current string.
- `'%'` reverses the current string.

Since the operations must be applied in order, a straightforward simulation works perfectly.

---

## Approach

1. Initialize an empty string `result`.
2. Traverse each character in `s`.
3. For every character:
   - If it is a lowercase letter, append it to `result`.
   - If it is `'*'`, remove the last character if `result` is not empty.
   - If it is `'#'`, append `result` to itself.
   - If it is `'%'`, reverse `result`.
4. After processing all characters, return `result`.

This directly follows the operations defined in the problem statement.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n × m)` in the worst case due to duplication and reversal operations |
| **Space** | `O(m)` where `m` is the length of the final string |

---

## Code (C++)

```cpp
class Solution {
public:
    string processStr(string s) {

        string result;

        for(char ch : s) {

            if(ch >= 'a' && ch <= 'z') {
                result.push_back(ch);
            }
            else if(ch == '*') {

                if(!result.empty())
                    result.pop_back();
            }
            else if(ch == '#') {

                result += result;
            }
            else if(ch == '%') {

                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};
```

---

## Key Takeaways

- This is a pure simulation problem.
- Maintain a running string and apply operations immediately.
- String operations such as append, pop, duplicate, and reverse are enough to solve the problem.
- Carefully handle the `'*'` operation when the string is empty.