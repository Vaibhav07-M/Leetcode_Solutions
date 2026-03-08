# 1980. Find Unique Binary String

**Difficulty:** `Medium`  
**Tags:** `Array`, `String`, `Backtracking`

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

[LeetCode — 1980. Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string/)

---

## Problem Summary

Given an array of strings `nums` containing `n` unique binary strings, each of length `n`, return a binary string of length `n` that does not appear in `nums`. If there are multiple valid answers, any of them can be returned.

Constraints:
- `n == nums.length`
- `1 <= n <= 16`
- `nums[i].length == n`
- `nums[i]` is either `'0'` or `'1'`.
- All strings in `nums` are unique.

---

## Examples

### Example 1
**Input:** `nums = ["01","10"]`  
**Output:** `"11"`  
**Explanation:** `"11"` does not appear in `nums`. `"00"` would also be correct.

### Example 2
**Input:** `nums = ["00","01"]`  
**Output:** `"11"`  
**Explanation:** `"11"` does not appear in `nums`. `"10"` would also be correct.

### Example 3
**Input:** `nums = ["111","011","001"]`  
**Output:** `"101"`  
**Explanation:** `"101"` does not appear in `nums`. `"000"`, `"010"`, `"100"`, and `"110"` would also be correct.

---

## Intuition

Since we need to construct a binary string of length `n` that is different from all `n` given binary strings of length `n`, we can use **Cantor's Diagonalization** argument.
The idea is to guarantee that the new string differs from the $i$-th string in `nums` at the $i$-th character. By flipping the $i$-th character of the $i$-th string, our new string is mathematically guaranteed to differ from every string in the array by at least one character. 

---

## Approach

1. Initialize an empty string `ans`.
2. Loop through `nums` from index `0` to `n - 1`.
3. For each index `i`, check the $i$-th character of the $i$-th string (`nums[i][i]`).
4. If it's `'0'`, append `'1'` to `ans`. If it's `'1'`, append `'0'` to `ans`.
5. Return the constructed string `ans`.

This elegant approach constructs a valid string directly without needing to generate all possible binary permutations or convert strings to integers.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — we iterate exactly `n` times, checking a single character each time |
| **Space** | `O(1)` — ignoring the space needed to store and return the answer string |

---

## Code (C++)

```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";

        for(int i = 0; i < n; i++) {
            if(nums[i][i] == '0')
                ans += '1';
            else
                ans += '0';
        }

        return ans;
    }
};
```

---

## Key Takeaways

- **Cantor's Diagonalization** is a classic technique from set theory that finds elegant applicability in generating uniquely differing elements.
- When generating a completely missing item out of exactly $n$ slots with length $n$, ensuring a difference at precisely one distinct index per existing item guarantees a missing result optimally.
