# 3731. Find Missing Elements

**Difficulty:** `Easy`  
**Tags:** `Array`, `Hash Set`

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

https://leetcode.com/problems/find-missing-elements/

---

## Problem Summary

You are given an array of **unique integers**.

Originally, the array contained every integer in a continuous range from its smallest value to its largest value, but some integers are missing.

Return all the missing integers in **sorted order**. If none are missing, return an empty array. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
nums = [1,4,2,5]
```

**Output**

```text
[3]
```

---

### Example 2

**Input**

```text
nums = [7,8,6,9]
```

**Output**

```text
[]
```

---

### Example 3

**Input**

```text
nums = [5,1]
```

**Output**

```text
[2,3,4]
```

---

## Intuition

The missing numbers must lie between:

- the smallest element
- the largest element

So:

1. Find the minimum and maximum values.
2. Store every number in a hash set.
3. Traverse the complete range from `min` to `max`.
4. Any number not present in the set is missing.

---

## Approach

Find:

```cpp
mn = minimum element
mx = maximum element
```

Insert all elements into an `unordered_set`.

Now iterate:

```cpp
for(i = mn; i <= mx; i++)
```

If:

```cpp
i not present in set
```

add it to the answer.

Since we iterate in increasing order, the output is already sorted.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n + (max - min))` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = mn; i <= mx; i++) {
            if (!st.count(i))
                ans.push_back(i);
        }

        return ans;
    }
};
```

---

## Why This Works

Consider:

```text
nums = [1,4,2,5]
```

Minimum:

```text
1
```

Maximum:

```text
5
```

The complete range is:

```text
1 2 3 4 5
```

The hash set contains:

```text
{1,2,4,5}
```

Checking each value:

| Number | Present? |
|--------:|:--------:|
| 1 | ✔ |
| 2 | ✔ |
| 3 | ✘ |
| 4 | ✔ |
| 5 | ✔ |

So the answer becomes:

```text
[3]
```

---

## Key Takeaways

- The smallest and largest values define the original range.
- A hash set provides **O(1)** average lookup.
- Traverse every value between `min` and `max`.
- Any value missing from the set is added to the answer.
- Time Complexity is **O(n + (max − min))**.
- Space Complexity is **O(n)**.