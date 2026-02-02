# 3013. Divide an Array Into Subarrays With Minimum Cost II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Sliding Window`, `Heap (Priority Queue)`, `Ordered Set`

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

[LeetCode — 3013. Divide an Array Into Subarrays With Minimum Cost II](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/)

---

## Problem Summary

You are given a 0-indexed array of integers `nums` of length `n`, and two positive integers `k` and `dist`.

The **cost** of an array is the value of its **first element**. For example, the cost of `[1,2,3]` is `1` while the cost of `[3,4,1]` is `3`.

You need to divide `nums` into **k disjoint contiguous subarrays**, such that the difference between the starting index of the **second** subarray and the starting index of the **kth** subarray should be **less than or equal to dist**.

In other words, if you divide nums into subarrays `nums[0..(i1 - 1)]`, `nums[i1..(i2 - 1)]`, ..., `nums[ik-1..(n - 1)]`, then `ik-1 - i1 <= dist`.

Return the **minimum possible sum** of the cost of these subarrays.

---

## Examples

### Example 1
**Input:** `nums = [1,3,2,6,4,2], k = 3, dist = 3`  
**Output:** `5`  
**Explanation:**
- Best division: `[1,3]`, `[2,6,4]`, and `[2]`
- Starting indices: 0, 2, 5
- Check: i3-1 - i1 = 5 - 2 = 3 ≤ dist ✓
- Total cost: nums[0] + nums[2] + nums[5] = 1 + 2 + 2 = 5

### Example 2
**Input:** `nums = [10,1,2,2,2,1], k = 4, dist = 3`  
**Output:** `15`  
**Explanation:**
- Best division: `[10]`, `[1]`, `[2]`, and `[2,2,1]`
- Starting indices: 0, 1, 2, 3
- Check: i4-1 - i1 = 3 - 1 = 2 ≤ dist ✓
- Total cost: nums[0] + nums[1] + nums[2] + nums[3] = 10 + 1 + 2 + 2 = 15

### Example 3
**Input:** `nums = [10,8,18,9], k = 3, dist = 1`  
**Output:** `36`  
**Explanation:**
- Best division: `[10]`, `[8]`, and `[18,9]`
- Starting indices: 0, 1, 2
- Check: i3-1 - i1 = 2 - 1 = 1 ≤ dist ✓
- Total cost: nums[0] + nums[1] + nums[2] = 10 + 8 + 18 = 36

---

## Intuition

This problem extends the simpler version (3010) by adding:
1. Variable number of subarrays `k` (not fixed at 3)
2. Distance constraint `dist` between starting indices

### Key Observations:

1. **First cost is fixed**: The first subarray always starts at index 0, so `nums[0]` is always part of the cost (cannot be optimized).

2. **Choose k-1 starting positions**: We need to select `k-1` additional starting positions from indices `[1, n-1]` to minimize their sum.

3. **Distance constraint**: If `i1` is the start of the 2nd subarray and `ik-1` is the start of the kth subarray, then `ik-1 - i1 ≤ dist`.
   - This means all `k-1` starting positions must fit within a **window of size dist+1**
   - Window: `[i1, i1 + dist]` must contain all `k-1` starting indices

4. **Sliding window approach**: 
   - The 2nd subarray can start at any index `i` in range `[1, n-k+1]`
   - If 2nd subarray starts at `i`, we can choose `k-2` more starting positions from `[i+1, i+dist]`
   - Goal: Find the `k-2` smallest values in window `[i+1, min(i+dist, n-1)]`

5. **Maintain k-1 smallest in window**: Use a sliding window technique with two data structures to maintain the `k-1` smallest elements efficiently.

---

## Approach

### Sliding Window with Two Multisets/Heaps:

We maintain two sets/heaps:
- **Selected**: Contains the `k-1` smallest elements in the current window (these contribute to cost)
- **Candidates**: Contains the remaining elements in the window

As the window slides:
1. Add new element to the right
2. Remove element from the left (if it goes out of window)
3. Balance between Selected and Candidates to maintain k-1 smallest

### Algorithm Steps:

1. **Initialize**: 
   - Start with cost = `nums[0]` (fixed)
   - Initial window: indices `[1, 1+dist]`

2. **Build initial window**:
   - Add first `k-1` elements from `nums[1..min(1+dist, n-1)]` to Selected
   - Add remaining elements in range to Candidates

3. **Slide the window**:
   - For each possible starting position `i` of the 2nd subarray (from 1 to n-k+1):
     - Calculate sum of k-1 smallest in window `[i, min(i+dist, n-1)]`
     - Track minimum sum
     - Slide window: remove `nums[i]`, add `nums[i+dist+1]` if in bounds

4. **Maintain invariant**:
   - Selected always has k-1 smallest elements
   - When adding/removing, rebalance between Selected and Candidates

