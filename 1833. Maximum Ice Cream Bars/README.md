# 1833. Maximum Ice Cream Bars

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Counting`, `Sorting`

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

[LeetCode — 1833. Maximum Ice Cream Bars](https://leetcode.com/problems/maximum-ice-cream-bars/)

---

## Problem Summary

A boy wants to buy as many ice cream bars as possible.

You are given:

- `costs[i]` = price of the `i-th` ice cream bar.
- `coins` = total number of coins available.

The boy may buy ice cream bars in any order.

Return the **maximum number of ice cream bars** he can purchase. The problem specifically requires a **counting sort** solution. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:**

```cpp
costs = [1,3,2,4,1]
coins = 7
```

**Output:**

```cpp
4
```

**Explanation:**

The boy can buy bars costing:

```text
1 + 1 + 2 + 3 = 7
```

for a total of `4` ice cream bars. :contentReference[oaicite:1]{index=1}

---

### Example 2

**Input:**

```cpp
costs = [10,6,8,7,7,8]
coins = 5
```

**Output:**

```cpp
0
```

**Explanation:**

Every ice cream bar costs more than the available coins. :contentReference[oaicite:2]{index=2}

---

### Example 3

**Input:**

```cpp
costs = [1,6,3,1,2,5]
coins = 20
```

**Output:**

```cpp
6
```

**Explanation:**

The boy can afford all ice cream bars since their total cost is:

```text
1 + 6 + 3 + 1 + 2 + 5 = 18
```

which is within the budget. :contentReference[oaicite:3]{index=3}

---

## Intuition

To maximize the number of ice cream bars, we should always buy the cheapest bars first.

Instead of sorting the entire array, the problem asks for a **counting sort** approach.

Since:

```cpp
1 <= costs[i] <= 100000
```

we can count how many bars exist at each price and purchase them from the smallest cost upward.

---

## Approach

### 1. Count Frequencies

Create a frequency array:

```cpp
freq[cost]
```

that stores how many ice cream bars have a given price.

---

### 2. Process Costs in Increasing Order

Iterate through every possible cost from:

```cpp
1 → 100000
```

For each cost:

- Skip if no bars exist.
- Determine how many bars can be purchased:

```cpp
canBuy = min(freq[cost], coins / cost);
```

---

### 3. Update Answer

Add purchased bars to the answer:

```cpp
ans += canBuy;
```

Reduce the remaining coins:

```cpp
coins -= canBuy * cost;
```

---

### 4. Return Result

After processing all costs, `ans` contains the maximum number of ice cream bars that can be purchased.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n + MAX_COST)` |
| **Space** | `O(MAX_COST)` |

Where:

```cpp
MAX_COST = 100000
```

---

## Code (C++)

```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        const int MAX_COST = 100000;

        vector<int> freq(MAX_COST + 1, 0);

        for (int cost : costs)
            freq[cost]++;

        int ans = 0;

        for (int cost = 1; cost <= MAX_COST; cost++) {

            if (freq[cost] == 0)
                continue;

            int canBuy = min(freq[cost], coins / cost);

            ans += canBuy;
            coins -= canBuy * cost;

            if (coins < cost)
                continue;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- To maximize quantity, always buy the cheapest items first.
- Counting sort avoids the `O(n log n)` cost of sorting.
- Frequency counting works well when values have a bounded range.
- Process costs in ascending order and greedily buy as many as possible.
- The solution runs in `O(n + MAX_COST)` time.