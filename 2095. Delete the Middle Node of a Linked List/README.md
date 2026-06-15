# 2095. Delete the Middle Node of a Linked List

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

[LeetCode — 2095. Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

---

## Problem Summary

You are given the head of a singly linked list.

Delete the **middle node** of the linked list and return the head of the modified list.

The middle node is defined as the `⌊n / 2⌋`-th node using **0-based indexing**, where `n` is the number of nodes in the list.

For example:

- `n = 1` → middle index = `0`
- `n = 2` → middle index = `1`
- `n = 3` → middle index = `1`
- `n = 4` → middle index = `2`

---

## Examples

### Example 1
**Input:** `head = [1,3,4,7,1,2,6]`  
**Output:** `[1,3,4,1,2,6]`

**Explanation:**
- Length = 7
- Middle index = 3
- Node with value `7` is removed.

### Example 2
**Input:** `head = [1,2,3,4]`  
**Output:** `[1,2,4]`

**Explanation:**
- Length = 4
- Middle index = 2
- Node with value `3` is removed.

### Example 3
**Input:** `head = [2,1]`  
**Output:** `[2]`

**Explanation:**
- Length = 2
- Middle index = 1
- Node with value `1` is removed.

---

## Intuition

A common way to find the middle node of a linked list is using the **slow and fast pointer technique**.

- `slow` moves one step at a time.
- `fast` moves two steps at a time.

When `fast` reaches the end of the list, `slow` will be positioned at the middle node.

Since we need to delete the middle node, we also keep track of the node just before it (`prev`) so that we can reconnect the list after removing the middle node.

---

## Approach

1. Handle the special case where the list contains only one node.
   - Deleting the middle node leaves an empty list.
2. Initialize:
   - `slow = head`
   - `fast = head`
   - `prev = nullptr`
3. Move:
   - `slow` by one step.
   - `fast` by two steps.
   - Update `prev` to follow `slow`.
4. When traversal ends:
   - `slow` points to the middle node.
   - `prev` points to the node before the middle.
5. Remove the middle node:
   - `prev->next = slow->next`
6. Delete the middle node and return the head.

This finds and removes the middle node in a single traversal.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n)` — single traversal of the linked list |
| **Space** | `O(1)` — only a few pointers are used |

---

## Code (C++)

```cpp
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
    }
};
```

---

## Key Takeaways

- Slow and fast pointers efficiently find the middle node in one pass.
- Keeping track of the previous node allows easy deletion in a singly linked list.
- Edge case: a single-node list becomes empty after deletion.
- The solution achieves `O(n)` time and `O(1)` extra space.