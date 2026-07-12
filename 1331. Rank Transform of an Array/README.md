# 1331. Rank Transform of an Array

**Difficulty:** `Easy`  
**Tags:** `Array`, `Sorting`, `Hash Table`

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

[LeetCode — 1331. Rank Transform of an Array](https://leetcode.com/problems/rank-transform-of-an-array/)

---

## Problem Summary

Given an integer array `arr`, replace every element with its **rank**.

The ranking rules are:

- Rank starts from `1`.
- Larger values receive larger ranks.
- Equal values receive the same rank.
- Ranks should be as small as possible.

Return the transformed array.

---

## Examples

### Example 1

**Input:** `arr = [40,10,20,30]`  
**Output:** `[4,1,2,3]`

**Explanation:**

- `10` → Rank `1`
- `20` → Rank `2`
- `30` → Rank `3`
- `40` → Rank `4`

---

### Example 2

**Input:** `arr = [100,100,100]`  
**Output:** `[1,1,1]`

---

### Example 3

**Input:** `arr = [37,12,28,9,100,56,80,5,12]`  
**Output:** `[5,3,4,2,8,6,7,1,3]`

---

## Intuition

The rank of an element depends only on its position in the sorted order of **distinct values**.

We first sort a copy of the array and assign increasing ranks to each unique value. Then, using a hash table, we replace every original element with its assigned rank.

---

## Approach

1. Create a sorted copy of the input array.
2. Sort the copied array in ascending order.
3. Traverse the sorted array and assign ranks only to unique values using a hash map.
4. Traverse the original array and replace each element with its corresponding rank.
5. Return the transformed array.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — due to sorting |
| **Space** | `O(n)` — for the sorted copy and hash map |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int x : sorted) {
            if (!rank.count(x))
                rank[x] = r++;
        }

        vector<int> ans;
        for (int x : arr)
            ans.push_back(rank[x]);

        return ans;
    }
};
```

---

## Key Takeaways

- Sorting unique values naturally determines their ranks.
- A hash table provides constant-time lookup for replacing elements.
- Equal elements automatically receive the same rank.
- Separating sorting from reconstruction keeps the solution simple and efficient.
```