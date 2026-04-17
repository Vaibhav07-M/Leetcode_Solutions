# 3761. Minimum Absolute Distance Between Mirror Pairs

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Math`

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

[LeetCode - 3761. Minimum Absolute Distance Between Mirror Pairs](https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/)

---

## Problem Summary

Given an integer array `nums`, a mirror pair `(i, j)` satisfies:
- `0 <= i < j < nums.length`
- `reverse(nums[i]) == nums[j]`

where `reverse(x)` is the digit-reversed integer (leading zeros dropped, e.g. `reverse(120) = 21`).

Return the minimum `abs(i - j)` over all mirror pairs, or `-1` if none exists.

---

## Examples

### Example 1
**Input:** `nums = [12,21,45,33,54]`  
**Output:** `1`

**Explanation:**
- `(0,1)` is valid since `reverse(12)=21`, distance `1`
- `(2,4)` is valid since `reverse(45)=54`, distance `2`
- Minimum is `1`

### Example 2
**Input:** `nums = [120,21]`  
**Output:** `1`

### Example 3
**Input:** `nums = [21,120]`  
**Output:** `-1`

---

## Intuition

While scanning left to right, index `i` can pair only with an earlier index `j` where:

`reverse(nums[j]) == nums[i]`

So if we store the latest position of every reversed value seen so far, we can immediately check whether current `nums[i]` closes a mirror pair and update the best distance.

---

## Approach

1. Maintain a hash map `last_mirror_pos`:
   - key = reversed value of a previously seen number
   - value = latest index where that reverse was produced
2. For each index `i`:
   - If `nums[i]` exists in `last_mirror_pos`, update answer with `i - last_mirror_pos[nums[i]]`.
   - Compute `reverse(nums[i])` and set `last_mirror_pos[reverse(nums[i])] = i`.
3. If answer was never updated, return `-1`; otherwise return the minimum distance.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * d)` where `d` is digits per number (at most 10), effectively `O(n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dist = n + 1; // Initialize with a value larger than any possible distance
        unordered_map<int, int> last_mirror_pos;

        auto get_reverse = [](int x) {
            int rev = 0;
            while (x > 0) {
                rev = rev * 10 + (x % 10);
                x /= 10;
            }
            return rev;
        };

        for (int i = 0; i < n; ++i) {
            // If the current number matches a previously recorded reverse(nums[j])
            if (last_mirror_pos.count(nums[i])) {
                min_dist = min(min_dist, i - last_mirror_pos[nums[i]]);
            }

            // Store the current number's reverse and its index i
            // This allows future nums[j] to find its mirror at index i
            last_mirror_pos[get_reverse(nums[i])] = i;
        }

        return (min_dist > n) ? -1 : min_dist;
    }
};
```

---

## Key Takeaways

- Convert pair matching into hash lookups by storing reversed forms.
- Storing the latest matching index minimizes future distance checks.
- One left-to-right pass is enough after using the map.