# 2144. Minimum Cost of Buying Candies With Discount

**Difficulty:** `Easy`  
**Tags:** `Greedy`, `Sorting`

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

[LeetCode — 2144. Minimum Cost of Buying Candies With Discount](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/)

---

## Problem Summary

Given an integer array `cost` where `cost[i]` denotes the cost of the `i-th` candy, the shop offers a deal: for every two candies you buy, you get a third candy for free, provided the free candy's cost is less than or equal to the minimum of the two purchased candies.

Return the minimum cost to buy all the candies.

---

## Examples

### Example 1
**Input:** `cost = [1,2,3]`  
**Output:** `5`  
**Explanation:** Buy 2 and 3, get 1 free → total = 2 + 3 = 5.

### Example 2
**Input:** `cost = [6,5,7,9,2,2]`  
**Output:** `23`  
**Explanation:** Buy (9,7) get 6, buy (5,2) get 2 free → total = 9+7+5+2 = 23.

---

## Intuition

To minimize cost, pay for the most expensive candies and try to get cheaper candies for free. Sorting in descending order and taking groups of three ensures the cheapest in every triple becomes free.

---

## Approach

1. Sort `cost` in descending order.
2. Iterate over `cost` and sum every first and second element in each group of three; skip every third element (it counts as free).
3. Return the total sum.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — sorting |
| **Space** | `O(1)` extra |

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int n = cost.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 3 != 2) ans += cost[i];
        }
        return ans;
    }
};
```

---

## Key Takeaways

- Sort descending and skip every third candy.
- Greedy grouping by descending costs minimizes paid total.
