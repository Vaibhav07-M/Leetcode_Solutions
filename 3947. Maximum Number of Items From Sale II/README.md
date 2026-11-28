# 3947. Maximum Number of Items From Sale II

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Sorting`, `Heap (Priority Queue)`

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

[LeetCode — 3947. Maximum Number of Items From Sale II](https://leetcode.com/problems/maximum-number-of-items-from-sale-ii/)

---

## Problem Summary

The problem involves maximizing the number of item copies obtained within a budget, where purchasing one copy of an item can yield free copies of other items if their factors are divisible. The solution employs a greedy approach to select items that provide the best value in terms of free copies relative to their cost.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to prioritize items that are both inexpensive and have a high potential to generate free copies. By identifying the cheapest item and calculating the frequency of its factor across all items, the algorithm can determine which purchases will yield the most copies for the least cost. The use of a map to track cost-to-count ratios allows for efficient decision-making during the iteration.

---

## Approach

1. Identify the cheapest item and the maximum factor present in the dataset to establish bounds for the search.
2. Calculate the frequency of each factor, determining how many items are multiples of each factor to assess potential free copy generation.
3. Iterate through the items, adding them to a cost-count map if they are profitable (i.e., if they generate more than one copy and their cost is within a reasonable threshold of the cheapest item).
4. Process the cost-count map to include as many items as possible within the budget, maximizing the total count of copies obtained.
5. Utilize any remaining budget to purchase additional copies of the cheapest item, ensuring no budget is wasted.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(N + M log M)` — The initial pass through the items takes O(N) to find the minimum cost and maximum factor. The frequency calculation involves iterating up to the maximum factor (M), with each step potentially updating multiple entries, leading to an overall complexity of O(M log M) due to the nature of the divisor loop. The final iteration over the cost-count map is linear relative to the number of unique costs, which is bounded by N. |
| **Space** | `O(M)` — The space complexity is dominated by the frequency array, which requires O(M) space to store counts for all factors up to the maximum observed. The cost-count map also requires space, but since it only stores unique cost-count pairs, it is bounded by the number of distinct items, making the overall space complexity O(M). |

---

## Code (C++)

```cpp
class Solution {
    #define ll long long
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();

        //Step-1: Find cheapest and max_factor O(N)
        int cheapest = INT_MAX;
        int max_factor = INT_MIN;
        for(int i=0;i<n;++i){
            cheapest = min(cheapest,items[i][1]);
            max_factor = max(max_factor,items[i][0]);
        }

        //Step-2: Calculate count of multiples for each factor O(MlogM)
        vector<int> freq(max_factor+1);//Create frequency counter for each factor
        for(int i=0;i<n;++i)
            freq[items[i][0]]++;
        for(int i=1;i<=max_factor;++i){
            if(freq[i]>0){
                for(int index=2*i;index<=max_factor;index+=i)
                    freq[i] += freq[index];
            }
        }

        //Step-3: Iterate for each item and check if including it is profitable over the cheapest ?
        map<ll,ll> cost_count;//Ordered based on increasing price
        for(int i=0;i<n;++i){
            int cost = items[i][1];
            int count = freq[items[i][0]]-1;
            if(count>0 and cost<=2*cheapest)
                cost_count[cost] += count;
        }
        //Step-4: Get total count of books by including optimally
        int total = 0;
        for(auto &[cost,count]: cost_count){
            int include = min<ll>(count,budget/cost);
            total += 2*include;
            budget -= include * cost;
        }
        total += budget/cheapest;//Leftover budget goes to cheapest book
        return total;
    }
};
```

---

## Key Takeaways

- The solution effectively combines greedy selection with a pre-computed frequency table to optimize the number of items obtained.
- It highlights the importance of considering the 'multiplier effect' of items that can generate free copies, rather than just minimizing individual costs.
- The use of a map to track cost-to-count ratios is a key technique for efficiently managing the trade-offs between different item prices and their respective yields.
