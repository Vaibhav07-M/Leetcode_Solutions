# 61. Rotate List

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

[LeetCode — 61. Rotate List](https://leetcode.com/problems/rotate-list/)

---

## Problem Summary

Given the head of a singly linked list, rotate the list to the right by `k` places.

For example, given `1->2->3->4->5` and `k = 2`, the result is `4->5->1->2->3`.

---

## Examples

### Example 1
**Input:** `head = [1,2,3,4,5], k = 2`  
**Output:** `[4,5,1,2,3]`

### Example 2
**Input:** `head = [0,1,2], k = 4`  
**Output:** `[2,0,1]`

---

## Intuition

Rotating the list by `k` positions to the right is equivalent to:
1. Linking the list into a cycle
2. Breaking the cycle at the new tail position which is `n - (k % n)` steps from the head

This allows O(n) time and O(1) extra space.

---

## Approach

1. If the list is empty or has one node, return head.
2. Compute the length `n` and find the tail node.
3. Connect tail->next = head to make it circular.
4. Compute `k = k % n` and find the new tail at position `n - k - 1` from head (0-indexed).
5. Set `newHead = newTail->next`, break the cycle `newTail->next = NULL`, and return `newHead`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass to get length + constant extra work |
| **Space** | `O(1)` — operate in place |

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        
        // compute length and tail
        ListNode* tail = head;
        int n = 1;
        while(tail->next) {
            tail = tail->next;
            n++;
        }
        
        k %= n;
        if(k == 0) return head;
        
        // make it circular
        tail->next = head;
        
        // find new tail: move n - k - 1 steps from head
        int stepsToNewTail = n - k - 1;
        ListNode* newTail = head;
        for(int i = 0; i < stepsToNewTail; ++i) newTail = newTail->next;
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
```

---

## Key Takeaways

- Transforming the list into a cycle simplifies rotation logic.
- Always reduce `k` modulo `n` to avoid unnecessary rotations.
- Handle edge cases: empty list, single node, or `k % n == 0`.
