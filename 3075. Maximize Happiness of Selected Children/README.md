# 3075. Maximize Happiness of Selected Children

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Sorting`

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

[LeetCode — 3075. Maximize Happiness of Selected Children](https://leetcode.com/problems/maximize-happiness-of-selected-children/)

---

## Problem Summary

You are given an array `happiness` where `happiness[i]` represents the happiness value of the `i-th` child.  
You must select exactly `k` children one by one.  
After each selection, the happiness of every unselected child decreases by `1`, but never goes below `0`.

Return the **maximum total happiness** you can achieve by selecting `k` children.

---

## Examples

### Example 1
**Input:** `happiness = [1,2,3], k = 2`  
**Output:** `4`  
**Explanation:**
- Pick 3 → remaining becomes [0,1]
- Pick 1 → remaining becomes [0]
- Total = 3 + 1 = 4

### Example 2
**Input:** `happiness = [1,1,1,1], k = 2`  
**Output:** `1`  
**Explanation:**
- Pick 1 → remaining becomes [0,0,0]
- Pick 0 → remaining stays [0]
- Total = 1

### Example 3
**Input:** `happiness = [2,3,4,5], k = 1`  
**Output:** `5`

---

## Intuition

To maximize total happiness, it's best to pick children starting from the ones with the highest happiness.  
Each time we select a child, all remaining children's happiness decreases by `1`, so future values get worse.  
Sorting in descending order ensures we pick the largest values early before they lose value due to decrements.

---

## Approach

1. **Sort `happiness` in descending order** so high values are picked first.
2. **Pick the first `k` children**, where:
   - Each selection causes a happiness reduction equal to the number of children already picked.
   - So for the `i-th` picked child, effective happiness becomes `max(happiness[i] - i, 0)`
3. Sum these adjusted values and return the result.

This greedy approach guarantees maximum happiness.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — due to sorting |
| **Space** | `O(1)` extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += max(happiness[i] - i, 0);
        }

        return sum;
    }
};
```

---

## Key Takeaways

- Picking the largest values first reduces loss from future decrements.
- Greedy + Sorting is often useful where values degrade over time.
- Track cumulative effects using index-based adjustments.
