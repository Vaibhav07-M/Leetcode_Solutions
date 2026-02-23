# 1461. Check If a String Contains All Binary Codes of Size K

**Difficulty:** `Medium`  
**Tags:** `String, Hash Table, Bit Manipulation, Rolling Hash`

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

[LeetCode — 1461. Check If a String Contains All Binary Codes of Size K](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)

---

## Problem Summary

Given a binary string `s` and an integer `k`, return `true` if every binary code of length `k` is a substring of `s`. Otherwise, return `false`.

In other words, check if all possible binary combinations of length `k` (from `"000...0"` to `"111...1"`) appear as substrings in `s`.

---

## Examples

### Example 1
**Input:** `s = "00110110", k = 2`  
**Output:** `true`  
**Explanation:**  
The binary codes of length 2 are `"00"`, `"01"`, `"10"` and `"11"`.  
They can all be found as substrings at indices 0, 1, 3 and 2 respectively.

### Example 2
**Input:** `s = "0110", k = 1`  
**Output:** `true`  
**Explanation:**  
The binary codes of length 1 are `"0"` and `"1"`.  
It is clear that both exist as substrings.

### Example 3
**Input:** `s = "0110", k = 2`  
**Output:** `false`  
**Explanation:**  
The binary code `"00"` is of length 2 and does not exist in the string.

---

## Intuition

We need to check if all 2^k possible binary codes of length k exist as substrings in s.

**Key observations:**
- Total possible binary codes of length k = 2^k
- For k=2: need 4 codes (`"00"`, `"01"`, `"10"`, `"11"`)
- For k=3: need 8 codes (`"000"`, `"001"`, ..., `"111"`)
- We can use a sliding window of size k to extract all k-length substrings
- Use a hash set to track which codes we've seen
- If we collect 2^k distinct codes, return true

**Optimization:**
- Instead of storing string substrings, convert k-bit windows to integers (0 to 2^k-1)
- Use rolling hash / bit manipulation to efficiently compute window values
- Use boolean array or bitset instead of hash set for O(1) lookup
- Early exit when we've found all 2^k codes

---

## Approach

### Solution 1: Hash Set with Substrings

1. **Check feasibility**: If `s.length() < k`, impossible to have substrings of length k
2. **Calculate need**: Total codes needed = 2^k
3. **Sliding window**:
   - Extract all substrings of length k
   - Insert each into a hash set
   - If set size reaches 2^k, return true
4. **Return** whether set size equals 2^k

### Solution 2: Rolling Hash with Boolean Array (Optimal)

1. **Initialize**: 
   - `need = 1 << k` (= 2^k)
   - Boolean array `seen[need]` initialized to false
   - `mask` to track current window value
2. **Build first window**: Convert first k characters to integer
3. **Slide window**:
   - For each position, compute k-bit integer value
   - Mark `seen[value] = true`
   - Count distinct codes
   - Early exit if count == need
4. **Rolling hash technique**:
   - Remove leftmost bit: `mask = (mask << 1) & ((1 << k) - 1)`
   - Add rightmost bit: `mask |= (s[i] - '0')`

### Solution 3: Optimized with Direct Indexing

