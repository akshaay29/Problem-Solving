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
        ios_base::sync_with_stdio(false);
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        for(int i=0;i<left-1;i++) prev=prev->next;
        ListNode* tr=prev->next;
        ListNode* l=prev;
        ListNode* forw=NULL;
        prev=NULL;
        for(int i=0;i<right-left+1;i++){
            forw=tr->next;
            tr->next=prev;
            prev=tr;
            tr=forw;
        }
        ListNode* end=l->next;
        end->next=tr;
        l->next=prev;
        return dummy->next;
    }
};