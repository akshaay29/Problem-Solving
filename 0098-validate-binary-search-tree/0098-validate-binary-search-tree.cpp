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
using ll=long long;
class Solution {
public:
    bool solve(TreeNode* root,ll high,ll low){
        if(!root) return true;
        if(root->val<=low || root->val>=high) return false;
        bool lsub=solve(root->left,root->val,low);
        bool rsub=solve(root->right,high,root->val);
        return (lsub && rsub) ? true:false;
    }
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll high=LLONG_MAX , low=LLONG_MIN;
        return solve(root,high,low); 
    }
};