5. **Return**: `nums[0]` + minimum sum of k-1 elements

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log k)` — sliding window with balanced set operations (insert/delete/rebalance) |
| **Space** | `O(k + dist)` — storing elements in the window |

---

## Code (C++)

### Solution: Sliding Window with Multiset

```cpp
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long minCost = LLONG_MAX;
        
        // Two multisets: selected (k-1 smallest), candidates (rest)
        multiset<int> selected, candidates;
        long long selectedSum = 0;
        
        // Helper: Move largest from selected to candidates
        auto moveToCandidate = [&]() {
            auto it = prev(selected.end());
            candidates.insert(*it);
            selectedSum -= *it;
            selected.erase(it);
        };
        
        // Helper: Move smallest from candidates to selected
        auto moveToSelected = [&]() {
            auto it = candidates.begin();
            selected.insert(*it);
            selectedSum += *it;
            candidates.erase(it);
        };
        
        // Helper: Add element to appropriate set
        auto addElement = [&](int val) {
            if (selected.size() < k - 1) {
                selected.insert(val);
                selectedSum += val;
            } else if (val < *selected.rbegin()) {
                selectedSum += val;
                selected.insert(val);
                moveToCandidate();
            } else {
                candidates.insert(val);
            }
        };
        
        // Helper: Remove element from appropriate set
        auto removeElement = [&](int val) {
            if (selected.count(val)) {
                selected.erase(selected.find(val));
                selectedSum -= val;
                if (!candidates.empty()) {
                    moveToSelected();
                }
            } else {
                candidates.erase(candidates.find(val));
            }
        };
        
        // Initialize first window [1, min(1+dist, n-1)]
        for (int i = 1; i <= min(n - 1, 1 + dist); i++) {
            addElement(nums[i]);
        }
        
        minCost = selectedSum;
        
        // Slide window: move starting position of 2nd subarray
        for (int i = 2; i <= n - k + 1; i++) {
            // Remove element going out of window (left side)
            removeElement(nums[i - 1]);
            
            // Add element coming into window (right side)
            int rightIdx = i + dist;
            if (rightIdx < n) {
                addElement(nums[rightIdx]);
            }
            
            // Update minimum if we have k-1 elements selected
            if (selected.size() == k - 1) {
                minCost = min(minCost, selectedSum);
            }
        }
        
        return nums[0] + minCost;
    }
};
```

### Solution 2: Using Priority Queues (Alternative)

```cpp
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        
        // Min heap for selected k-1 smallest (but store as max heap for easy access to max)
        priority_queue<int> selected; // max heap
        // Min heap for candidates
        priority_queue<int, vector<int>, greater<int>> candidates; // min heap
        
        long long selectedSum = 0;
        long long minCost = LLONG_MAX;
        
        // Track elements in current window
        map<int, int> windowCount;
        
        auto addToWindow = [&](int idx) {
            windowCount[nums[idx]]++;
            if (selected.size() < k - 1) {
                selected.push(nums[idx]);
                selectedSum += nums[idx];
            } else if (nums[idx] < selected.top()) {
                selectedSum -= selected.top();
                candidates.push(selected.top());
                selected.pop();
                selected.push(nums[idx]);
                selectedSum += nums[idx];
            } else {
                candidates.push(nums[idx]);
            }
        };
        
        auto removeFromWindow = [&](int idx) {
            windowCount[nums[idx]]--;
            if (windowCount[nums[idx]] == 0) {
                windowCount.erase(nums[idx]);
            }
        };
        
        // Build initial window
        for (int i = 1; i <= min(n - 1, 1 + dist); i++) {
            addToWindow(i);
        }
        
        // Clean and update
        while (!selected.empty() && windowCount.find(selected.top()) == windowCount.end()) {
            selected.pop();
        }
        
        minCost = selectedSum;
        
        // Sliding window
        for (int i = 2; i <= n - k + 1; i++) {
            removeFromWindow(i - 1);
            if (i + dist < n) {
                addToWindow(i + dist);
            }
            
            // Rebalance and calculate cost
            // (Implementation details omitted for brevity)
            minCost = min(minCost, selectedSum);
        }
        
        return nums[0] + minCost;
    }
};
```

---

## Key Takeaways

1. **Fixed vs variable optimization**: When part of the answer is fixed (nums[0]), focus optimization efforts on the variable parts.

2. **Sliding window with k smallest**: Maintaining the k smallest elements in a sliding window requires two data structures (selected + candidates) with rebalancing.

3. **Constraint interpretation**: "ik-1 - i1 ≤ dist" means all k-1 starting positions (excluding the first at index 0) must fit within a window of size dist+1.

4. **Multiset for dynamic ordering**: C++ multiset allows efficient insertion, deletion, and access to min/max elements, making it ideal for maintaining k smallest elements.

5. **Balanced invariant**: Always maintain exactly k-1 elements in the "selected" set, moving elements between selected and candidates as needed.

6. **Window size management**: The effective window is `[i, min(i+dist, n-1)]` where i is the starting position of the 2nd subarray.

7. **Greedy within constraint**: Unlike the simple version (k=3), we can't just pick k-1 smallest from entire array; must respect the distance constraint.

8. **Problem progression**: This is a natural extension of problem 3010, adding complexity through variable k and distance constraint.

---
