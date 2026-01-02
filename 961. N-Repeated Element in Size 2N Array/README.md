# 961. N-Repeated Element in Size 2N Array

**Difficulty:** `Easy`  
**Tags:** `Array`, `Hash Table`

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

[LeetCode — 961. N-Repeated Element in Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)

---

## Problem Summary

You are given an integer array `nums` with the following properties:
- `nums.length == 2 * n`
- `nums` contains `n + 1` unique elements
- Exactly one element of `nums` is repeated `n` times

Return the element that is repeated `n` times.

---

## Examples

### Example 1
**Input:** `nums = [1,2,3,3]`  
**Output:** `3`  
**Explanation:**
- Array length is 4, so n = 2
- The element 3 appears 2 times (n times)

### Example 2
**Input:** `nums = [2,1,2,5,3,2]`  
**Output:** `2`  
**Explanation:**
- Array length is 6, so n = 3
- The element 2 appears 3 times (n times)

### Example 3
**Input:** `nums = [5,1,5,2,5,3,5,4]`  
**Output:** `5`  
**Explanation:**
- Array length is 8, so n = 4
- The element 5 appears 4 times (n times)

---

## Intuition

Since the array has length `2n` and contains `n+1` unique elements with one element repeated exactly `n` times, this means:
- There are `n` repeated elements and `n` unique elements
- The repeated element appears exactly half the time

The key insight is that with `n+1` unique elements in a `2n` sized array, the repeated element must appear frequently. We can use a hash set to track elements we've seen. The first element we encounter that's already in the set is our answer.

Alternatively, we can use a frequency count approach with a hash map - the element with count `n` (or more than 1) is our target.

---

## Approach

### Approach 1: Hash Set (Optimal)
1. **Initialize a Set**: Create an empty set to track seen elements.
2. **Iterate Through Array**: For each element in the array:
   - If the element is already in the set, return it (this is the repeated element)
   - Otherwise, add it to the set
3. **Return Result**: The first duplicate found is the n-repeated element.

### Approach 2: Hash Map (Frequency Count)
1. **Count Frequencies**: Use a hash map to count occurrences of each element.
2. **Find Repeated Element**: Return the element with frequency greater than 1 (or equal to n).

Both approaches work, but the hash set approach is more efficient as it can return early upon finding the first duplicate.

---

## Complexity

- **Time Complexity**: `O(n)` where n is the length of the array.  
  We traverse the array once, and set/map operations are O(1) average case.

- **Space Complexity**: `O(n)` for storing elements in the hash set/map.  
  In the worst case, we store up to n unique elements before finding the repeated one.

---

## Code (C++)

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        
        for(int num : nums) {
            if(seen.count(num)) {
                return num;
            }
            seen.insert(num);
        }
        
        return -1; // This line will never be reached given the problem constraints
    }
};
```

**Alternative Approach (Hash Map):**
```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for(int num : nums) {
            freq[num]++;
            if(freq[num] > 1) {
                return num;
            }
        }
        
        return -1;
    }
};
```

---

## Key Takeaways

- **Early Return Optimization**: Using a hash set allows us to return immediately upon finding the first duplicate, making the solution efficient.
- **Problem Constraints Matter**: Understanding that exactly one element appears n times and there are n+1 unique elements helps us realize the repeated element will be found quickly.
- **Hash Set vs Hash Map**: Both data structures work, but hash set is slightly more efficient here since we only need to detect presence, not count frequencies.
- **Pattern Recognition**: This is a classic "find duplicate" problem that appears frequently in coding interviews.
- **Space-Time Tradeoff**: We trade O(n) space for O(n) time, which is optimal for this problem.
