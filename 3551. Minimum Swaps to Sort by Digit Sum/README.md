# 3551. Minimum Swaps to Sort by Digit Sum

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Sorting`

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

[LeetCode — 3551. Minimum Swaps to Sort by Digit Sum](https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/)

---

## Problem Summary

The problem requires sorting an array of integers based on the sum of their digits, with smaller numbers appearing first if digit sums are equal. The goal is to determine the minimum number of swaps needed to achieve this sorted order.

---

## Examples

_No examples provided._

---

## Intuition

The solution employs a cycle detection algorithm to minimize swaps. By identifying cycles of elements that need to be rearranged, the algorithm calculates the minimum number of swaps required to break these cycles and sort the array. This is more efficient than performing individual swaps for each element.

---

## Approach

1. Create a vector of pairs containing the original numbers and their indices.
2. Sort the vector based on the digit sum of the numbers, with a secondary sort by the number itself if sums are equal.
3. Initialize a visited array and a swap counter.
4. Iterate through the sorted vector, identifying cycles of elements that are not in their correct positions.
5. For each cycle, calculate the number of swaps needed to resolve it (cycle length - 1) and add it to the total swap count.
6. Return the total number of swaps.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — The dominant factor is the sorting step, which has a time complexity of O(n log n). The subsequent cycle detection and counting are linear, O(n), but the overall complexity is determined by the sorting operation. |
| **Space** | `O(n)` — The solution requires additional space for the vector of pairs, the visited array, and temporary variables. The space complexity is linear relative to the size of the input array. |

---

## Code (C++)

```cpp

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [&](auto a, auto b) {
            int s1 = digitSum(a.first);
            int s2 = digitSum(b.first);

            if (s1 != s2)
                return s1 < s2;

            return a.first < b.first;
        });

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};
```

---

## Key Takeaways

- The solution utilizes a cycle detection algorithm to efficiently calculate the minimum number of swaps required for sorting.
- Sorting the array based on the digit sum allows for a structured approach to identifying the necessary rearrangements.
- The algorithm avoids unnecessary swaps by focusing on the relationships between elements rather than individual positions.
