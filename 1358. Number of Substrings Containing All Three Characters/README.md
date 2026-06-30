# 1358. Number of Substrings Containing All Three Characters

**Difficulty:** `Medium`  
**Tags:** `String`, `Sliding Window`, `Two Pointers`

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

[LeetCode — 1358. Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)

---

## Problem Summary

You are given a string `s` consisting only of the characters:

```text
'a', 'b', and 'c'
```

Return the number of substrings that contain **at least one occurrence** of each of the three characters.

---

## Examples

### Example 1

**Input:**

```cpp
s = "abcabc"
```

**Output:**

```cpp
10
```

**Explanation:**

There are 10 substrings that contain at least one `'a'`, one `'b'`, and one `'c'`.

---

### Example 2

**Input:**

```cpp
s = "aaacb"
```

**Output:**

```cpp
3
```

**Explanation:**

The valid substrings are:

```text
"aaacb"
"aacb"
"acb"
```

---

### Example 3

**Input:**

```cpp
s = "abc"
```

**Output:**

```cpp
1
```

---

## Intuition

Since we need substrings containing all three characters, a **sliding window** is ideal.

Expand the right end of the window until all three characters are present.

Once the current window is valid:

- Every longer substring starting at the current left pointer is also valid.
- Therefore, if the window ends at index `right`, then there are:

```cpp
s.size() - right
```

valid substrings starting from the current `left`.

Then shrink the window from the left while it remains valid.

---

## Approach

1. Maintain a sliding window using two pointers:
   - `left`
   - `right`
2. Keep a frequency array for `'a'`, `'b'`, and `'c'`.
3. Expand the window by moving `right`.
4. Whenever all three frequencies become positive:
   - Add:
     ```cpp
     s.size() - right
     ```
     to the answer.
   - Remove the leftmost character.
   - Move `left` forward.
5. Continue until the entire string has been processed.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt(3, 0);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            cnt[s[right] - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += s.size() - right;
                cnt[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Use a sliding window to maintain a valid substring.
- Count character frequencies inside the current window.
- Once all three characters are present, every extension to the right is also valid.
- Add `n - right` valid substrings at once instead of checking each individually.
- The solution runs in `O(n)` time with `O(1)` extra space.