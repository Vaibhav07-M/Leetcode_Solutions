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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        // Edge cases
        if(!head || !head->next || k == 0) return head;
        
        // Step 1: find length and tail
        int n = 1;
        ListNode* tail = head;
        
        while(tail->next) {
            tail = tail->next;
            n++;
        }
        
        // Step 2: optimize k
        k = k % n;
        if(k == 0) return head;
        
        // Step 3: make circular
        tail->next = head;
        
        // Step 4: find new tail
        int steps = n - k - 1;
        ListNode* newTail = head;
        
        for(int i = 0; i < steps; i++) {
            newTail = newTail->next;
        }
        
        // Step 5: break and return new head
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        
        return newHead;
    }
};