# 3634. Minimum Removals to Balance Array

**Difficulty:** `Medium`  
**Tags:** `Array`, `Sorting`, `Sliding Window`, `Two Pointers`

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

[LeetCode — 3634. Minimum Removals to Balance Array](https://leetcode.com/problems/minimum-removals-to-balance-array/)

---

## Problem Summary

You are given an integer array `nums` and an integer `k`.

An array is considered **balanced** if the value of its maximum element is at most `k` times the minimum element. In other words: `max(array) <= k * min(array)`

You may remove any number of elements from `nums` without making it empty.

Return the **minimum number of elements to remove** so that the remaining array is balanced.

**Note:** An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.

**Constraints:**
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 10^5`

---

## Examples

### Example 1
**Input:** `nums = [2,1,5], k = 2`  
**Output:** `1`  
**Explanation:**
- Remove `nums[2] = 5` to get `nums = [2, 1]`
- Now `max = 2`, `min = 1` and `max <= min * k` as `2 <= 1 * 2`
- Thus, the answer is 1

### Example 2
**Input:** `nums = [1,6,2,9], k = 3`  
**Output:** `2`  
**Explanation:**
- Remove `nums[0] = 1` and `nums[3] = 9` to get `nums = [6, 2]`
- Now `max = 6`, `min = 2` and `max <= min * k` as `6 <= 2 * 3`
- Thus, the answer is 2

### Example 3
**Input:** `nums = [4,6], k = 2`  
**Output:** `0`  
**Explanation:**
- Since `nums` is already balanced as `6 <= 4 * 2`, no elements need to be removed

---

## Intuition

The key insight is that in a balanced array, all elements must lie within a specific range. If we fix the minimum element, then all elements in the balanced array must satisfy: `element <= k * min_element`.

Since we want to **minimize removals**, we equivalently want to **maximize the number of elements we keep**. This transforms the problem into finding the longest subarray (in a sorted array) where the ratio between max and min doesn't exceed `k`.

Key observations:
1. **Sorting helps**: After sorting, we can use a sliding window approach where any contiguous subarray will have its min at the left end and max at the right end
2. **Window condition**: For a window `[l, r]` in sorted array, we need `nums[r] <= k * nums[l]`
3. **Maximum kept = Minimum removed**: If we keep `maxLen` elements, we remove `n - maxLen` elements
4. **Single element**: Any single element forms a balanced array (since max == min)

The problem becomes: find the longest contiguous subarray in the sorted array where `nums[r] / nums[l] <= k`.

---

## Approach

### Method 1: Sorting + Sliding Window (Optimal)

1. **Sort the array** in ascending order
2. **Use two pointers** (left and right) to maintain a sliding window:
   - The window represents a potential balanced array
   - `nums[left]` is the minimum, `nums[right]` is the maximum
3. **Expand and contract window**:
   - Expand right pointer to include more elements
   - If `nums[right] > k * nums[left]`, the window is invalid
   - Contract from left until window becomes valid again
4. **Track maximum window size** throughout the process
5. **Return** `n - maxWindowSize` as the minimum removals

**Why this works:**
- After sorting, any contiguous subarray has its min/max at the endpoints
- Sliding window efficiently finds all valid subarrays
- The longest valid subarray minimizes removals

**Algorithm:**
```
1. Sort nums
2. Initialize left = 0, maxLen = 1
3. For right from 0 to n-1:
     - While nums[right] > k * nums[left]:
         - Move left forward
     - maxLen = max(maxLen, right - left + 1)
4. Return n - maxLen
```

### Method 2: Sorting + Binary Search for Each Element

For each element as the minimum:
1. Fix `nums[i]` as the minimum
2. Binary search for the largest index `j` where `nums[j] <= k * nums[i]`
3. The length of valid subarray is `j - i + 1`
4. Track maximum length

This is less efficient than the sliding window approach.

### Method 3: Brute Force (Check All Subarrays)

After sorting:
1. Try all possible subarrays `[i, j]`
2. Check if `nums[j] <= k * nums[i]`
3. Track maximum valid length

This has O(n²) time complexity.

---

## Complexity

### Method 1: Sliding Window
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — dominated by sorting; sliding window is O(n) |
| **Space** | `O(1)` — only using pointers (ignoring sorting space) |

### Method 2: Binary Search
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — O(n log n) for sorting + O(n log n) for n binary searches |
| **Space** | `O(1)` — constant extra space |

### Method 3: Brute Force
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n²)` — checking all pairs |
| **Space** | `O(1)` — constant extra space |

---

## Code (C++)

### Solution 1: Sliding Window (Optimal)

```cpp
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left = 0;
        int maxLen = 1;  // At least one element can always be kept
        
        for (int right = 0; right < n; right++) {
            // Shrink window from left while condition is violated
            while (nums[right] > (long long)k * nums[left]) {
                left++;
            }
            
            // Update maximum valid window size
            maxLen = max(maxLen, right - left + 1);
        }
        
        // Minimum removals = total - maximum kept
        return n - maxLen;
    }
};
```

### Solution 2: Sliding Window with Explicit Check

```cpp
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left = 0;
        int maxLen = 1;
        
        for (int right = 0; right < n; right++) {
            // Move left pointer until window is valid
            while (left < right && nums[right] > (long long)k * nums[left]) {
                left++;
            }
            
            // Current window [left, right] is valid
            int windowSize = right - left + 1;
            maxLen = max(maxLen, windowSize);
        }
        
        return n - maxLen;
    }
};
```

### Solution 3: Binary Search for Each Element

```cpp
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int maxLen = 1;
        
        for (int i = 0; i < n; i++) {
            // Find largest j where nums[j] <= k * nums[i]
            long long target = (long long)k * nums[i];
            
            // Binary search
            int left = i, right = n - 1;
            int validEnd = i;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] <= target) {
                    validEnd = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            maxLen = max(maxLen, validEnd - i + 1);
        }
        
        return n - maxLen;
    }
};
```

### Solution 4: Using STL upper_bound

```cpp
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int maxLen = 1;
        
        for (int i = 0; i < n; i++) {
            long long maxAllowed = (long long)k * nums[i];
            
            // Find first element > maxAllowed
            auto it = upper_bound(nums.begin() + i, nums.end(), maxAllowed);
            
            // Length of valid subarray starting at i
            int len = distance(nums.begin() + i, it);
            maxLen = max(maxLen, len);
        }
        
        return n - maxLen;
    }
};
```

---

## Key Takeaways

- **Min/Max Relationship**: The balance condition `max <= k * min` creates a bounded range
- **Sorting Transforms Problem**: After sorting, contiguous subarrays have min/max at endpoints
- **Minimize Removals = Maximize Kept**: Finding longest valid subarray is equivalent to minimum removals
- **Sliding Window Pattern**: Two pointers efficiently find all valid windows in sorted array
- **Integer Overflow**: Use `long long` when computing `k * nums[left]` since both can be up to 10^5 and 10^9
- **Single Element Edge Case**: Any single element is always balanced (handled by initializing maxLen = 1)
- **Window Validity**: Condition `nums[right] > k * nums[left]` determines when to shrink window
- **Optimal O(n log n)**: Sorting dominates; sliding window adds only O(n)
- **Greedy Property**: Keeping the longest valid subarray is optimal due to monotonicity after sorting
- **Similar to**: Problems involving finding longest subarray with bounded ratio or difference

