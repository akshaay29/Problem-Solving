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
    /**ListNode* solve(ListNode* head){
        if(head==NULL) return head;
        ListNode* forw=head->next;
        head->next=solve()
        
        return forw;
    }**/
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* forw=head->next;
        head->next=swapPairs(forw->next);
        forw->next=head;
        return forw;
    }
};