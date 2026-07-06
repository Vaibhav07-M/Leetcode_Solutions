# 1288. Remove Covered Intervals

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

[LeetCode — 1288. Remove Covered Intervals](https://leetcode.com/problems/remove-covered-intervals/)

---

## Problem Summary

You are given an array `intervals` where:

```cpp
intervals[i] = [li, ri)
```

represents the interval `[li, ri)`.

An interval:

```text
[a, b)
```

is said to be **covered** by another interval:

```text
[c, d)
```

if:

```text
c <= a
and
b <= d
```

Remove all covered intervals and return the number of remaining intervals.

---

## Examples

### Example 1

**Input:**

```cpp
intervals = [[1,4],[3,6],[2,8]]
```

**Output:**

```cpp
2
```

**Explanation:**

Interval:

```text
[3,6]
```

is covered by:

```text
[2,8]
```

so it is removed.

---

### Example 2

**Input:**

```cpp
intervals = [[1,4],[2,3]]
```

**Output:**

```cpp
1
```

**Explanation:**

Interval:

```text
[2,3]
```

is completely covered by:

```text
[1,4]
```

---

## Intuition

Sorting the intervals helps us identify covered intervals efficiently.

Sort by:

- Increasing starting point.
- If two intervals have the same start, place the **longer interval first**.

This guarantees that whenever we encounter a shorter interval with the same starting point, it is automatically covered.

While traversing the sorted intervals, keep track of the largest ending point seen so far.

- If the current interval ends beyond the current maximum, it is not covered.
- Otherwise, it is covered and should be ignored.

---

## Approach

### 1. Sort the Intervals

Sort intervals by:

- Increasing start value.
- Decreasing end value when starts are equal.

---

### 2. Traverse the Sorted List

Maintain:

```cpp
maxEnd
```

which stores the largest ending point encountered.

For every interval:

- If:

```cpp
interval[1] > maxEnd
```

then the interval is not covered.

- Otherwise, it is already covered by a previously processed interval.

---

### 3. Count Remaining Intervals

Increase the answer only when an interval is not covered.

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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];   // longer interval first
            return a[0] < b[0];
        });

        int count = 0;
        int maxEnd = -1;

        for (auto &interval : intervals) {
            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }

        return count;
    }
};
```

---

## Key Takeaways

- Sort intervals by increasing start and decreasing end.
- Keeping longer intervals first makes covered intervals easy to detect.
- Track the maximum ending point seen so far.
- An interval is covered if its ending point does not exceed the current maximum.
- The solution runs in `O(n log n)` time with `O(1)` extra space.