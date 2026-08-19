/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(root==NULL) return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            Node* tail=NULL;
            for(int i=0;i<n;i++){
                Node* head=q.front();
                q.pop();
                if(tail!=NULL) tail->next=head;
                tail=head;
                if(head->left!=NULL) q.push(head->left);
                if(head->right!=NULL) q.push(head->right);
            }
            tail->next=NULL;
        }
        return root;
    }
};