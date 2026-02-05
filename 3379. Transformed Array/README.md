# 3379. Transformed Array

**Difficulty:** `Easy`  
**Tags:** `Array`, `Simulation`

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

[LeetCode — 3379. Transformed Array](https://leetcode.com/problems/transformed-array/)

---

## Problem Summary

You are given an integer array `nums` that represents a **circular array**. Your task is to create a new array `result` of the same size, following these rules:

For each index `i` (where `0 <= i < nums.length`):
- If `nums[i] > 0`: Move `nums[i]` steps to the **right** in the circular array. Set `result[i]` to the value at the landing index.
- If `nums[i] < 0`: Move `abs(nums[i])` steps to the **left** in the circular array. Set `result[i]` to the value at the landing index.
- If `nums[i] == 0`: Set `result[i]` to `nums[i]` (which is 0).

Return the new array `result`.

**Note:** Since `nums` is circular, moving past the last element wraps around to the beginning, and moving before the first element wraps back to the end.

**Constraints:**
- `1 <= nums.length <= 100`
- `-100 <= nums[i] <= 100`

---

## Examples

### Example 1
**Input:** `nums = [3,-2,1,1]`  
**Output:** `[1,1,1,3]`  
**Explanation:**
- `nums[0] = 3`: Move 3 steps right from index 0 → land at index 3. `result[0] = nums[3] = 1`
- `nums[1] = -2`: Move 2 steps left from index 1 → land at index 3. `result[1] = nums[3] = 1`
- `nums[2] = 1`: Move 1 step right from index 2 → land at index 3. `result[2] = nums[3] = 1`
- `nums[3] = 1`: Move 1 step right from index 3 → land at index 0. `result[3] = nums[0] = 3`

### Example 2
**Input:** `nums = [-1,4,-1]`  
**Output:** `[-1,-1,4]`  
**Explanation:**
- `nums[0] = -1`: Move 1 step left from index 0 → land at index 2. `result[0] = nums[2] = -1`
- `nums[1] = 4`: Move 4 steps right from index 1 → land at index 2. `result[1] = nums[2] = -1`
- `nums[2] = -1`: Move 1 step left from index 2 → land at index 1. `result[2] = nums[1] = 4`

---

## Intuition

This is a straightforward circular array simulation problem. The key insight is handling the circular nature of the array using modulo arithmetic.

Key observations:
1. For positive values, we move right (forward) in the array
2. For negative values, we move left (backward) in the array
3. For zero, we stay at the same position
4. The array wraps around, so we need to handle indices that go beyond array bounds
5. Each element's transformation is **independent** of others

The circular indexing can be handled with modulo operation:
- Moving right: `(i + steps) % n`
- Moving left: `(i - steps + n) % n` or `(i - steps % n + n) % n` for large negative steps

---

## Approach

### Method 1: Direct Simulation with Modulo (Optimal)

1. **Initialize** a result array of the same size as `nums`
2. **For each index** `i` from 0 to n-1:
   - If `nums[i] > 0`: Calculate new index as `(i + nums[i]) % n`
   - If `nums[i] < 0`: Calculate new index as `(i + nums[i] % n + n) % n`
   - If `nums[i] == 0`: New index is `i`
   - Set `result[i] = nums[newIndex]`
3. **Return** the result array

**Why the formula works:**
- For positive steps: `(i + steps) % n` naturally wraps around
- For negative steps: We add `n` to ensure the result is always positive before taking modulo
- The `% n` inside negative calculation handles cases where `|nums[i]|` > n

### Method 2: Simplified Modulo

We can use a single formula for all cases:
- `newIndex = ((i + nums[i]) % n + n) % n`

This works for positive, negative, and zero values because:
- Adding `n` before the final modulo ensures we never have negative indices
- The double modulo handles both wrapping and negative values correctly

### Method 3: Manual Wrapping

Instead of using modulo, we can manually adjust the index:
1. Calculate `newIndex = i + nums[i]`
2. While `newIndex < 0`: Add `n` to wrap around
3. While `newIndex >= n`: Subtract `n` to wrap around
4. Set `result[i] = nums[newIndex]`

This is less elegant but more explicit about the wrapping logic.

---

## Complexity

### Method 1 & 2: Direct Simulation
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass through the array |
| **Space** | `O(n)` — result array (required for output) |

### Method 3: Manual Wrapping
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * k)` — where k is max steps (up to 100), worst case when wrapping multiple times |
| **Space** | `O(n)` — result array |

---

## Code (C++)

### Solution 1: Direct Simulation with Modulo (Optimal)

```cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                // Move right
                int newIndex = (i + nums[i]) % n;
                result[i] = nums[newIndex];
            } else if (nums[i] < 0) {
                // Move left
                int newIndex = (i + nums[i] % n + n) % n;
                result[i] = nums[newIndex];
            } else {
                // nums[i] == 0
                result[i] = nums[i];
            }
        }
        
        return result;
    }
};
```

### Solution 2: Simplified Single Formula

```cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            // Unified formula for all cases
            int newIndex = ((i + nums[i]) % n + n) % n;
            result[i] = nums[newIndex];
        }
        
        return result;
    }
};
```

### Solution 3: Manual Wrapping

```cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            int newIndex = i + nums[i];
            
            // Handle wrapping manually
            while (newIndex < 0) {
                newIndex += n;
            }
            while (newIndex >= n) {
                newIndex -= n;
            }
            
            result[i] = nums[newIndex];
        }
        
        return result;
    }
};
```

### Solution 4: Compact Version

```cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            result[i] = nums[((i + nums[i]) % n + n) % n];
        }
        
        return result;
    }
};
```

---

## Key Takeaways

- **Circular Array**: Use modulo arithmetic to handle wrap-around behavior
- **Unified Formula**: `((i + offset) % n + n) % n` works for both positive and negative offsets
- **Double Modulo**: The pattern `(x % n + n) % n` ensures non-negative result for any integer x
- **Independent Transformations**: Each element's result depends only on the original array, not on other transformations
- **Zero Handling**: Special case where element stays at its own position
- **Simulation Problem**: Straightforward implementation following given rules
- **Positive vs Negative**: Positive moves right, negative moves left in circular array
- **Efficient Solution**: O(n) time with single pass is optimal
- **No Edge Cases**: Problem guarantees at least 1 element, so no empty array handling needed

