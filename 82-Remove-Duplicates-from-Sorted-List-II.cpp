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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr=head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        while(curr!=nullptr){
            bool hasduplicate = false;
            while(curr->next!=nullptr && curr->val ==curr->next->val){
                hasduplicate = true;
                curr=curr->next;
            }
            if(hasduplicate){
                prev->next = curr->next;
            }
            else{
              prev= prev->next;
            }
            curr = curr->next;
        }
        ListNode* newHead = dummy ->next;
        delete dummy;
        return newHead;
    }
};