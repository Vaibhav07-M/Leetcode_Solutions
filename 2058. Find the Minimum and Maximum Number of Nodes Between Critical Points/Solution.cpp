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
