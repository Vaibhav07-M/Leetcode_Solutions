# 1520. Maximum Number of Non-Overlapping Substrings

**Difficulty:** `Hard`  
**Tags:** `Hash Table`, `String`, `Greedy`, `Sorting`

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

[LeetCode — 1520. Maximum Number of Non-Overlapping Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)

---

## Problem Summary

The problem requires finding the maximum number of non-overlapping substrings in a given string, where each substring must contain all occurrences of its characters. The solution employs a greedy approach to select substrings that end earliest, ensuring minimal overlap and satisfying the character containment constraint.

---

## Examples

### Example 1
**Input:** `s = "adefaddaccc"`  
**Output:** `["e","f","ccc"]`  
**Explanation:**
- The following are all the possible substrings that meet the conditions:
- [
- "adefaddaccc"
- "adefadda",
- "ef",
- "e",
- "f",
- "ccc",
- ]
- If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.

### Example 2
**Input:** `s = "abbaccd"`  
**Output:** `["d","bb","cc"]`  
**Explanation:**
- Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.

---

## Intuition

The core insight is to identify 'valid' intervals for each character by checking if all occurrences of that character lie within the interval. By sorting these intervals by their ending positions, the algorithm can greedily select the next substring that ends earliest, minimizing the overlap and maximizing the number of distinct substrings.

---

## Approach

1. Initialize arrays to track the first and last occurrence of each character in the string.
2. Iterate through the string to populate these occurrence arrays.
3. For each character, attempt to create an interval spanning from its first to last occurrence. Verify that no other character's occurrence lies outside this window to ensure the interval is valid.
4. Sort the collected valid intervals by their ending positions.
5. Greedily iterate through the sorted intervals, adding a substring to the result if its start position is greater than the end of the previously selected substring.
6. Return the list of selected substrings.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + Σ(n))` — The initial pass to find character occurrences takes O(n). The subsequent loop to create intervals iterates over each character, with the inner loop potentially running up to n times for each character, leading to a total complexity of O(n + Σ(n)). Sorting the intervals adds an O(n log n) step, but the dominant factor is the nested iteration. |
| **Space** | `O(n)` — The space complexity is determined by the storage for the character occurrence arrays (O(1)) and the list of intervals, which in the worst case could contain n elements if the string consists of a single repeating character, making it O(n). |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to create a valid interval for every character
        for (int c = 0; c < 26; c++) {

            if (last[c] == -1)
                continue;

            int left = first[c];
            int right = last[c];

            bool valid = true;

            for (int i = left; i <= right; i++) {
                int x = s[i] - 'a';

                // This character appeared before our left boundary
                if (first[x] < left) {
                    valid = false;
                    break;
                }

                // We must include all occurrences of this character
                right = max(right, last[x]);
            }

            if (valid)
                intervals.push_back({left, right});
        }

        // Sort intervals by ending position
        sort(intervals.begin(), intervals.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        // Greedily choose the interval ending earliest
        for (auto interval : intervals) {
            int left = interval.first;
            int right = interval.second;

            if (left > prevEnd) {
                ans.push_back(s.substr(left, right - left + 1));
                prevEnd = right;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The solution effectively combines character tracking with interval analysis to satisfy the non-overlap and containment constraints.
- Sorting by the end of the interval is a key strategy to minimize overlap and maximize the number of selectable substrings.
- The greedy selection of the earliest-ending interval ensures an optimal solution for the given constraints.
