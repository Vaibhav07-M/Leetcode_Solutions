# 3420. Count Non-Decreasing Subarrays After K Operations

**Difficulty:** `Hard`  
**Tags:** `Array`, `Stack`, `Segment Tree`, `Queue`, `Sliding Window`, `Monotonic Stack`, `Monotonic Queue`

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

[LeetCode — 3420. Count Non-Decreasing Subarrays After K Operations](https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/)

---

## Problem Summary

The problem requires determining the number of subarrays in a given integer array that can be transformed into a non-decreasing sequence by performing up to 'k' increment operations. Each subarray is considered independently, and the goal is to count how many of these subarrays satisfy the non-decreasing condition after the allowed operations.

---

## Examples

_No examples provided._

---

## Intuition

The solution employs a two-pass approach. First, it uses a monotonic stack to identify the 'Next Greater Right' (NGR) elements, which helps determine the minimum number of operations needed to make the suffix of the array non-decreasing. Second, it utilizes a sliding window with a deque to efficiently calculate the total number of operations required for each subarray, allowing for a quick determination of which subarrays are valid within the 'k' constraint.

---

## Approach

1. Calculate the cumulative sum of the array to enable fast computation of subarray sums.
2. Use a monotonic stack to find the 'Next Greater Right' (NGR) index for each element, which indicates where the current element is no longer the minimum in a non-decreasing sequence.
3. Compute a 'Operations' array that stores the total number of operations required to make the suffix of the array starting from each index non-decreasing.
4. Implement a sliding window with a deque to maintain the maximum element in the current window. This allows for efficient calculation of the total operations needed for each subarray.
5. Iterate through the array, updating the window and checking if the total operations for the current subarray exceed 'k'. If they do not, the subarray is counted as valid.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The solution involves a single pass through the array to build the cumulative sum and NGR, followed by a linear sweep with a sliding window. The deque operations are amortized, resulting in an overall linear time complexity. |
| **Space** | `O(n)` — The space complexity is dominated by the storage of the cumulative sum, NGR, and Operations arrays, each requiring linear space proportional to the size of the input array. |

---

## Code (C++)

```cpp
class Solution {
public:
    typedef long long ll;

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> cumSum(n);
        cumSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            cumSum[i] = nums[i] + cumSum[i-1];
        }

        //Range Sum
        auto rangeSum = [&](int i, int j) -> long long {
            if(i > j)
                return 0;

            return cumSum[j] - ((i > 0) ? cumSum[i-1] : 0);
        };

        //NGR[i] = n
        vector<int> NGR(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                NGR[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        //Operations[i] = total operns to make [i...n-1] non-decreasing
        vector<ll> Operations(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            int m = NGR[i];

            //i to m-1 segment
            ll segmentOprns = (1LL * nums[i] * (m-i)) - rangeSum(i, m-1);
            Operations[i] = segmentOprns + Operations[m];
        }


        //Ready for Sliding Window Maximum
        deque<int> deq;
        ll result = 0;
        int i = 0;
        int j = 0;

        while(j < n) {

            while(!deq.empty() && nums[deq.back()] < nums[j]) { //decreasing order maintained - monotonic ds
                deq.pop_back();
            }

            deq.push_back(j);

            //Shrink if required
            while(i <= j) {
                int m = deq.front(); //fayda hai sliding window maximum

                //i...j
                ll oprnsCount = (Operations[i] - Operations[m]) + (1LL * nums[m] * (j-m+1)) - rangeSum(m, j);

                if(oprnsCount <= k)
                    break;
                
                i++;
                if(deq.front() < i) {
                    deq.pop_front();
                }
            }

            result += (j-i+1);
            j++;
        }

        return result;
    }
};
```

---

## Key Takeaways

- The use of a monotonic stack is effective for identifying the 'Next Greater Right' elements, which is crucial for determining the minimum operations needed for suffix segments.
- A sliding window with a deque provides an efficient way to track the maximum element in a window, allowing for constant-time access to the maximum value during the sweep.
- The problem demonstrates how to combine prefix/suffix analysis with a sliding window to solve a constraint-based subarray counting problem.
