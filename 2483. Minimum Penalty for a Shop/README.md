# 2483. Minimum Penalty for a Shop

**Difficulty:** `Medium`  
**Tags:** `String`, `Prefix Sum`

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

[LeetCode — 2483. Minimum Penalty for a Shop](https://leetcode.com/problems/minimum-penalty-for-a-shop/)

---

## Problem Summary

You are given a customer visit log of a shop represented by a 0-indexed string `customers` consisting only of characters `'N'` and `'Y'`:
- `'Y'` means customers come at that hour
- `'N'` means no customers come at that hour

If the shop closes at the `j-th` hour (0 <= j <= n), the penalty is:
- **+1** for every hour the shop is **open** and **no customers come** ('N')
- **+1** for every hour the shop is **closed** and **customers come** ('Y')

Return the **earliest hour** at which the shop must be closed to incur a **minimum penalty**.

---

## Examples

### Example 1
**Input:** `customers = "YYNY"`  
**Output:** `2`  
**Explanation:**
- Close at hour 0 → penalty = 1+1+0+1 = 3
- Close at hour 1 → penalty = 0+1+0+1 = 2
- Close at hour 2 → penalty = 0+0+0+1 = 1 (minimum)
- Close at hour 3 → penalty = 0+0+1+1 = 2
- Close at hour 4 → penalty = 0+0+1+0 = 1
- Earliest minimum is hour 2

### Example 2
**Input:** `customers = "NNNNN"`  
**Output:** `0`  
**Explanation:**
- No customers arrive, so close immediately at hour 0

### Example 3
**Input:** `customers = "YYYY"`  
**Output:** `4`  
**Explanation:**
- Customers arrive every hour, so keep open all day (close at hour 4)

---

## Intuition

Instead of recalculating penalty for each possible closing time, we can track how the penalty **changes** as we move the closing time forward.

Starting with closing at hour 0 (all 'Y's after closing count as penalty), as we move closing time forward:
- If we encounter 'Y' → penalty **decreases** (we're now open when customer arrives)
- If we encounter 'N' → penalty **increases** (we're now open when no customer arrives)

This allows us to find the minimum penalty in one pass through the string.

---

## Approach

1. **Calculate initial penalty** for closing at hour 0:
   - Count all 'Y's in the string (these all count as missed customers)
   
2. **Iterate through each hour** and update penalty dynamically:
   - If `customers[i] == 'Y'` → penalty decreases (one less missed customer)
   - If `customers[i] == 'N'` → penalty increases (one more wasted open hour)
   
3. **Track minimum penalty** and the earliest hour that achieves it

4. **Return the hour** with minimum penalty

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass through the string |
| **Space** | `O(1)` — only constant extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    int bestClosingTime(string customers) {
        int size = customers.size();
        int penalty = 0;

        // Initial penalty: closing at hour 0 (all Y's count)
        for (char it : customers) {
            if (it == 'Y') penalty++;
        }

        int minpenalty = penalty;
        int hr = 0;

        // Try moving closing time forward
        for (int i = 0; i < size; i++) {
            if (customers[i] == 'Y') penalty--;  // One less missed customer
            else penalty++;                       // One more wasted open hour
            
            if (penalty < minpenalty) {
                minpenalty = penalty;
                hr = i + 1;  // Closing after this hour
            }
        }
        return hr;
    }
};
```

---

## Key Takeaways

- Instead of brute force, track how penalty changes as closing time shifts forward.
- Prefix sum thinking helps optimize problems with cumulative calculations.
- Greedy iteration can replace nested loops when transitions are predictable.
