# 3637. Trionic Array I

**Difficulty:** `Easy`  
**Tags:** `Array`

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

[LeetCode — 3637. Trionic Array I](https://leetcode.com/problems/trionic-array-i/)

---

## Problem Summary

You are given an integer array `nums` of length `n`.

An array is **trionic** if there exist indices `0 < p < q < n − 1` such that:
- `nums[0...p]` is strictly increasing
- `nums[p...q]` is strictly decreasing
- `nums[q...n − 1]` is strictly increasing

Return `true` if `nums` is trionic, otherwise return `false`.

**Constraints:**
- `3 <= n <= 100`
- `-1000 <= nums[i] <= 1000`

---

## Examples

### Example 1
**Input:** `nums = [1,3,5,4,2,6]`  
**Output:** `true`  
**Explanation:**
- Pick `p = 2`, `q = 4`:
  - `nums[0...2] = [1, 3, 5]` is strictly increasing (1 < 3 < 5)
  - `nums[2...4] = [5, 4, 2]` is strictly decreasing (5 > 4 > 2)
  - `nums[4...5] = [2, 6]` is strictly increasing (2 < 6)

### Example 2
**Input:** `nums = [2,1,3]`  
**Output:** `false`  
**Explanation:**
- There is no way to pick `p` and `q` to form the required three segments.

---

## Intuition

The problem requires finding three consecutive segments with specific monotonic properties:
1. First segment: strictly increasing
2. Middle segment: strictly decreasing
3. Last segment: strictly increasing

The key insight is that we can use a single linear scan to check if such a pattern exists. We need to ensure:
- The first segment has at least 2 elements (since `0 < p`)
- The middle segment has at least 2 elements (since `p < q`)
- The last segment has at least 2 elements (since `q < n − 1`)
- Each segment maintains its required monotonic property

---

## Approach

### Method 1: Three-Phase Linear Scan

1. **Phase 1 - Strictly Increasing:**
   - Start from index 0 and move forward while `nums[i] < nums[i+1]`
   - If we can't move at least once, the array doesn't start with an increasing segment

2. **Phase 2 - Strictly Decreasing:**
   - Continue from where phase 1 ended and move forward while `nums[i] > nums[i+1]`
   - If we can't move at least once, there's no decreasing segment

3. **Phase 3 - Strictly Increasing:**
   - Continue from where phase 2 ended and move forward while `nums[i] < nums[i+1]`
   - If we reach exactly the last index (`n-1`), the array is trionic

4. **Validation:**
   - We must reach exactly the last index after all three phases
   - Each phase must make at least one move to ensure all segments exist

This greedy approach works because we're looking for any valid trionic pattern, not a specific one. Taking the longest possible segments in each phase gives us the best chance of success.

### Method 2: Brute Force with All Combinations

Try all possible combinations of `p` and `q` where `0 < p < q < n-1`:
1. For each pair `(p, q)`, check if:
   - `nums[0...p]` is strictly increasing
   - `nums[p...q]` is strictly decreasing
   - `nums[q...n-1]` is strictly increasing
2. Return `true` if any valid pair is found

This is less efficient but more straightforward.

---

## Complexity

### Method 1: Linear Scan
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass through the array |
| **Space** | `O(1)` — only using index variables |

### Method 2: Brute Force
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n³)` — checking all pairs and validating segments |
| **Space** | `O(1)` — no extra space needed |

---

## Code (C++)

### Solution 1: Greedy Linear Scan (Optimal)

```cpp
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        // Phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        
        // Must have moved at least once and not be at the end
        if (i == 0 || i == n - 1) return false;
        
        // Phase 2: strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        
        // Must have moved at least once and not be at the end
        if (i == n - 1) return false;
        
        // Phase 3: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        
        // Must reach exactly the last index
        return i == n - 1;
    }
};
```

### Solution 2: Brute Force (All Combinations)

```cpp
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        
        // Try all possible values of p and q
        for (int p = 1; p < n - 1; p++) {
            // Check if nums[0...p] is strictly increasing
            bool firstIncreasing = true;
            for (int i = 0; i < p; i++) {
                if (nums[i] >= nums[i + 1]) {
                    firstIncreasing = false;
                    break;
                }
            }
            if (!firstIncreasing) continue;
            
            for (int q = p + 1; q < n - 1; q++) {
                // Check if nums[p...q] is strictly decreasing
                bool midDecreasing = true;
                for (int i = p; i < q; i++) {
                    if (nums[i] <= nums[i + 1]) {
                        midDecreasing = false;
                        break;
                    }
                }
                if (!midDecreasing) continue;
                
                // Check if nums[q...n-1] is strictly increasing
                bool lastIncreasing = true;
                for (int i = q; i < n - 1; i++) {
                    if (nums[i] >= nums[i + 1]) {
                        lastIncreasing = false;
                        break;
                    }
                }
                
                if (lastIncreasing) return true;
            }
        }
        
        return false;
    }
};
```

### Solution 3: Compact Version

```cpp
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 0;
        
        // Strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == 0 || i >= n - 2) return false;
        
        // Strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        if (i >= n - 1) return false;
        
        // Strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        
        return i == n - 1;
    }
};
```

---

## Key Takeaways

- **Greedy Linear Scan**: The optimal approach uses a single pass to identify the three segments
- **Phase Validation**: Each phase must make at least one move to ensure all three segments exist
- **Index Boundaries**: Critical to check that we don't reach the end too early or too late
- **Strictly Monotonic**: The problem requires strict inequality (`<` or `>`), not `<=` or `>=`
- **Single Pattern**: We only need to find one valid trionic pattern, not all of them
- **Overlapping Segments**: The segments overlap at indices `p` and `q` (peaks/valleys)
- **Greedy Works**: Taking the longest possible segment in each phase is optimal
- **Problem Constraints**: With `n <= 100`, even O(n³) brute force would work, but O(n) is better

