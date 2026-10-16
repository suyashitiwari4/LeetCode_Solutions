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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        // 1. Move prev to the node right before the `left` position
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        // 2. Reverse the sublist from left to right
        ListNode* curr = prev->next;
        ListNode* forward = nullptr;
        ListNode* tail = curr; // This will become the tail of the reversed sublist

        for (int i = 0; i < right - left; i++) {
            forward = curr->next;
            curr->next = forward->next;
            forward->next = prev->next;
            prev->next = forward;
        }

        return dummy->next;
    }
};