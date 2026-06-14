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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow;
        ListNode* prev=NULL;
        ListNode* nextptr=NULL;
        while(curr!=NULL){
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
        int sum=0,maxSum=INT_MIN;
        while(head!=NULL && prev!=NULL){
            sum=head->val+prev->val;
            maxSum=max(maxSum,sum);
            head=head->next;
            prev=prev->next;
        }
        return maxSum;
    }
};