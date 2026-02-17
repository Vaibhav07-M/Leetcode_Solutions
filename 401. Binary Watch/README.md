# 401. Binary Watch

**Difficulty:** `Easy`  
**Tags:** `Backtracking`, `Bit Manipulation`

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

[LeetCode — 401. Binary Watch](https://leetcode.com/problems/binary-watch/)

---

## Problem Summary

A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

Given an integer `turnedOn` which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

**Constraints:**
- The hour must not contain a leading zero (e.g., "1:00" not "01:00")
- The minute must consist of two digits and may contain a leading zero (e.g., "10:02" not "10:2")

---

## Examples

### Example 1
**Input:** `turnedOn = 1`  
**Output:** `["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]`  
**Explanation:** One LED can be on in positions representing 1, 2, 4, 8, 16, 32 minutes or 1, 2, 4, 8 hours.

### Example 2
**Input:** `turnedOn = 9`  
**Output:** `[]`  
**Explanation:** Maximum possible LEDs on for valid time is 8 (11:59 has 8 bits on). So 9 or 10 LEDs on is impossible.

---

## Intuition

The key insight is that a binary watch uses binary representation for both hours and minutes:
- **Hours (0-11):** Represented by 4 LEDs (max value 15, but we only use 0-11)
- **Minutes (0-59):** Represented by 6 LEDs (max value 63, but we only use 0-59)

Each valid time has a specific number of LEDs turned on, which equals the total number of 1s in the binary representations of both hour and minute values.

Instead of trying to generate all combinations of which LEDs to turn on, we can:
1. **Iterate through all valid times** (hours 0-11, minutes 0-59)
2. **Count the number of 1-bits** (set bits) in each hour and minute
3. **Check if the total matches** `turnedOn`
4. If yes, add that time to the result

This brute force approach is efficient because there are only 12 × 60 = 720 possible times to check.

---

## Approach

### Solution 1: Brute Force with Bit Counting (Optimal)

1. **Initialize** an empty result vector
2. **Iterate** through all possible hours (0 to 11):
   - For each hour, iterate through all possible minutes (0 to 59):
     - Count the number of set bits in `hour` using `__builtin_popcount()`
     - Count the number of set bits in `minute` using `__builtin_popcount()`
     - If the sum equals `turnedOn`:
       - Format the time string (hour without leading zero, minute with leading zero if needed)
       - Add to result
3. **Return** the result vector

**Why this works:**
- We exhaustively check all valid times (only 720 possibilities)
- Bit counting directly tells us how many LEDs are on
- No need for complex backtracking since the search space is small

### Alternative: Backtracking Approach

We could also use backtracking to generate combinations of which LEDs to turn on, but this is more complex and not necessary for this problem size.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(1)` — always checks 12 × 60 = 720 times, which is constant |
| **Space** | `O(1)` — output space doesn't count; only uses a few variables |

---

## Code (C++)

### Solution 1: Brute Force with __builtin_popcount

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for(int hour = 0; hour < 12; hour++) {
            for(int minute = 0; minute < 60; minute++) {
                int bits = __builtin_popcount(hour) + __builtin_popcount(minute);
                
                if(bits == turnedOn) {
                    string time = to_string(hour) + ":";
                    if(minute < 10) time += "0";
                    time += to_string(minute);
                    result.push_back(time);
                }
            }
        }

        return result;
    }
};
```

### Solution 2: Manual Bit Counting

```cpp
class Solution {
private:
    int countBits(int n) {
        int count = 0;
        while(n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for(int hour = 0; hour < 12; hour++) {
            for(int minute = 0; minute < 60; minute++) {
                if(countBits(hour) + countBits(minute) == turnedOn) {
                    result.push_back(to_string(hour) + ":" + 
                                   (minute < 10 ? "0" : "") + 
                                   to_string(minute));
                }
            }
        }

        return result;
    }
};
```

### Solution 3: Using Bitset

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for(int hour = 0; hour < 12; hour++) {
            for(int minute = 0; minute < 60; minute++) {
                bitset<4> h(hour);
                bitset<6> m(minute);
                
                if(h.count() + m.count() == turnedOn) {
                    string time = to_string(hour) + ":";
                    time += (minute < 10 ? "0" : "") + to_string(minute);
                    result.push_back(time);
                }
            }
        }

        return result;
    }
};
```

### Solution 4: Using sprintf for Formatting

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for(int hour = 0; hour < 12; hour++) {
            for(int minute = 0; minute < 60; minute++) {
                if(__builtin_popcount(hour) + __builtin_popcount(minute) == turnedOn) {
                    char buffer[10];
                    sprintf(buffer, "%d:%02d", hour, minute);
                    result.push_back(string(buffer));
                }
            }
        }

        return result;
    }
};
```

---

## Key Takeaways

- **Brute force is sometimes optimal**: With only 720 possible times, checking all is faster than generating combinations
- **Bit counting**: `__builtin_popcount()` is a built-in GCC function that efficiently counts set bits
- **Alternative bit counting**: Can manually count using `n & 1` and right shift in a loop
- **Bitset**: C++ `bitset<N>` provides `count()` method to count set bits
- **String formatting**:
  - Hours: no leading zero, use `to_string(hour)` directly
  - Minutes: need leading zero for single digits, check `minute < 10`
  - Can use `sprintf` with `%02d` format for automatic zero-padding
- **Time representation**: 
  - 4 bits for hours (0-11): positions 8, 4, 2, 1
  - 6 bits for minutes (0-59): positions 32, 16, 8, 4, 2, 1
- **Edge cases**: 
  - `turnedOn = 0`: Only "0:00" is valid
  - `turnedOn >= 9`: No valid times (max is 8 bits for 11:59)
- **Small search space**: Sometimes iterating through all possibilities is simpler than using complex algorithms

