# 3518. Smallest Palindromic Rearrangement II

**Difficulty:** `Hard`  
**Tags:** `String`, `Greedy`, `Combinatorics`, `Math`, `Counting`, `Backtracking`

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

[LeetCode – 3518. Smallest Palindromic Rearrangement II](https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/)

---

## Problem Summary

You are given a **palindromic** string `s` and an integer `k`.

Return the **k-th lexicographically smallest distinct palindromic permutation** of `s`. If fewer than `k` distinct palindromic permutations exist, return an empty string. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
s = "abba", k = 2
```

**Output**

```text
"baab"
```

---

### Example 2

**Input**

```text
s = "aa", k = 2
```

**Output**

```text
""
```

---

### Example 3

**Input**

```text
s = "bacab", k = 1
```

**Output**

```text
"abcba"
```

---

## Intuition

Every palindrome is uniquely determined by:

- its left half,
- an optional middle character,
- and the mirrored right half.

Instead of generating every palindrome, we greedily construct the left half one character at a time.

For every candidate character:

- temporarily place it,
- count how many valid palindromes can still be formed,
- if that count is at least `k`, keep the character,
- otherwise skip all those permutations by subtracting their count from `k` and try the next character.

The number of possible left-half arrangements is computed using multinomial coefficients.

---

## Approach

1. Count the frequency of every character.
2. Build:
   - `half[i] = frequency[i] / 2`
   - the middle character (if any).
3. Compute the total number of distinct left-half permutations.
   - If it is less than `k`, return an empty string.
4. Construct the left half greedily:
   - Try every character from `'a'` to `'z'`.
   - Decrease its count.
   - Count the remaining permutations.
   - If enough permutations remain, keep the character.
   - Otherwise restore the count and decrease `k`.
5. Mirror the left half and insert the middle character.

---

## Complexity

Let:

- `n` = length of the string
- `m = n / 2`

| Metric | Complexity |
|---------|------------|
| **Time** | `O(26 × m²)` |
| **Space** | `O(26)` |

Since the alphabet size is fixed (26 lowercase letters), the solution is efficient even for the given constraints.

---

## Code (C++)

```cpp
class Solution {
public:
    static const int LIM = 1000000;

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > LIM) return LIM + 1;
        }
        return min(res, (long long)LIM + 1);
    }

    long long countWays(vector<int>& cnt) {
        int tot = 0;
        for (int x : cnt) tot += x;

        long long ways = 1;
        int rem = tot;

        for (int x : cnt) {
            if (x == 0) continue;
            ways *= C(rem, x);
            if (ways > LIM) return LIM + 1;
            rem -= x;
        }
        return min(ways, (long long)LIM + 1);
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string mid = "";
        vector<int> half(26, 0);

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k) return "";

        string left = "";
        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
```

---

## Key Takeaways

- A palindrome is completely determined by its left half and optional middle character.
- Count distinct left-half arrangements using multinomial coefficients instead of generating every permutation.
- Greedily build the answer from left to right by checking how many permutations begin with each possible character.
- Skip entire groups of permutations by subtracting their count from `k`.
- Capping combination values at `10⁶ + 1` prevents overflow while still allowing correct comparisons with `k`.