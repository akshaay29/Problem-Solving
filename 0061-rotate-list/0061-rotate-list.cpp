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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* dummy=new ListNode(0,head);
        ListNode* tr=dummy->next;
        int n=0;
        while(tr!=NULL){
            n+=1;
            tr=tr->next;
        }
        if(k==0 || n==0 || k%n==0) return dummy->next;
        k=k%n;
        tr=head;
        for(int i=0;i<n-k-1;i++){
            tr=tr->next;
        }
        ListNode* forw=tr->next;
        dummy->next=forw;
        tr->next=NULL;
        while(forw->next!=NULL) forw=forw->next;
        forw->next=head;
        return dummy->next;
    }
};