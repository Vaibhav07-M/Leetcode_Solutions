# 3789. Minimum Cost to Acquire Required Items

**Difficulty:** `Medium`  
**Tags:** `Math`, `Greedy`

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

[LeetCode — 3789. Minimum Cost to Acquire Required Items](https://leetcode.com/problems/minimum-cost-to-acquire-required-items/)

---

## Problem Summary

The problem involves purchasing items of three types (1, 2, and 3) to meet specific requirements for type 1 and type 2 contributions. The goal is to minimize the total cost while ensuring the contributions satisfy the given needs. The solution evaluates three different purchasing strategies to determine the most cost-effective approach.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to compare the cost of purchasing items separately versus purchasing them in combination. The solution calculates the cost for three scenarios: buying only individual items, buying a mix of individual and combined items, and buying only combined items. By evaluating these options, the algorithm identifies the minimum cost required to fulfill the specified needs.

---

## Approach

1. Calculate the cost of purchasing items separately (Option 1) by multiplying the number of needed type 1 items by cost1 and the number of needed type 2 items by cost2.
2. Determine the cost of a hybrid approach (Option 2) where the minimum of need1 and need2 is purchased as type 3 items, and the remaining requirements are filled with individual items.
3. Compute the cost of purchasing only combined items (Option 3) by multiplying the maximum of need1 and need2 by costBoth.
4. Compare the three calculated costs and return the minimum value as the optimal solution.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(1)` — The solution involves a constant number of arithmetic operations to calculate the costs of the three options and compare them, resulting in a time complexity of O(1). |
| **Space** | `O(1)` — The algorithm uses a fixed number of variables to store the costs and requirements, with no dynamic data structures or recursion, leading to a space complexity of O(1). |

---

## Code (C++)

```cpp
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        // Option 1: Buy only separate items
        long long option1 =
            1LL * need1 * cost1 +
            1LL * need2 * cost2;

        // Option 2: Buy type 3 items for both requirements
        long long both = min(need1, need2);

        long long option2 =
            both * costBoth +
            1LL * (need1 - both) * cost1 +
            1LL * (need2 - both) * cost2;

        // Option 3: Buy type 3 items for the larger requirement
        long long option3 =
            1LL * max(need1, need2) * costBoth;

        return min({option1, option2, option3});
    }
};
```

---

## Key Takeaways

- The problem demonstrates the application of a greedy algorithm to minimize cost by comparing discrete purchasing options.
- It highlights the importance of considering both individual and combined resource allocation strategies in optimization problems.
- The solution effectively utilizes the min and max functions to determine the most efficient distribution of item types.
