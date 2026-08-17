/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool  isMirror(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if((p && !q) || (!p && q)) return false;
        bool inner=isMirror(p->right,q->left);
        bool outer=isMirror(p->left,q->right);
        return (inner &&  outer  && p->val==q->val);
    }
    bool isSymmetric(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!root) return true;
        if((root->left && !root->right ) || (root->right && !root->left)) return false;
        return isMirror(root->left,root->right);
    }
};