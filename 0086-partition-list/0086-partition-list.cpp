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
    ListNode* partition(ListNode* head, int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>smaller,greater;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val<x) smaller.push_back(curr->val);
            else greater.push_back(curr->val);
            curr=curr->next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* prev=dummy;
        for(int i=0;i<smaller.size();i++){ 
            prev->next=new ListNode(smaller[i]);;
            prev=prev->next;
        }
        for(int i=0;i<greater.size();i++){
            prev->next=new ListNode(greater[i]);
            prev=prev->next;
        }
        return dummy->next;
    }
};