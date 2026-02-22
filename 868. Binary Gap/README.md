# 868. Binary Gap

**Difficulty:** `Easy`  
**Tags:** `Bit Manipulation`

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

[LeetCode — 868. Binary Gap](https://leetcode.com/problems/binary-gap/)

---

## Problem Summary

Given a positive integer `n`, find and return the **longest distance** between any two adjacent `1`'s in the binary representation of `n`. If there are no two adjacent `1`'s, return `0`.

Two `1`'s are **adjacent** if there are only `0`'s separating them (possibly no `0`'s). The **distance** between two `1`'s is the absolute difference between their bit positions.

---

## Examples

### Example 1
**Input:** `n = 22`  
**Output:** `2`  
**Explanation:**  
22 in binary is `"10110"`.
- The first adjacent pair of 1's is `"10110"` with a distance of 2.
- The second adjacent pair of 1's is `"10110"` with a distance of 1.
- The answer is the largest of these two distances, which is 2.
- Note that `"10110"` is not a valid pair since there is a 1 separating the two 1's underlined.

### Example 2
**Input:** `n = 8`  
**Output:** `0`  
**Explanation:**  
8 in binary is `"1000"`.  
There are not any adjacent pairs of 1's in the binary representation of 8, so we return 0.

### Example 3
**Input:** `n = 5`  
**Output:** `2`  
**Explanation:**  
5 in binary is `"101"`.

---

## Intuition

We need to find the maximum distance between consecutive `1` bits in the binary representation of a number.

**Key observations:**
- Adjacent `1`'s means consecutive `1`'s in the binary representation (not necessarily consecutive bits)
- We need to track the positions of `1` bits
- Calculate distances between consecutive `1` positions
- Return the maximum distance found

**Approach:**
1. Iterate through all bits of the number (from LSB to MSB or vice versa)
2. Keep track of positions where we find a `1` bit
3. When we find a `1`, calculate the distance from the previous `1` position
4. Keep track of the maximum distance
5. Handle edge case: if there's only one `1` or no `1`'s, return 0

---

## Approach

### Solution 1: Track Positions

1. **Initialize** variables:
   - `pos` = 0 (current bit position)
   - `lastPos` = -1 (position of last seen `1`)
   - `ans` = 0 (maximum distance)
2. **While** `n > 0`:
   - Check if current bit is `1` using `n & 1`
   - If it's `1`:
     - If `lastPos != -1`, calculate distance and update `ans`
     - Update `lastPos = pos`
   - Right shift `n` by 1
   - Increment `pos`
3. **Return** `ans`

### Solution 2: Using Built-in Functions

We can convert the number to binary string and find positions of all `1`'s, then calculate distances.

### Solution 3: Single Pass with Distance Tracking

Track the distance since the last `1` was seen, and update maximum when we encounter the next `1`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(log n)` — process each bit, there are log₂(n) bits |
| **Space** | `O(1)` — only use a few variables |

---

## Code (C++)

### Solution 1: Track Bit Positions

```cpp
class Solution {
public:
    int binaryGap(int n) {
        int pos = 0;
        int lastPos = -1;
        int ans = 0;
        
        while(n > 0) {
            if(n & 1) {
                if(lastPos != -1) {
                    ans = max(ans, pos - lastPos);
                }
                lastPos = pos;
            }
            n >>= 1;
            pos++;
        }
        
        return ans;
    }
};
```

### Solution 2: Track Distance Since Last 1

```cpp
class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0;
        int lastOnePos = -1;
        int currentPos = 0;
        
        while(n > 0) {
            if(n & 1) {
                if(lastOnePos != -1) {
                    maxGap = max(maxGap, currentPos - lastOnePos);
                }
                lastOnePos = currentPos;
            }
            n >>= 1;
            currentPos++;
        }
        
        return maxGap;
    }
};
```

### Solution 3: Using Vector to Store Positions

```cpp
class Solution {
public:
    int binaryGap(int n) {
        vector<int> positions;
        int pos = 0;
        
        // Collect all positions where bit is 1
        while(n > 0) {
            if(n & 1) {
                positions.push_back(pos);
            }
            n >>= 1;
            pos++;
        }
        
        // If less than 2 ones, return 0
        if(positions.size() < 2) {
            return 0;
        }
        
        // Find maximum gap
        int maxGap = 0;
        for(int i = 1; i < positions.size(); i++) {
            maxGap = max(maxGap, positions[i] - positions[i-1]);
        }
        
        return maxGap;
    }
};
```

### Solution 4: Distance Counter

```cpp
class Solution {
public:
    int binaryGap(int n) {
        int maxDistance = 0;
        int distance = 0;
        bool foundFirstOne = false;
        
        while(n > 0) {
            if(n & 1) {
                if(foundFirstOne) {
                    maxDistance = max(maxDistance, distance);
                }
                foundFirstOne = true;
                distance = 1; // Start counting from 1 for next gap
            } else {
                if(foundFirstOne) {
                    distance++;
                }
            }
            n >>= 1;
        }
        
        return maxDistance;
    }
};
```

### Solution 5: Cleaner Version

```cpp
class Solution {
public:
    int binaryGap(int n) {
        int result = 0;
        int prev = -1;
        
        for(int i = 0; i < 32; i++) {
            if((n >> i) & 1) {
                if(prev != -1) {
                    result = max(result, i - prev);
                }
                prev = i;
            }
        }
        
        return result;
    }
};
```

---

## Key Takeaways

- **Bit checking**: Use `n & 1` to check if the least significant bit is 1
- **Right shift**: `n >>= 1` moves to the next bit (divides by 2)
- **Position tracking**: Keep track of where we find `1` bits to calculate distances
- **Adjacent `1`'s definition**: Means consecutive `1`'s in the sequence of all `1` bits, not consecutive bit positions
- **Edge cases**:
  - Only one `1` bit → return 0
  - No `1` bits → won't happen per constraints (n is positive)
  - All consecutive `1`'s like `111` → minimum distance is 1
- **Bit position indexing**: Can start from 0 (LSB) or count from right
- **Alternative approaches**:
  - Store all positions then calculate pairwise differences
  - Track distance counter and reset when `1` is found
  - Use binary string representation and find indices
- **Optimization**: Single pass is sufficient, O(log n) time
- **Distance calculation**: Distance between positions `i` and `j` is simply `|i - j|`
- **Maximum tracking**: Use `max()` to keep track of the largest gap seen so far
- **Binary representation**: For number `n`, has at most ⌊log₂(n)⌋ + 1 bits
- **Bit manipulation pattern**: Common pattern of checking bits one by one using shift and mask

