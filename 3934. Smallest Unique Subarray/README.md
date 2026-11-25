# 3934. Smallest Unique Subarray

**Difficulty:** `Hard`  
**Tags:** `Array`, `Hash Table`, `Binary Search`, `Rolling Hash`, `Suffix Array`, `Hash Function`

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

[LeetCode — 3934. Smallest Unique Subarray](https://leetcode.com/problems/smallest-unique-subarray/)

---

## Problem Summary

The problem requires finding the minimum length of a subarray that is unique within the given array, meaning no other subarray of the same length shares the exact same elements. The solution employs a binary search strategy to efficiently determine this minimum length by checking for unique subarrays at different lengths.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to use a rolling hash to represent subarrays. By hashing each subarray and storing the counts in a map, we can quickly identify if a subarray is unique (count == 1). The binary search allows us to narrow down the search space for the minimum length where a unique subarray exists.

---

## Approach

1. Perform a binary search on the potential subarray lengths (from 1 to n).
2. For each candidate length, calculate the hash of all subarrays of that length using a rolling hash technique.
3. Store the hash values in a map to count occurrences. If any hash appears only once, the subarray is unique.
4. If a unique subarray is found at the current length, update the result and search for smaller lengths. Otherwise, search for larger lengths.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — The binary search runs in O(log n) iterations. Within each iteration, the rolling hash calculation and map update take O(n) time, leading to an overall complexity of O(n log n). |
| **Space** | `O(n)` — The space complexity is dominated by the hash map used to store the counts of the subarray hashes, which can contain up to n entries in the worst case. |

---

## Code (C++)

```cpp
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;

    // Binary exponentiation
    ll findPower(ll a, ll base) {
        if (base == 0) {
            return 1;
        }

        ll half = findPower(a, base / 2);
        ll result = (half * half) % MOD;
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    bool check(vector<int>& nums, int size, int base) {
        int n = nums.size();

        ll hash = 0;
        unordered_map<ll, int> mp;

        ll p = findPower(base, size-1); //O(log(size))

        int i = 0;
        int j = 0;

        while(j < n) { //O(n)
            hash = (hash * base + nums[j]) % MOD;

            if(j-i+1 < size) {
                j++;
            } else {
                mp[hash]++;

                hash = (hash - (p * nums[i])%MOD + MOD) % MOD;

                i++;
                j++;
            }
        }

        for(auto &it : mp) {
            if(it.second == 1) {
                return true;
            }
        }

        return false;

    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int base = *max_element(begin(nums), end(nums)) + 1;

        int l = 1;
        int r = n;

        int result = n;

        while(l <= r) { //log(n)
            int mid = l + (r-l)/2;

            if(check(nums, mid, base)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};
```

---

## Key Takeaways

- Rolling hashes are an efficient way to compare substrings or subarrays.
- Binary search is a powerful technique for finding optimal parameters when a decision boundary exists.
- The choice of base for the hash function is critical; it should be larger than the maximum element in the array to ensure distinct hashing.
