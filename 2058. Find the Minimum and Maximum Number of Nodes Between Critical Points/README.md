# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

**Difficulty:** `Medium`  
**Tags:** `Linked List`

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

[LeetCode — 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/)

---

## Problem Summary

Given a singly linked list, a node is a critical point if it is a strict local maximum (greater than both neighbors) or a strict local minimum (smaller than both neighbors). Only nodes with both a previous and next node qualify, so the head and tail can never be critical points.  
The task is to return [minDistance, maxDistance], where minDistance is the smallest index gap between any two critical points and maxDistance is the largest such gap. If fewer than two critical points exist, return [-1, -1].

---

## Examples

### Example 1
**Input:** `head = [3,1]`  
**Output:** `[-1,-1]`  
**Explanation:**
- There are no critical points in [3,1].

### Example 2
**Input:** `head = [5,3,1,2,5,1,2]`  
**Output:** `[1,3]`  
**Explanation:**
- There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
- The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
- The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

### Example 3
**Input:** `head = [1,3,2,2,3,2,2,2,7]`  
**Output:** `[3,3]`  
**Explanation:**
- There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
- Both the minimum and maximum distances are between the second and the fifth node.
- Thus, minDistance and maxDistance is 5 - 2 = 3.
- Note that the last node is not considered a local maxima because it does not have a next node.

---

## Intuition

The maximum distance between any two critical points is always the gap between the first and last critical point, since indices are increasing along the list. So we only need to record the position of the first and last critical points encountered.  
For the minimum distance, a key observation is that the closest pair of critical points must be consecutive in the sequence of critical points: if critical points at positions a < b < c existed, then b - a and c - b are both smaller than c - a. Therefore, tracking only the gap between each newly found critical point and the immediately previous one suffices to find the global minimum.

---

## Approach

1. Initialize a position counter starting at 1, pointers prev = head and curr = head->next, and trackers for the first, previous, and last critical point positions, plus minDist set to INT_MAX.
2. Iterate while curr has a next node, so every examined node has both neighbors; at each step compare curr->val against prev->val and next->val to detect a strict local maximum or minimum.
3. When a critical point is found, record its position as first if none was seen before; otherwise update minDist with the gap pos - prevCritical, since consecutive critical points give the tightest candidate distances.
4. Update prevCritical and last to the current position after each critical point, then advance prev and curr and increment the position counter.
5. After traversal, if no critical point was found (first == -1) or only one exists (first == last), return {-1, -1}.
6. Otherwise compute maxDist = last - first and return {minDist, maxDist}.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — Single pass through the n-node list with constant-time comparisons and updates per node. |
| **Space** | `O(1)` — Only a fixed set of integer variables and two node pointers are used regardless of list size. |

---

## Code (C++)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int pos = 1;

        int first = -1;
        int prevCritical = -1;
        int last = -1;

        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {

            ListNode* next = curr->next;

            // Check if current node is a critical point
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                // First critical point
                if (first == -1) {
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - prevCritical);
                }

                prevCritical = pos;
                last = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        // Fewer than two critical points
        if (first == -1 || first == last)
            return {-1, -1};

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};
```

---

## Key Takeaways

- The maximum gap between ordered points is always last minus first, so no pairwise comparison is needed for maxDistance.
- The minimum gap among sorted positions only needs to be checked between consecutive elements, reducing the problem to a single linear scan.
- Local extrema detection in a linked list requires a sliding window of three nodes (prev, curr, next), which naturally excludes the endpoints.
- Tracking first, previous, and last occurrence positions in one pass is a common pattern for distance-between-events problems on sequential data.
