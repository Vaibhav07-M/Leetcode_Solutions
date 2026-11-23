# 1352. Product of the Last K Numbers

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`, `Design`, `Data Stream`, `Prefix Sum`

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

[LeetCode — 1352. Product of the Last K Numbers](https://leetcode.com/problems/product-of-the-last-k-numbers/)

---

## Problem Summary

The problem requires designing a data structure to efficiently track the product of the last k integers in a stream. The solution uses a vector to store cumulative products, allowing for fast retrieval of the product of any contiguous segment by dividing the current total product by the product of the segment before the desired range.

---

## Examples

_No examples provided._

---

## Intuition

By maintaining a running product (cumulative product) in the vector, we can avoid re-calculating the product from scratch every time. The key insight is that the product of the last k numbers is simply the current total product divided by the product of the numbers before the last k (i.e., nums[n-1] / nums[n-k-1]). This leverages the property of multiplication being associative and commutative.

---

## Approach

1. Initialize an empty vector 'nums' to store cumulative products and a counter 'n' to track the number of elements.
2. In the 'add' method, if the new number is 0, reset the vector and counter, as 0 multiplies everything to 0. Otherwise, append the product of the new number and the previous cumulative product to the vector.
3. In the 'getProduct' method, check if k is larger than the current size; if so, return 0. If k equals the size, return the last element of the vector. Otherwise, return the last element divided by the element at index n-k-1 to get the product of the last k numbers.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(1)` — Both the 'add' and 'getProduct' operations involve constant-time lookups and arithmetic operations on the vector. The 'add' operation appends one element, and 'getProduct' performs a division and a lookup, both of which are O(1). |
| **Space** | `O(n)` — The space complexity is linear with respect to the number of elements added to the stream. The vector 'nums' stores one cumulative product value for each integer added, resulting in a total space requirement of O(n). |

---

## Code (C++)

```cpp
class ProductOfNumbers {
public:
    vector<int> nums; //cumulative prod store karenge
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        if(num == 0) {
            nums = {};
            n = 0;
        } else {
            if(nums.empty()) {
                nums.push_back(num);
            } else {
                nums.push_back(nums[n-1] * num);
            }
            n++; //increasing size by 1
        }
    }
    
    int getProduct(int k) {
        if(k > n) {
            return 0;
        } else if(k == n) {
            return nums[n-1];
        }

        return nums[n-1] / nums[n-k-1];
    }
};
```

---

## Key Takeaways

- Cumulative products are a powerful technique for efficiently computing products of subsequences in a stream.
- Division can be used to 'undo' a multiplication in the cumulative sum, allowing for the extraction of specific segments.
- The solution handles the edge case of zero effectively by resetting the state, preventing incorrect results from accumulating.
