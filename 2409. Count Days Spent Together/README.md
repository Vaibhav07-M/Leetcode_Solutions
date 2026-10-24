# 2409. Count Days Spent Together

**Difficulty:** `Easy`  
**Tags:** `Math`, `String`

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

[LeetCode — 2409. Count Days Spent Together](https://leetcode.com/problems/count-days-spent-together/)

---

## Problem Summary

The problem requires calculating the number of days that two individuals, Alice and Bob, are simultaneously present in Rome. Each person's visit is defined by a start and end date in the format 'MM-DD'. The solution must account for the varying number of days in each month to determine the total overlap period.

---

## Examples

### Example 1
**Input:** `arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"`  
**Output:** `3`  
**Explanation:**
- Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

### Example 2
**Input:** `arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"`  
**Output:** `0`  
**Explanation:**
- There is no day when Alice and Bob are in Rome together, so we return 0.

---

## Intuition

To find the overlap, we need to convert the string dates into a single integer representing the day of the year (e.g., January 1st is 1, February 1st is 32). By comparing the converted start and end dates for both Alice and Bob, we can identify the earliest start date and the latest end date of the shared period. The difference between these two values gives the total number of overlapping days.

---

## Approach

1. Define an array 'days' containing the number of days for each month (January to December).
2. Create a lambda function 'convert' that takes a date string, extracts the month and day, and calculates the corresponding day of the year by summing the days of previous months.
3. Convert the four input strings (arriveAlice, leaveAlice, arriveBob, leaveBob) into their respective day-of-year integers.
4. Determine the 'start' of the overlap as the maximum of the two arrival dates, and the 'end' as the minimum of the two departure dates.
5. If the calculated start is greater than the end, there is no overlap (return 0). Otherwise, return the difference between the end and start plus one to include the start day.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(1)` — The solution involves a fixed number of arithmetic operations to convert dates and compare values. The loop in the 'convert' function iterates over a constant-sized array (12 months), making the overall time complexity constant. |
| **Space** | `O(1)` — The space used is limited to a few integer variables for storing the converted dates and the overlap bounds. The 'days' array is a small, constant-sized lookup table, so the space complexity is constant. |

---

## Code (C++)

```cpp
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        
        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }

            return day;
        };

        int start = max(convert(arriveAlice), convert(arriveBob));
        int end = min(convert(leaveAlice), convert(leaveBob));

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};
```

---

## Key Takeaways

- Date conversion is a key step in solving overlap problems; converting to a single integer (day of year) simplifies comparisons.
- The maximum of the starts and minimum of the ends define the intersection of two intervals.
- Always check for negative or zero overlap (start > end) to handle cases where the intervals do not intersect.
