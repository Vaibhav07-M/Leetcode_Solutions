# 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

**Difficulty:** `Easy`  
**Tags:** `Array`, `Hash Table`

---

## Table of Contents

- [Problem Link](#problem-link)
- [Problem Summary](#problem-summary)
- [Examples](#examples)
- [Intuition](#intuition)
- [Approach](#approach)
- [Complexity](#complexity)
- [Code (C++)](#code-c)
- [Why This Works](#why-this-works)
- [Key Takeaways](#key-takeaways)

---

## Problem Link

https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/

---

## Problem Summary

Given an integer array `nums`, find the longest **sequential prefix** of the array.

A sequential prefix is a prefix where every element after the first is exactly one greater than the previous element.

Calculate the sum of this sequential prefix.

Then return the smallest integer greater than or equal to this sum that does not appear in `nums`.

---

## Examples

### Example 1

**Input**

```text
nums = [1,2,3,2,5]
```

**Sequential Prefix**

```text
[1,2,3]
```

**Sum**

```text
1 + 2 + 3 = 6
```

Since `6` does not exist in the array:

**Output**

```text
6
```

---

### Example 2

**Input**

```text
nums = [3,4,5,1,2]
```

**Sequential Prefix**

```text
[3,4,5]
```

**Sum**

```text
3 + 4 + 5 = 12
```

Since `12` is not present:

**Output**

```text
12
```

---

## Intuition

The first step is to find the longest prefix where the numbers are consecutive.

For example:

```text
[1,2,3,2,5]
```

The sequential prefix is:

```text
1 → 2 → 3
```

because:

```text
2 = 1 + 1
3 = 2 + 1
```

But `2` after that does not continue the sequence.

Therefore, the prefix sum is:

```text
1 + 2 + 3 = 6
```

Now we need the smallest missing integer that is at least `6`.

A hash set allows us to quickly check whether each candidate exists in the array.

---

## Approach

### Step 1

Initialize the sum with the first element.

```cpp
int sum = nums[0];
```

---

### Step 2

Traverse the array from the second element.

If the current element is exactly one greater than the previous element, add it to the sum.

```text
nums[i] == nums[i - 1] + 1
```

If this condition fails, stop because the sequential prefix has ended.

---

### Step 3

Store all elements of `nums` in an `unordered_set`.

This allows efficient existence checking.

---

### Step 4

Starting from the sequential prefix sum, check whether the value exists in the set.

If it exists, increment it.

Continue until a value that does not exist is found.

---

### Step 5

Return that value.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n)` average |
| **Space** | `O(n)` |

The `unordered_set` provides **O(1) average** lookup time.

---

## Code (C++)

```cpp
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find sum of longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        // Find smallest missing integer >= sum
        unordered_set<int> s(nums.begin(), nums.end());

        while (s.count(sum))
            sum++;

        return sum;
    }
};
```

---

## Why This Works

Consider:

```text
nums = [1,2,3,2,5]
```

The longest sequential prefix is:

```text
[1,2,3]
```

So:

```text
sum = 1 + 2 + 3 = 6
```

Now store the elements:

```text
{1,2,3,5}
```

Check `6`.

```text
6 ∉ {1,2,3,5}
```

Therefore, `6` is the smallest missing integer greater than or equal to the sequential prefix sum.

The algorithm correctly returns:

```text
6
```

---

## Key Takeaways

- Find the **longest sequential prefix** first.
- Calculate the sum of that prefix.
- Use an `unordered_set` for fast existence checks.
- Start checking from the prefix sum.
- Keep incrementing until a missing integer is found.
- Time Complexity is **O(n) average**.
- Space Complexity is **O(n)**.