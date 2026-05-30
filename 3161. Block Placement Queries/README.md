# 3161. Block Placement Queries

**Difficulty:** `Hard`  
**Tags:** `Ordered Set`, `Array`, `Binary Search` 

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

[LeetCode — 3161. Block Placement Queries](https://leetcode.com/problems/block-placement-queries/)

---

## Problem Summary

You process two types of queries on an infinite non-negative number line:
- Type 1: add an obstacle at position `x` (guaranteed not present already).
- Type 2: given `(x, sz)`, determine whether there exists a contiguous block of length `sz` that lies entirely inside `[0, x]` and does not intersect any obstacle (touching obstacles is allowed).

Return a boolean result for each type-2 query.

---

## Examples

### Example 1
Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

Output: [false,true,true]

### Example 2
Input: queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

Output: [true,true,false]

---

## Intuition

A placement is possible if some gap (contiguous obstacle-free interval) of length at least `sz` exists within `[0, x]`. Maintain the set of obstacle positions and track the lengths of gaps between adjacent obstacles (including the segment from 0 to the first obstacle and from the last obstacle to +infinity). For queries restricted to `[0,x]` we only need to consider gaps that intersect that prefix.

---

## Approach

1. Maintain a sorted set of obstacle positions (e.g. `std::set<int>`).
2. Maintain a multiset (or balanced BST) of gap lengths between consecutive obstacles.
3. On inserting an obstacle at `p`:
   - Find predecessor `a` and successor `b` in the set (if any).
   - Remove gap `(b - a)` (if both exist) from the multiset and add the new gaps `(p - a)` and `(b - p)` as appropriate.
4. For a type-2 query `(x, sz)`:
   - Consider the obstacles within `(0, x]` and the implicit boundary at `0`.
   - The largest gap that lies entirely inside `[0,x]` can be detected by inspecting the gaps that start before or at `x` (a careful implementation considers truncated gaps at `x`).
   - Simpler (and efficient): keep the set of obstacle positions, and for a query, locate the first obstacle > `x` and examine the previous obstacle to determine the largest contiguous free segment ending at or before `x`. Also check gaps between obstacles fully contained in `[0,x]` using an auxiliary structure storing gap lengths keyed by their starting position.

Implementation notes:
- Use `std::set<int>` for obstacles, `std::multiset<int>` for gap lengths, and a map from gap-start → gap-length if you need to query which gaps are inside `[0,x]` quickly.
- Time per insert: O(log n). Time per query: O(log n) with proper auxiliary indexes.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((Q + I) log N)` — each insert/query uses balanced-tree ops (Q = number of queries, I = number of inserts) |
| **Space** | `O(N)` for storing obstacles and gaps |

---

## Code (C++)

```cpp
// Sketch of data-structure operations (not full contest code)
#include <set>
#include <map>
#include <multiset>

class BlockPlacement {
    std::set<int> obs; // obstacle positions
    std::multiset<int> gaps; // gap lengths
public:
    void insert(int p) {
        if (obs.empty()) {
            obs.insert(p);
            gaps.insert(p); // gap [0, p)
            return;
        }
        auto it = obs.lower_bound(p);
        int r = (it==obs.end()? INT_MAX: *it);
        int l = (it==obs.begin()? 0: *std::prev(it));
        // remove old gap (r - l) if r != INT_MAX
        if (r != INT_MAX) {
            auto itg = gaps.find(r - l);
            if (itg!=gaps.end()) gaps.erase(itg);
            gaps.insert(p - l);
            gaps.insert(r - p);
        } else {
            // tail gap from l to +inf, represented by large sentinel or ignored
            gaps.insert(p - l);
        }
        obs.insert(p);
    }

    bool canPlace(int x, int sz) {
        // find first obstacle > x
        auto it = obs.upper_bound(x);
        int r = (it==obs.end()? INT_MAX: *it);
        int l = (it==obs.begin()? 0: *std::prev(it));
        // consider tail: [l, x]
        if (r==INT_MAX) {
            if ((long long)x - l >= sz) return true;
        } else {
            // gap [l, min(r,x)]
            if ((long long)std::min(r, x) - l >= sz) return true;
        }
        // Additionally, gaps fully inside [0,x] should be checked via auxiliary structure (omitted here)
        return false;
    }
};
```

---

## Key Takeaways

- Maintain obstacles in a sorted set and gaps in another structure to answer range-placement queries efficiently.
- Inserts and queries are both O(log n) with balanced BSTs.
- Careful handling of prefix queries `[0,x]` requires truncating gaps at `x`.
