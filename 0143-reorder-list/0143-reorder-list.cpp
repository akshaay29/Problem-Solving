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
    void reorderList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        deque<ListNode*>q;
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
        tr->next=NULL;
    }
};