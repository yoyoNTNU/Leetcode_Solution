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
        if(!head)return head;
        ListNode* cur=head->next;
        ListNode* pre=head;
        while(cur){
            if(cur->val==pre->val){
                pre->next=cur->next;
            }
            else{
                pre=cur;
            }
            cur=cur->next;
        }
        return head;
    }
};
