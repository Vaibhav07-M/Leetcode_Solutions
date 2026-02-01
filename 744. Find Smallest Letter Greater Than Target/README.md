# 744. Find Smallest Letter Greater Than Target

**Difficulty:** `Easy`  
**Tags:** `Array`, `Binary Search`

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

[LeetCode — 744. Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)

---

## Problem Summary

You are given an array of characters `letters` that is sorted in **non-decreasing order**, and a character `target`. There are at least two different characters in `letters`.

Return the **smallest character** in `letters` that is **lexicographically greater than** `target`. If such a character does not exist, return the **first character** in `letters`.

---

## Examples

### Example 1
**Input:** `letters = ["c","f","j"], target = "a"`  
**Output:** `"c"`  
**Explanation:**
- The smallest character lexicographically greater than 'a' in letters is 'c'

### Example 2
**Input:** `letters = ["c","f","j"], target = "c"`  
**Output:** `"f"`  
**Explanation:**
- The smallest character lexicographically greater than 'c' in letters is 'f'

### Example 3
**Input:** `letters = ["x","x","y","y"], target = "z"`  
**Output:** `"x"`  
**Explanation:**
- There are no characters in letters lexicographically greater than 'z', so we return letters[0]

---

## Intuition

Since the array is **sorted**, we can use **binary search** to find the answer efficiently in O(log n) time instead of a linear scan.

The key insight is that we're looking for the **leftmost** (smallest) character that is **strictly greater** than the target. This is a classic binary search variant.

**Special case**: If no character is greater than the target (e.g., target is 'z' and all letters are smaller), we wrap around and return `letters[0]` (circular behavior).

---

## Approach

### Binary Search Strategy:

1. **Initialize**: 
   - `left = 0`, `right = letters.size() - 1`
   - `answer = letters[0]` (default fallback for wrap-around case)

2. **Binary Search Loop**:
   - Calculate `mid = left + (right - left) / 2`
   - If `letters[mid] > target`:
     - This could be our answer, so update `answer = letters[mid]`
     - Search left half for potentially smaller valid answer: `right = mid - 1`
   - If `letters[mid] <= target`:
     - Current character is not valid, search right half: `left = mid + 1`

3. **Return**: The `answer` found, which is either:
   - The smallest character greater than target, or
   - `letters[0]` if no such character exists (wrap-around)

### Why Binary Search Works:

- Array is sorted, so all elements to the left of a valid answer are also potentially valid (or smaller)
- We want the **leftmost** valid answer, so when we find a valid character, we continue searching left
- Time complexity is O(log n) instead of O(n) linear search

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(log n)` — binary search on sorted array |
| **Space** | `O(1)` — only a few variables used |

---

## Code (C++)

### Solution 1: Binary Search (Standard)

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        char answer = letters[0]; // Default wrap-around answer
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (letters[mid] > target) {
                answer = letters[mid]; // Potential answer
                right = mid - 1;       // Search left for smaller valid answer
            } else {
                left = mid + 1;        // Search right
            }
        }
        
        return answer;
    }
};
```

### Solution 2: Binary Search (Compact)

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // If left == letters.size(), wrap around to letters[0]
        return left == letters.size() ? letters[0] : letters[left];
    }
};
```

### Solution 3: Using STL upper_bound

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // upper_bound returns iterator to first element > target
        auto it = upper_bound(letters.begin(), letters.end(), target);
        
        // If no element found, wrap around to letters[0]
        return it == letters.end() ? letters[0] : *it;
    }
};
```

### Solution 4: Linear Search (For Comparison)

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // O(n) solution - not optimal but simple
        for (char c : letters) {
            if (c > target) {
                return c;
            }
        }
        // Wrap around if not found
        return letters[0];
    }
};
```

---

## Key Takeaways

1. **Binary search on sorted arrays**: When searching in a sorted array, always consider binary search for O(log n) complexity instead of O(n) linear scan.

2. **Finding leftmost/rightmost elements**: Binary search variants can find:
   - Leftmost element ≥ x
   - Rightmost element ≤ x
   - Leftmost element > x (this problem)
   - Rightmost element < x

3. **Wrap-around logic**: Handle circular/wrap-around cases by setting a default answer before the search.

4. **STL upper_bound**: C++ STL provides `upper_bound()` for finding the first element strictly greater than a value.

5. **Boundary conditions**: Always consider edge cases:
   - Target smaller than all elements → return first element
   - Target larger than all elements → wrap around to first element
   - Target equals some elements → return next greater element

6. **Template for binary search**: The pattern `while (left <= right)` with `answer` tracking is reusable for many binary search problems.

7. **Lexicographic comparison**: Characters can be compared directly using `>`, `<`, `==` operators in C++.

---
