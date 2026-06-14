# 2130. Maximum Twin Sum of a Linked List

**Difficulty:** `Medium`  
**Tags:** `Linked List`, `Two Pointers`

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

[LeetCode — 2130. Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)

---

## Problem Summary

You are given the head of a singly linked list with an even number of nodes.

For a linked list of size `n`, the twin of the `i-th` node is the `(n - 1 - i)-th` node.

The **twin sum** of a node is defined as the sum of the node's value and its twin's value.

Return the **maximum twin sum** among all twin pairs in the linked list.

---

## Examples

### Example 1
**Input:** `head = [5,4,2,1]`  
**Output:** `6`

**Explanation:**
- Twin pairs:
  - (5, 1) → 6
  - (4, 2) → 6
- Maximum twin sum = 6

### Example 2
**Input:** `head = [4,2,2,3]`  
**Output:** `7`

**Explanation:**
- Twin pairs:
  - (4, 3) → 7
  - (2, 2) → 4
- Maximum twin sum = 7

### Example 3
**Input:** `head = [1,100000]`  
**Output:** `100001`

**Explanation:**
- Only one twin pair exists:
  - (1, 100000) → 100001

---

## Intuition

Since twins are located symmetrically from the beginning and end of the linked list, we need a way to access nodes from both directions.

A singly linked list does not allow backward traversal, so we:

1. Find the middle of the list using the slow and fast pointer technique.
2. Reverse the second half of the list.
3. Traverse both halves simultaneously and compute twin sums.
4. Keep track of the maximum twin sum encountered.

This avoids using extra space while efficiently pairing corresponding twin nodes.

---

## Approach

1. Use **slow** and **fast** pointers to locate the middle of the linked list.
2. Reverse the second half of the list starting from the middle.
3. Initialize:
   - `first` at the beginning of the list.
   - `second` at the head of the reversed second half.
4. Traverse both pointers together:
   - Compute `first->val + second->val`.
   - Update the maximum answer.
5. Return the maximum twin sum found.

This works because reversing the second half aligns every node directly with its twin.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n)` — one pass to find middle, one to reverse, one to compute sums |
| **Space** | `O(1)` — no extra data structures used |

---

## Code (C++)

```cpp
class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode *slow = head;
        ListNode *fast = head;

        // Find middle
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *prev = nullptr;
        while(slow) {
            ListNode *nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Compute twin sums
        int ans = 0;
        ListNode *first = head;
        ListNode *second = prev;

        while(second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Slow and fast pointers are useful for finding the middle of a linked list in `O(n)` time.
- Reversing the second half allows twin nodes to be accessed simultaneously.
- The solution achieves `O(n)` time and `O(1)` extra space.
- Combining linked list reversal with two-pointer traversal is a common interview pattern.