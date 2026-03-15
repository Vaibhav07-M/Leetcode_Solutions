# 1622. Fancy Sequence

**Difficulty:** `Hard`  
**Tags:** `Design`, `Math`, `Segment Tree`

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

[LeetCode - 1622. Fancy Sequence](https://leetcode.com/problems/fancy-sequence/)

---

## Problem Summary

Design a sequence API supporting these operations under modulo `1e9 + 7`:
- `append(val)`: append value to end
- `addAll(inc)`: add `inc` to all existing values
- `multAll(m)`: multiply all existing values by `m`
- `getIndex(idx)`: return value at index `idx`, or `-1` if out of bounds

Up to `1e5` total operations are made, so updates over all elements per query are too slow.

---

## Examples

### Example 1
**Input:**
`["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]`  
`[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]`

**Output:**
`[null, null, null, null, null, 10, null, null, null, 26, 34, 20]`

---

## Intuition

All operations on existing values are affine transforms of the form:

`value -> value * mul + add (mod MOD)`

Instead of updating every stored element on `addAll`/`multAll`, keep global lazy parameters:
- `mul`: global multiplier
- `add`: global additive shift

When appending a new value, store its normalized base form so that applying current transform recovers original appended value later.

To normalize during `append(val)`:

`stored = (val - add) / mul (mod MOD)`

Division under modulo is done using modular inverse (Fermat):

`mul^{-1} = mul^(MOD-2) mod MOD`

Then `getIndex(idx)` simply re-applies the current global transform to stored base.

---

## Approach

1. Maintain:
- `arr`: normalized base values
- `mul = 1`, `add = 0`
2. `addAll(inc)`:
- `add = (add + inc) % MOD`
3. `multAll(m)`:
- `mul = (mul * m) % MOD`
- `add = (add * m) % MOD`
4. `append(val)`:
- compute inverse of current `mul`
- push normalized value `((val - add) * invMul) % MOD`
5. `getIndex(idx)`:
- if out of bounds return `-1`
- return `(arr[idx] * mul + add) % MOD`

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **append** | `O(log MOD)` (modular inverse via fast exponentiation) |
| **addAll** | `O(1)` |
| **multAll** | `O(1)` |
| **getIndex** | `O(1)` |
| **Space** | `O(n)` for stored elements |

---

## Code (C++)

### Solution 1 - Lazy Affine Transform + Modular Inverse (Submitted)

```cpp
class Fancy {
public:
    const long long MOD = 1e9+7;

    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modInverse(long long x){
        long long res = 1;
        long long power = MOD-2;

        while(power){
            if(power & 1) res = (res*x)%MOD;
            x = (x*x)%MOD;
            power >>= 1;
        }

        return res;
    }

    Fancy() {}

    void append(int val) {
        long long inv = modInverse(mul);
        long long x = ((val - add + MOD) % MOD * inv) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;

        long long val = (arr[idx]*mul + add) % MOD;
        return val;
    }
};
```

---

## Key Takeaways

- Keep global lazy affine parameters instead of updating all elements.
- Normalize appended values using modular inverse of current multiplier.
- This makes range-wide updates constant time and queries efficient.
