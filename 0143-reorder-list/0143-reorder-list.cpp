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
    ListNode*  getmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* tr=head;
        ListNode* prev=NULL;
        ListNode* forw=NULL;
        while(tr!=NULL){
            forw=tr->next;
            tr->next=prev;
            prev=tr;
            tr=forw;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* middle=getmid(head);
        ListNode* head2=reverse(middle);
        ListNode* tr=head;
        ListNode* forw1=NULL;
        ListNode* forw2=NULL;
        ListNode* prev=NULL;
        while(tr!=NULL && head2!=NULL){
            forw1=tr->next;
            forw2=head2->next;
            if (tr!=head) prev->next=tr;
            tr->next=head2;
            prev=head2;
            tr=forw1;
            head2=forw2;
        }
        prev->next=NULL;
        /**deque<ListNode*>q;
        ListNode* tr=head->next;
        while(tr!=NULL){
            q.push_back(tr);
            tr=tr->next;
        }
        tr=head;
        while(!q.empty()){
            ListNode* l=q.front();
            ListNode* r=q.back();
            tr->next=r;
            tr=tr->next;
            q.pop_back();
            if(!q.empty()){
                r->next=q.front();
                tr=l;
                q.pop_front();
            }
        }
        tr->next=NULL;**/
    }
};