Similar to Solution 2 but directly index into boolean array without separate counter.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * k)` for hash set approach, `O(n)` for rolling hash — where n = s.length() |
| **Space** | `O(min(2^k, n-k+1))` for hash set, `O(2^k)` for boolean array |

**Note:** With rolling hash and bit manipulation, time complexity approaches O(n) as we avoid string operations.

---

## Code (C++)

### Solution 1: Hash Set with Substrings

```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        
        int need = 1 << k;  // 2^k
        unordered_set<string> seen;
        
        for(int i = 0; i <= n - k; i++) {
            seen.insert(s.substr(i, k));
            if(seen.size() == need) return true;
        }
        
        return seen.size() == need;
    }
};
```

### Solution 2: Rolling Hash with Boolean Array (Optimal)

```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        
        int need = 1 << k;               // total possible codes = 2^k
        vector<bool> seen(need, false);
        int count = 0;
        
        // Build first window
        int mask = 0;
        for(int i = 0; i < k; i++) {
            mask = (mask << 1) | (s[i] - '0');
        }
        seen[mask] = true;
        count++;
        
        // Slide window
        int maskBits = (1 << k) - 1;  // k bits set to 1
        for(int i = k; i < n; i++) {
            // Remove leftmost bit and add new rightmost bit
            mask = ((mask << 1) & maskBits) | (s[i] - '0');
            
            if(!seen[mask]) {
                seen[mask] = true;
                count++;
                if(count == need) return true;  // early exit
            }
        }
        
        return false;
    }
};
```

### Solution 3: Single Pass Rolling Hash

```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n - k + 1 < (1 << k)) return false;  // not enough substrings
        
        int need = 1 << k;
        unordered_set<int> seen;
        int mask = 0;
        int allBits = (1 << k) - 1;
        
        for(int i = 0; i < n; i++) {
            mask = ((mask << 1) & allBits) | (s[i] - '0');
            
            if(i >= k - 1) {
                seen.insert(mask);
                if(seen.size() == need) return true;
            }
        }
        
        return false;
    }
};
```

### Solution 4: Bitset Optimization

```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        
        int need = 1 << k;
        if(n - k + 1 < need) return false;
        
        vector<bool> seen(need, false);
        int mask = 0;
        int allBits = need - 1;
        int count = 0;
        
        for(int i = 0; i < k - 1; i++) {
            mask = (mask << 1) | (s[i] - '0');
        }
        
        for(int i = k - 1; i < n; i++) {
            mask = ((mask << 1) & allBits) | (s[i] - '0');
            
            if(!seen[mask]) {
                seen[mask] = true;
                if(++count == need) return true;
            }
        }
        
        return false;
    }
};
```

### Solution 5: Compact Version

```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        
        unordered_set<string> codes;
        for(int i = 0; i <= s.size() - k; i++) {
            codes.insert(s.substr(i, k));
        }
        
        return codes.size() == (1 << k);
    }
};
```

---

## Key Takeaways

- **Problem type**: Substring enumeration with completeness check
- **Total possibilities**: For k bits, there are exactly 2^k unique binary codes
- **Sliding window**: Extract all k-length substrings efficiently
- **Rolling hash advantage**: 
  - Avoid repeated substring creation (O(k) per extraction)
  - Use bit manipulation for O(1) window updates
  - Convert binary string to integer: `mask = (mask << 1) | bit`
- **Bit manipulation tricks**:
  - `1 << k` = 2^k
  - `(1 << k) - 1` = mask with k bits set to 1
  - `(mask << 1) & maskBits` = shift left and keep only k bits
  - `| (s[i] - '0')` = add new bit at LSB
- **Space optimization**: Boolean array of size 2^k vs hash set
  - Boolean array: O(1) access, fixed space
  - Hash set: More flexible but slower with overhead
- **Early termination**: Return true as soon as we've seen all 2^k codes
- **Feasibility check**: 
  - If `s.length() < k`, impossible
  - If `s.length() - k + 1 < 2^k`, not enough substrings (optional optimization)
- **Alternative approaches**:
  - Store actual substring strings (slower, O(k) per operation)
  - Convert substrings to integers (faster, O(1) with rolling hash)
  - Use bitset for space-efficient boolean array
- **Trade-offs**:
  - String hash set: Simple but slower (O(k) string operations)
  - Integer with boolean array: Faster (O(1) operations) but requires 2^k space
  - Hash set of integers: Balance between space and time
- **Edge cases**:
  - k = 1: only need "0" and "1"
  - k larger than reasonable: 2^k might be huge (k ≤ 20 per constraints)
  - String too short: s.length() < k returns false immediately
- **Rolling hash formula**: 
  - New window = `((old << 1) & mask) | new_bit`
  - Removes oldest bit and adds newest bit in O(1)
- **Counting optimization**: Track count and early exit vs checking set size at end
- **Constraint analysis**: With k ≤ 20, maximum 2^k = 1,048,576, so boolean array is feasible

