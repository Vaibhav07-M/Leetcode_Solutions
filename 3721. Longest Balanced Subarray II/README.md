# 3721. Longest Balanced Subarray II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Hash Table`, `Sliding Window`, `Segment Tree`, `Prefix Sum`

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

[LeetCode — 3721. Longest Balanced Subarray II](https://leetcode.com/problems/longest-balanced-subarray-ii/)

---

## Problem Summary

You are given an integer array `nums`.

A subarray is called **balanced** if the number of **distinct even numbers** in the subarray is equal to the number of **distinct odd numbers**.

Return the **length of the longest balanced subarray**.

**Note:** This is the **Hard** version with larger constraints (`n ≤ 10^5`) compared to problem 3719.

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

Unlike the Medium version (3719), where `n ≤ 1500` allows O(n²) brute force, this Hard version requires `n ≤ 10^5`, demanding O(n log n) or O(n) solutions.

**Key Insight:** Transform the problem using a **difference array** approach:
- Treat each **distinct even** number as `+1`
- Treat each **distinct odd** number as `-1`
- A balanced subarray has equal distinct even/odd counts → cumulative difference = 0

**Challenge:** When a number appears multiple times, only the **first occurrence** counts as "distinct". We need to handle duplicates by "undoing" previous contributions.

**Solution:** Use a **Segment Tree with Lazy Propagation** to:
1. Efficiently perform range updates when we see duplicates
2. Query for the leftmost position where cumulative difference equals 0

---

## Approach

### Approach: Segment Tree with Lazy Propagation

**Transform the problem:**
1. Assign `+1` to even numbers, `-1` to odd numbers
2. Maintain a cumulative "balance" array where balance[i] = count(distinct even) - count(distinct odd) in [0, i]
3. A balanced subarray [l, r] exists when balance[r] - balance[l-1] = 0, or balance at position l is 0

**Handle duplicates:**
- When we see `nums[r]` again at position `r` (previously at position `prev`):
  - The contribution from position `prev` should be removed from all positions [0, prev]
  - Add the new contribution at position `r` to all positions [0, r]

**Segment Tree Operations:**
1. **Range Update:** Add a value to a range [l, r] (lazy propagation)
2. **Range Query:** Find leftmost position where cumulative difference = 0

**Algorithm:**
```
1. Initialize segment tree (min, max, lazy) of size 4n
2. Use hash map to track last position of each number
3. For each position r:
   a. val = (nums[r] is even) ? +1 : -1
   b. If nums[r] seen before at position prev:
      - updateRange(0, prev, -val)  // Remove old contribution
   c. updateRange(0, r, val)  // Add new contribution
   d. Find leftmost position l where balance = 0
   e. Update max length as (r - l + 1)
   f. Update map: mp[nums[r]] = r
4. Return max length
```

---

## Complexity

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| **Segment Tree + Lazy Propagation** | `O(n log n)` | `O(n)` |

- **Time:** Each of n elements performs O(log n) segment tree operations
- **Space:** Segment tree (4n nodes) + hash map (n entries)

---

## Code (C++)

### Solution 1: Segment Tree with Lazy Propagation

```cpp
class Solution {
public:
    vector<int> segMin, segMax, lazy;
    int n;

    void propagate(int i, int l, int r) {
        if (lazy[i] != 0) {
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];

            if (l != r) {
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    // Range add val to [start, end]
    void updateRange(int start, int end, int i, int l, int r, int val) {
        propagate(i, l, r);

        if (l > end || r < start) return;

        // [start...end] is fully inside range of current node [l..r]
        if (l >= start && r <= end) {
            lazy[i] += val;
            propagate(i, l, r);
            return;
        }

        int mid = (l + r) / 2;
        updateRange(start, end, 2*i+1, l, mid, val);
        updateRange(start, end, 2*i+2, mid+1, r, val);

        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }

    int findLeftMostZero(int i, int l, int r) {
        propagate(i, l, r);

        if(segMin[i] > 0 || segMax[i] < 0) {
            return -1;
        }

        if(l == r) {
            return l;
        }

        int mid = l + (r-l)/2;
        int leftResult = findLeftMostZero(2*i+1, l, mid);
        if(leftResult != -1)
            return leftResult;
        
        return findLeftMostZero(2*i+2, mid+1, r);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        segMin.assign(4*n, 0);
        segMax.assign(4*n, 0);
        lazy.assign(4*n, 0);

        int maxL = 0;
        unordered_map<int, int> mp;

        for(int r = 0; r < n; r++) {
            int val = (nums[r] % 2 == 0) ? 1 : -1;

            int prev = -1;
            if(mp.count(nums[r])) {
                prev = mp[nums[r]];
            }

            if(prev != -1) {
                // Remove old contribution from [0, prev]
                updateRange(0, prev, 0, 0, n-1, -val);
            }

            // Add new contribution to [0, r]
            updateRange(0, r, 0, 0, n-1, val);

            // Find leftmost position where balance = 0
            int l = findLeftMostZero(0, 0, n-1);
            if(l != -1)
                maxL = max(maxL, r-l+1);

            mp[nums[r]] = r;
        }

        return maxL;
    }
};
```

---

### Solution 2: Simplified with Comments

```cpp
class Solution {
public:
    vector<int> segMin, segMax, lazy;
    int n;

    void propagate(int idx, int left, int right) {
        if (lazy[idx]) {
            segMin[idx] += lazy[idx];
            segMax[idx] += lazy[idx];
            if (left != right) {
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(int start, int end, int idx, int left, int right, int delta) {
        propagate(idx, left, right);
        if (left > end || right < start) return;
        
        if (left >= start && right <= end) {
            lazy[idx] += delta;
            propagate(idx, left, right);
            return;
        }

        int mid = (left + right) / 2;
        update(start, end, 2*idx+1, left, mid, delta);
        update(start, end, 2*idx+2, mid+1, right, delta);
        
        segMin[idx] = min(segMin[2*idx+1], segMin[2*idx+2]);
        segMax[idx] = max(segMax[2*idx+1], segMax[2*idx+2]);
    }

    int findLeftZero(int idx, int left, int right) {
        propagate(idx, left, right);
        if (segMin[idx] > 0 || segMax[idx] < 0) return -1;
        if (left == right) return left;
        
        int mid = left + (right - left) / 2;
        int res = findLeftZero(2*idx+1, left, mid);
        return (res != -1) ? res : findLeftZero(2*idx+2, mid+1, right);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        segMin.resize(4*n, 0);
        segMax.resize(4*n, 0);
        lazy.resize(4*n, 0);

        int ans = 0;
        unordered_map<int, int> lastPos;

        for (int r = 0; r < n; r++) {
            int val = (nums[r] & 1) ? -1 : 1;  // Odd: -1, Even: +1
            
            if (lastPos.count(nums[r])) {
                int prev = lastPos[nums[r]];
                update(0, prev, 0, 0, n-1, -val);
            }
            
            update(0, r, 0, 0, n-1, val);
            
            int l = findLeftZero(0, 0, n-1);
            if (l != -1) ans = max(ans, r - l + 1);
            
            lastPos[nums[r]] = r;
        }

        return ans;
    }
};
```

---

### Solution 3: Compact Version

```cpp
class Solution {
public:
    vector<int> mn, mx, lz;
    int n;

    void prop(int i, int l, int r) {
        if (lz[i]) {
            mn[i] += lz[i]; mx[i] += lz[i];
            if (l < r) { lz[2*i+1] += lz[i]; lz[2*i+2] += lz[i]; }
            lz[i] = 0;
        }
    }

    void upd(int s, int e, int i, int l, int r, int v) {
        prop(i, l, r);
        if (l > e || r < s) return;
        if (l >= s && r <= e) { lz[i] += v; prop(i, l, r); return; }
        int m = (l + r) / 2;
        upd(s, e, 2*i+1, l, m, v);
        upd(s, e, 2*i+2, m+1, r, v);
        mn[i] = min(mn[2*i+1], mn[2*i+2]);
        mx[i] = max(mx[2*i+1], mx[2*i+2]);
    }

    int find(int i, int l, int r) {
        prop(i, l, r);
        if (mn[i] > 0 || mx[i] < 0) return -1;
        if (l == r) return l;
        int m = l + (r - l) / 2;
        int res = find(2*i+1, l, m);
        return res != -1 ? res : find(2*i+2, m+1, r);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        mn.assign(4*n, 0); mx.assign(4*n, 0); lz.assign(4*n, 0);
        int ans = 0;
        unordered_map<int, int> pos;
        for (int r = 0; r < n; r++) {
            int v = (nums[r] & 1) ? -1 : 1;
            if (pos.count(nums[r])) upd(0, pos[nums[r]], 0, 0, n-1, -v);
            upd(0, r, 0, 0, n-1, v);
            int l = find(0, 0, n-1);
            if (l != -1) ans = max(ans, r - l + 1);
            pos[nums[r]] = r;
        }
        return ans;
    }
};
```

---

## Key Takeaways

- **Constraint-driven approach:** O(n²) works for n ≤ 1500, but n ≤ 10^5 requires O(n log n)
- **Problem transformation:** Convert "equal distinct counts" to "cumulative difference = 0"
- **Segment Tree mastery:** Lazy propagation enables efficient range updates in O(log n)
- **Duplicate handling:** Track last position of each value to "undo" previous contributions
- **Binary representation trick:** Use `nums[r] & 1` instead of `nums[r] % 2` for even/odd check
- **Range query optimization:** Find leftmost zero by checking min/max bounds in segment tree
- **Space-time tradeoff:** 4n space for segment tree enables O(log n) operations
- **Related problems:** Range sum queries, subarray with target sum, distinct element queries
- **Advanced data structures:** Segment trees shine when multiple range updates/queries needed
- **From Medium to Hard:** Same problem logic, different algorithmic complexity required
- Segment tree template: Store min/max for range queries, lazy array for deferred updates
- **Greedy insight:** Process left-to-right, always extend to rightmost valid position
- **Hash map usage:** O(1) lookup for duplicate detection and position tracking

---
