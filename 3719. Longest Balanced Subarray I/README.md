# 3719. Longest Balanced Subarray I

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Sliding Window`

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

[LeetCode — 3719. Longest Balanced Subarray I](https://leetcode.com/problems/longest-balanced-subarray-i/)

---

## Problem Summary

You are given an integer array `nums`.

A subarray is called **balanced** if the number of **distinct even numbers** in the subarray is equal to the number of **distinct odd numbers**.

Return the **length of the longest balanced subarray**.

---

## Examples

### Example 1
**Input:** `nums = [2,5,4,3]`  
**Output:** `4`  
**Explanation:**
- The longest balanced subarray is `[2, 5, 4, 3]`.
- It has 2 distinct even numbers `[2, 4]` and 2 distinct odd numbers `[5, 3]`.
- Answer = 4

### Example 2
**Input:** `nums = [3,2,2,5,4]`  
**Output:** `5`  
**Explanation:**
- The longest balanced subarray is `[3, 2, 2, 5, 4]`.
- It has 2 distinct even numbers `[2, 4]` and 2 distinct odd numbers `[3, 5]`.
- Answer = 5

### Example 3
**Input:** `nums = [1,2,3,2]`  
**Output:** `3`  
**Explanation:**
- The longest balanced subarray is `[2, 3, 2]`.
- It has 1 distinct even number `[2]` and 1 distinct odd number `[3]`.
- Answer = 3

---

## Intuition

A balanced subarray requires equal counts of **distinct** even and odd numbers—not total count, but **unique** values.

For example, `[2, 2, 3]` has 1 distinct even (`2`) and 1 distinct odd (`3`)—so it's balanced.

We need to:
1. Track distinct even and odd numbers in each subarray
2. Find the longest one where these counts are equal

Using **hash sets** (or sets) to store distinct values makes this straightforward.

---

## Approach

### Approach 1: Brute Force with Two Sets (O(n²))

1. For each starting index `i`:
   - Use two sets: `evenSet` and `oddSet`
   - Extend the subarray by iterating `j` from `i` to `n-1`
   - At each `j`, add `nums[j]` to the appropriate set (even or odd)
   - If `evenSet.size() == oddSet.size()`, check if current length is maximum
2. Return the maximum length found

This approach checks all subarrays and tracks distinct counts efficiently using sets.

### Approach 2: Optimized Early Termination

Same as Approach 1, but skip when remaining elements can't beat current answer.

### Approach 3: HashMap State Tracking

Use a single map to track distinct even/odd counts as we extend subarrays, reducing redundant checks.

---

## Complexity

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| **Brute Force with Sets** | `O(n²)` | `O(n)` for sets |
| **With Early Termination** | `O(n²)` | `O(n)` |
| **Compact Version** | `O(n²)` | `O(n)` |

Where `n = nums.length`.

---

## Code (C++)

### Solution 1: Brute Force with Two Sets

```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<int> evenSet;
            unordered_set<int> oddSet;

            for(int j = i; j < n; j++) {
                if(nums[j] % 2 == 0) {
                    evenSet.insert(nums[j]);
                } else {
                    oddSet.insert(nums[j]);
                }

                if(evenSet.size() == oddSet.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
```

---

### Solution 2: With Early Termination

```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            // Early termination: if remaining elements can't beat current answer
            if(n - i <= ans) break;

            unordered_set<int> evenSet;
            unordered_set<int> oddSet;

            for(int j = i; j < n; j++) {
                if(nums[j] % 2 == 0) {
                    evenSet.insert(nums[j]);
                } else {
                    oddSet.insert(nums[j]);
                }

                if(evenSet.size() == oddSet.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
```

---

### Solution 3: Using Sets with Size Check

```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for(int start = 0; start < n; start++) {
            set<int> even, odd;

            for(int end = start; end < n; end++) {
                (nums[end] % 2 == 0 ? even : odd).insert(nums[end]);

                if(even.size() == odd.size()) {
                    maxLen = max(maxLen, end - start + 1);
                }
            }
        }

        return maxLen;
    }
};
```

---

### Solution 4: Compact Version

```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<int> even, odd;
            for(int j = i; j < nums.size(); j++) {
                (nums[j] & 1 ? odd : even).insert(nums[j]);
                if(even.size() == odd.size()) 
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
```

---

## Key Takeaways

- **Distinct counts** matter, not total counts—use `set` or `unordered_set` to track unique values
- **Brute force** with sets is straightforward and efficient enough for constraints up to `n ≤ 1500`
- **Early termination** can optimize when remaining elements can't improve the answer
- **Bitwise check** (`nums[j] & 1`) is faster than modulo for even/odd detection
- **Ternary expressions** with sets make code more compact: `(condition ? set1 : set2).insert()`
- For "distinct element" problems, hash sets are your friend
- O(n²) is acceptable when n ≤ 1500 and operations per iteration are O(1) amortized
- Always check if a greedy or sliding window optimization exists, though not applicable here due to "distinct" requirement
- Similar pattern: Count distinct elements in all subarrays
- Could extend to "longest subarray with k distinct even and k distinct odd numbers"

---
