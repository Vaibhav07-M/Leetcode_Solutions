# 3510. Minimum Pair Removal to Sort Array II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Heap (Priority Queue)`, `Greedy`, `Simulation`

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

[LeetCode — 3510. Minimum Pair Removal to Sort Array II](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/)

---

## Problem Summary

Given an array `nums`, you can perform the following operation any number of times:
- Select the adjacent pair with the **minimum sum** in `nums`
- If multiple such pairs exist, choose the **leftmost one**
- Replace the pair with their sum

Return the **minimum number of operations** needed to make the array non-decreasing.

An array is non-decreasing if each element is greater than or equal to its previous element.

**Note:** This is the hard version with constraints up to `10⁵` elements.

---

## Examples

### Example 1
**Input:** `nums = [5,2,3,1]`  
**Output:** `2`  
**Explanation:**
- Operation 1: Pair (3,1) has minimum sum 4 → `nums = [5,2,4]`
- Operation 2: Pair (2,4) has minimum sum 6 → `nums = [5,6]`
- Array is now non-decreasing in 2 operations

### Example 2
**Input:** `nums = [1,2,2]`  
**Output:** `0`  
**Explanation:**
- Array is already non-decreasing

---

## Intuition

The Easy version (3507) with n ≤ 50 allowed O(n³) brute force simulation. With n ≤ 10⁵, we need a more efficient approach.

**Key insights:**
1. We need to efficiently find the minimum sum adjacent pair (leftmost if tie)
2. After each merge, we need to update adjacent pairs
3. A **min-heap (priority queue)** can track all adjacent pairs by (sum, index)
4. We need to handle invalidated pairs when elements are merged

**Challenges:**
- Tracking which elements still exist after merges
- Efficiently finding leftmost minimum sum pair
- Updating adjacent pairs after each operation

---

## Approach

### Optimized Strategy using Heap:

1. **Initialize:**
   - Use a min-heap to store all adjacent pairs as `(sum, index)`
   - Use a data structure to track which indices are still valid
   - Store actual array values separately

2. **Process operations:**
   - Pop minimum from heap
   - Check if both elements still exist (not merged away)
   - If valid, merge the pair:
     - Update the value at first index
     - Mark second index as invalid
     - Add new adjacent pairs to heap (with neighbors)
     - Increment operation count

3. **Termination:**
   - Stop when array is non-decreasing
   - Check after each merge if sorting achieved

### Data Structures:
- **Priority Queue:** Store `(sum, leftIndex)` ordered by sum, then index
- **Set/Map:** Track valid indices
- **Array/Vector:** Store current values

### Algorithm:
```cpp
// Build initial heap with all adjacent pairs
for i from 0 to n-2:
    heap.push({nums[i] + nums[i+1], i})

operations = 0
while not sorted:
    // Get minimum sum pair
    auto [sum, idx] = heap.top()
    heap.pop()
    
    // Check if pair still valid
    if idx and idx+1 not merged:
        // Merge pair
        nums[idx] = sum
        mark nums[idx+1] as invalid
        
        // Add new adjacent pairs
        if valid neighbor on left:
            heap.push({nums[left] + nums[idx], left})
        if valid neighbor on right:
            heap.push({nums[idx] + nums[right], idx})
        
        operations++
```

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n² log n)` — worst case n operations × log n heap operations |
| **Space** | `O(n)` — for heap and tracking structures |

**Optimization notes:**
- Each merge reduces array size by 1
- Heap operations are O(log n)
- Checking sorted status can be optimized with lazy evaluation

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        // Check if already sorted
        if (isSorted(nums)) return 0;
        
        int operations = 0;
        
        // Min heap: {sum, index}
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<>> pq;
        
        // Track valid indices
        set<int> valid;
        for (int i = 0; i < n; i++) {
            valid.insert(i);
        }
        
        // Initialize heap with all adjacent pairs
        for (int i = 0; i < n - 1; i++) {
            pq.push({(long long)nums[i] + nums[i + 1], i});
        }
        
        while (!isSortedSet(nums, valid)) {
            // Get minimum sum pair
            auto [sum, idx] = pq.top();
            pq.pop();
            
            // Check if both elements still valid
            if (valid.find(idx) == valid.end() || 
                valid.find(idx + 1) == valid.end()) {
                continue;
            }
            
            // Find actual next valid index
            auto it = valid.find(idx);
            auto nextIt = next(it);
            if (nextIt == valid.end()) continue;
            
            int nextIdx = *nextIt;
            
            // Verify this is the correct pair
            if (nums[idx] + nums[nextIdx] != sum) continue;
            
            // Merge the pair
            nums[idx] = sum;
            valid.erase(nextIdx);
            operations++;
            
            // Add new adjacent pairs
            if (it != valid.begin()) {
                auto prevIt = prev(it);
                int prevIdx = *prevIt;
                pq.push({(long long)nums[prevIdx] + nums[idx], prevIdx});
            }
            
            auto afterIt = valid.find(idx);
            if (afterIt != valid.end() && next(afterIt) != valid.end()) {
                int afterIdx = *next(afterIt);
                pq.push({(long long)nums[idx] + nums[afterIdx], idx});
            }
        }
        
        return operations;
    }
    
private:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
    
    bool isSortedSet(vector<int>& nums, set<int>& valid) {
        if (valid.size() <= 1) return true;
        
        auto it = valid.begin();
        int prev = *it;
        ++it;
        
        while (it != valid.end()) {
            int curr = *it;
            if (nums[curr] < nums[prev]) return false;
            prev = curr;
            ++it;
        }
        return true;
    }
};
```

### Alternative Implementation with List:

```cpp
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        
        // Use list for efficient removal
        list<long long> arr(nums.begin(), nums.end());
        
        int operations = 0;
        
        while (!isSorted(arr)) {
            // Find minimum sum adjacent pair
            long long minSum = LLONG_MAX;
            auto minIt = arr.end();
            
            for (auto it = arr.begin(); it != arr.end(); ++it) {
                auto next_it = next(it);
                if (next_it == arr.end()) break;
                
                long long sum = *it + *next_it;
                if (sum < minSum) {
                    minSum = sum;
                    minIt = it;
                }
            }
            
            // Merge the pair
            auto next_it = next(minIt);
            *minIt = minSum;
            arr.erase(next_it);
            operations++;
        }
        
        return operations;
    }
    
private:
    bool isSorted(list<long long>& arr) {
        if (arr.size() <= 1) return true;
        
        auto it = arr.begin();
        long long prev = *it;
        ++it;
        
        while (it != arr.end()) {
            if (*it < prev) return false;
            prev = *it;
            ++it;
        }
        return true;
    }
};
```

---

## Key Takeaways

1. **Heap optimization** — Use priority queue to efficiently find minimum sum pairs
2. **Index tracking** — Need to maintain which elements are still valid after merges
3. **Leftmost tie-breaking** — When sums are equal, choose pair with smallest index
4. **Long long for sums** — With values up to 10⁹, sums can overflow int
5. **Lazy invalidation** — Skip invalid pairs when popped from heap
6. **Set for tracking** — Ordered set helps find adjacent valid elements
7. **List alternative** — Using std::list allows O(1) removal but O(n) search
8. **Trade-offs** — Heap approach has better worst-case but more complex implementation

---
