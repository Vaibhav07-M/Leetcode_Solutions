# 3946. Maximum Number of Items From Sale I

**Difficulty:** `Medium`  
**Tags:** `Array`, `Dynamic Programming`, `Greedy`

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

[LeetCode — 3946. Maximum Number of Items From Sale I](https://leetcode.com/problems/maximum-number-of-items-from-sale-i/)

---

## Problem Summary

The problem involves maximizing the number of item copies obtained within a given budget, where purchasing one copy of an item grants free copies of other items whose factors are divisible by the purchased item's factor. The solution uses dynamic programming to calculate the maximum number of free copies that can be earned for each possible spending amount, and then determines the optimal distribution of the remaining budget to maximize the total count.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to treat the problem as a knapsack-like optimization where the 'value' is the number of free copies earned. By iterating through the items and updating a dynamic programming array `f` to store the maximum free copies for each budget level, we can efficiently determine the best combination of purchases. The final step involves using the remaining budget to buy the cheapest available item to further increase the total count.

---

## Approach

1. Initialize a dynamic programming array `f` of size `budget + 1`, where `f[i]` represents the maximum number of free copies that can be earned by spending up to `i` units of budget.
2. Iterate through each item in the `items` list. For each item, calculate the number of other items (`cnt`) whose factors are divisible by the current item's factor, as these will be the free copies earned.
3. Update the `f` array using a bottom-up approach. For each budget value `j` from `price` to `budget`, update `f[j]` to be the maximum of its current value and the value at `f[j - price]` plus the number of free copies (`cnt`) earned by purchasing this item.
4. After processing all items, calculate the final answer. For each possible spending amount `i`, add the number of free copies earned (`f[i]`) to the number of additional copies that can be bought with the remaining budget (`(budget - i) / mn`, where `mn` is the minimum price found).
5. Return the maximum value found in the previous step as the optimal solution.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(N * budget)` — The algorithm iterates through N items and for each item, it updates the dynamic programming array over the range of the budget (up to budget). This results in a time complexity of O(N * budget). |
| **Space** | `O(budget)` — The space complexity is dominated by the dynamic programming array `f`, which requires storage proportional to the budget size. Other variables use constant space. |

---

## Code (C++)

```cpp
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> f(budget + 1, 0);
        int mn = INT_MAX;

        for (const auto& item : items) {
            int factor = item[0];
            int price = item[1];

            mn = min(mn, price);

            int cnt = 0;
            for (const auto& jItem : items) {
                if (jItem[0] % factor == 0) {
                    cnt++;
                }
            }

            for (int j = budget; j >= price; --j) {
                f[j] = max(f[j], f[j - price] + cnt);
            }
        }

        int ans = 0;
        for (int i = 0; i <= budget; ++i) {
            ans = max(ans, f[i] + (budget - i) / mn);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The solution effectively models the problem of earning free items as a dynamic programming optimization over the spending budget.
- It highlights the importance of identifying the 'cheapest' item (minimum price) to utilize the remaining budget efficiently after maximizing free copies.
- The approach demonstrates how to combine direct purchases with earned bonuses to maximize the total yield.
