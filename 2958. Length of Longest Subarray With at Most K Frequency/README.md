# 2958. Length of Longest Subarray With at Most K Frequency

**Difficulty:** `Medium`  
**Tags:** `Sliding Window`, `Hash Map`

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

https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

---

## Problem Summary

Given an integer array `nums` and an integer `k`, find the length of the longest subarray in which **every distinct element appears at most `k` times**.

The subarray must be contiguous.

---

## Examples

### Example 1

**Input**

```text
nums = [1,2,3,1,2,3,1,2], k = 2
```

**Output**

```text
6
```

**Explanation**

The longest valid subarray is:

```text
[1,2,3,1,2,3]
```

Every number appears exactly `2` times.

---

### Example 2

**Input**

```text
nums = [1,2,1,2,1,2,1,2], k = 1
```

**Output**

```text
2
```

**Explanation**

With `k = 1`, no number can appear more than once.

Therefore, a valid longest subarray is:

```text
[1,2]
```

---

### Example 3

**Input**

```text
nums = [5,5,5,5], k = 2
```

**Output**

```text
2
```

**Explanation**

The number `5` can appear at most `2` times, so the longest valid subarray has length `2`.

---

## Intuition

We need to find the **longest contiguous subarray** where no element occurs more than `k` times.

This is a typical **Sliding Window** problem.

Maintain a window:

```text
[left ........ right]
```

and store the frequency of every number inside the window.

When we add `nums[right]`, its frequency increases.

If its frequency becomes greater than `k`, the current window is invalid.

So we move `left` forward and decrease the frequencies until the window becomes valid again.

At every valid window, update the maximum length.

---

## Approach

### Step 1

Create a frequency map.

```cpp
unordered_map<int, int> freq;
```

It stores how many times each number occurs in the current window.

---

### Step 2

Initialize two pointers:

```text
left = 0
right = 0
```

`right` expands the window and `left` shrinks it when necessary.

---

### Step 3

Move `right` through the array.

For every element:

```cpp
freq[nums[right]]++;
```

This adds the current element to the window.

---

### Step 4

If the frequency of the newly added element becomes greater than `k`:

```cpp
while (freq[nums[right]] > k)
```

remove elements from the left.

```cpp
freq[nums[left]]--;
left++;
```

Continue until the window becomes valid.

---

### Step 5

Once the window is valid, calculate its length:

```cpp
right - left + 1
```

and update the answer:

```cpp
ans = max(ans, right - left + 1);
```

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n)` average |
| **Space** | `O(n)` |

where `n` is the size of `nums`.

Each element is added to the window once and removed from the window at most once.

---

## Code (C++)

```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

---

## Why This Works

Consider:

```text
nums = [1,2,1,2,1]
k = 2
```

We expand the window:

```text
[1]
[1,2]
[1,2,1]
[1,2,1,2]
```

At this point:

```text
1 → 2 times
2 → 2 times
```

The window is valid.

When we add another `1`:

```text
[1,2,1,2,1]
```

the frequency becomes:

```text
1 → 3 times
```

which is greater than `k = 2`.

So we move `left` forward and remove elements until `1` occurs at most twice again.

This guarantees that the maintained window is always valid.

Since we check the maximum length after every valid window, `ans` becomes the length of the longest valid subarray.

---

## Key Takeaways

- This is a **Sliding Window** problem.
- Use a **Hash Map** to maintain element frequencies.
- `right` expands the window.
- `left` shrinks the window when a frequency exceeds `k`.
- The window is always maintained as valid.
- Each element enters and leaves the window at most once.
- Time Complexity is **O(n)** average.
- Space Complexity is **O(n)**.