# 2213. Longest Substring of One Repeating Character

**Difficulty:** `Hard`  
**Tags:** `Segment Tree`

---

## Table of Contents

- [Problem Link](#problem-link)
- [Problem Summary](#problem-summary)
- [Examples](#examples)
- [Intuition](#intuition)
- [Approach](#approach)
- [Complexity](#complexity)
- [Code (C++)](#code-c)
- [Why This Works](#why-this-works)
- [Key Takeaways](#key-takeaways)

---

## Problem Link

https://leetcode.com/problems/longest-substring-of-one-repeating-character/

---

## Problem Summary

You are given a string `s` and a sequence of character updates.

For each query:

- Change the character at a given index.
- After the change, find the length of the longest substring consisting of only one repeating character.

Return the answer after every query.

---

## Examples

### Example

**Input**

```text
s = "babacc"
queryCharacters = "bcb"
queryIndices = [1,3,3]
```

**Output**

```text
[3,3,4]
```

After each character update, the longest substring containing the same character is calculated.

---

## Intuition

The string changes after every query, so checking the entire string after every update would be inefficient.

A **Segment Tree** allows us to:

1. Build information about every part of the string.
2. Update one character in `O(log n)`.
3. Store the longest repeating substring for every segment.
4. Get the answer for the complete string from the root.

For each segment, we need to know:

- `pre` → longest repeating prefix.
- `suf` → longest repeating suffix.
- `maxLen` → longest repeating substring anywhere in the segment.
- `leftChar` → first character of the segment.
- `rightChar` → last character of the segment.

---

## Approach

### Step 1

Create a `Node` structure.

```cpp
struct Node {
    int pre;
    int suf;
    int maxLen;
    char leftChar;
    char rightChar;
};
```

These values describe the repeating-character information for each segment.

---

### Step 2

Build the Segment Tree.

For a single character:

```text
pre = 1
suf = 1
maxLen = 1
leftChar = character
rightChar = character
```

For example:

```text
"a"
```

has:

```text
pre = 1
suf = 1
maxLen = 1
leftChar = 'a'
rightChar = 'a'
```

---

### Step 3

Merge two child nodes.

Suppose the segment is divided into:

```text
Left Segment | Right Segment
```

The first and last characters are:

```text
Left:  ... L.rightChar
Right: R.leftChar ...
```

If

```text
L.rightChar == R.leftChar
```

the repeating sequences can connect across the boundary.

Therefore:

```text
L.suf + R.pre
```

can form a longer repeating substring.

---

### Step 4

Calculate the prefix.

Normally:

```cpp
res.pre = L.pre;
```

But if the entire left segment is the same character and its last character matches the first character of the right segment:

```cpp
if (L.pre == leftLen && L.rightChar == R.leftChar)
    res.pre = L.pre + R.pre;
```

Then the repeating prefix extends into the right segment.

---

### Step 5

Calculate the suffix.

Similarly:

```cpp
res.suf = R.suf;
```

If the entire right segment is the same character and its first character matches the last character of the left segment:

```cpp
if (R.suf == rightLen && L.rightChar == R.leftChar)
    res.suf = R.suf + L.suf;
```

Then the repeating suffix extends into the left segment.

---

### Step 6

Calculate the maximum repeating substring.

The answer can be:

- Completely inside the left segment.
- Completely inside the right segment.
- Crossing the boundary.

Therefore:

```cpp
res.maxLen = max(L.maxLen, R.maxLen);
```

and if the boundary characters match:

```cpp
res.maxLen = max(res.maxLen, L.suf + R.pre);
```

---

### Step 7

Process each query.

For every query:

```text
index = queryIndices[i]
character = queryCharacters[i]
```

Update that position in the Segment Tree.

After the update:

```cpp
segTree[0].maxLen
```

contains the answer because the root represents the entire string.

---

## Complexity

Let:

- `n` = length of the string.
- `q` = number of queries.

| Operation | Complexity |
|-----------|------------|
| **Build Segment Tree** | `O(n)` |
| **Each Update** | `O(log n)` |
| **All Queries** | `O(q log n)` |
| **Space** | `O(n)` |

Overall:

```text
Time:  O(n + q log n)
Space: O(n)
```

---

## Code (C++)

```cpp
class Solution {
public:
    struct Node {
        int pre = 0;
        int suf = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    vector<Node> segTree;

    Node merge(const Node& L, const Node& R, int leftLen, int rightLen) {
        Node res;

        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        res.pre = L.pre;
        if (L.pre == leftLen && L.rightChar == R.leftChar) {
            res.pre = L.pre + R.pre;
        }

        res.suf = R.suf;
        if (R.suf == rightLen && L.rightChar == R.leftChar) {
            res.suf = R.suf + L.suf;
        }

        res.maxLen = max(L.maxLen, R.maxLen);

        if (L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }

    void buildSegmentTree(int i, int l, int r, string& s) {
        if (l == r) {
            segTree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);

        segTree[i] = merge(
            segTree[2 * i + 1],
            segTree[2 * i + 2],
            mid - l + 1,
            r - mid
        );
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) {
            segTree[i] = {1, 1, 1, ch, ch};
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }

        segTree[i] = merge(
            segTree[2 * i + 1],
            segTree[2 * i + 2],
            mid - l + 1,
            r - mid
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        n = s.size();

        segTree.assign(4 * n, Node());

        buildSegmentTree(0, 0, n - 1, s);

        int k = queryIndices.size();
        vector<int> result(k);

        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(0, 0, n - 1, pos, ch);

            result[i] = segTree[0].maxLen;
        }

        return result;
    }
};
```

---

## Why This Works

Consider a segment divided into:

```text
aaaa | aabb
```

The left segment has:

```text
suffix = "aaaa"
```

and the right segment has:

```text
prefix = "aa"
```

Since:

```text
left.rightChar == right.leftChar == 'a'
```

they can be combined:

```text
aaaa + aa = aaaaaa
```

Therefore:

```cpp
L.suf + R.pre
```

correctly represents the longest repeating substring crossing the boundary.

The Segment Tree stores this information at every level. When one character changes, only the nodes on the path from that character to the root need to be recalculated.

Thus, after every update, the root's `maxLen` gives the longest repeating substring of the entire string.

---

## Key Takeaways

- Use a **Segment Tree** when the string is repeatedly updated and range information is needed.
- Each node stores:
  - Longest repeating prefix.
  - Longest repeating suffix.
  - Longest repeating substring.
  - First character.
  - Last character.
- Two adjacent segments can be combined when their boundary characters are equal.
- A single character update takes **O(log n)**.
- The root always contains the answer for the complete string.
- Overall complexity is **O(n + q log n)**.