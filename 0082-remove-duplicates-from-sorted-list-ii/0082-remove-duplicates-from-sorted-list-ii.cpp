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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int dup=0;
        ListNode* dummy=new ListNode(0,head);
        ListNode* prev=dummy;
        ListNode* l=NULL;
        ListNode* r=NULL;
        while(prev->next!=NULL && prev->next->next!=NULL){
            if(prev->next->val==prev->next->next->val){
                dup=prev->next->val;
                l=prev->next;
                r=prev->next->next;
                while(r->next!=NULL && r->next->val==dup) r=r->next;
                prev->next=r->next;
            }
            else prev=prev->next;
        }
        return dummy->next;
    }
};