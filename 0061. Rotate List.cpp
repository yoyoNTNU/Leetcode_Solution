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
        if(!head) return head;
        ListNode* cur=head;
        int nodeCount=0;
        while(cur){
            nodeCount++;
            if(!cur->next){
                cur->next=head;
                break;
            }
            cur=cur->next;
        }
        k%=nodeCount;
        k=nodeCount-k;
        cur=head;

        for(int i=0;i<k-1;++i){
            cur=cur->next;
        }
        head=cur->next;
        cur->next=nullptr;

        return head;
    }
};
