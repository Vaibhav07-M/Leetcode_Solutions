# 3499. Maximize Active Section with Trade I

**Difficulty:** `Medium`  
**Tags:** `String`, `Greedy`, `Simulation`, `Run-Length Encoding`

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

[LeetCode – 3499. Maximize Active Section with Trade I](https://leetcode.com/problems/maximize-active-section-with-trade-i/)

---

## Problem Summary

Given a binary string `s`, you may perform **at most one trade**:

1. Convert a contiguous block of `'1'`s that is surrounded by `'0'`s into `'0'`s.
2. Then convert a contiguous block of `'0'`s that is surrounded by `'1'`s into `'1'`s.

Treat the string as if it were augmented with `'1'` at both ends. Return the maximum possible number of active (`'1'`) sections after the optimal trade. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
s = "01"
```

**Output**

```text
1
```

---

### Example 2

**Input**

```text
s = "0100"
```

**Output**

```text
4
```

---

### Example 3

**Input**

```text
s = "1000100"
```

**Output**

```text
7
```

---

## Intuition

The added `'1'`s at both ends simplify handling boundary cases.

Compress the augmented string into consecutive runs of `'0'`s and `'1'`s.

For every removable `'1'` run that lies between two `'0'` runs:

- Remove that `'1'` block.
- The adjacent `'0'` runs merge into one larger zero block.
- That merged zero block can then be converted entirely into `'1'`s.

The best trade is obtained by checking every such middle `'1'` run.

---

## Approach

1. Count the initial number of active sections (`'1'`s).
2. Augment the string by adding `'1'` to both ends.
3. Perform **Run-Length Encoding (RLE)** to obtain alternating runs.
4. Iterate through every interior `'1'` run.
5. Compute:
   - length of the removable `'1'` run,
   - combined length of its neighboring `'0'` runs.
6. Update the maximum active count after performing the trade.
7. Return the maximum value found.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        for (char c : s) ones += (c == '1');

        string t = "1" + s + "1";
        int m = t.size();

        vector<pair<char,int>> runs;
        for (int i = 0; i < m; ) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int ans = ones;

        for (int i = 2; i + 2 < runs.size(); i += 2) {
            if (runs[i].first != '1') continue;

            int oneLen = runs[i].second;
            int zeroLen = runs[i - 1].second + runs[i + 1].second;

            ans = max(ans, ones - oneLen + zeroLen + oneLen);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Augmenting the string with `'1'`s removes boundary edge cases.
- Run-Length Encoding (RLE) simplifies processing consecutive blocks.
- Only `'1'` runs surrounded by `'0'` runs are valid candidates for removal.
- The neighboring zero runs merge after removing the middle one run, maximizing the possible gain.
- The entire solution runs in **O(n)** time by scanning the string only once after building the runs.