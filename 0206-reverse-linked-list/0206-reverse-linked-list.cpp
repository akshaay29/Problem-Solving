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
 /* struct Listnode{
        int val;
        ListNode* next;
        ListNode() :  val(0),next(nullptr)  {}
        ListNode(int x) :  val(x),next(nullptr) {}
        ListNode(int x,ListNode* next) :val(x),next(next){}
    }
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(head==NULL) return head;
        ListNode* curr=head;
        ListNode* forw=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
};