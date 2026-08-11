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
    void solve(TreeNode* root,int &prev,int &minD){
        if(!root) return;
        solve(root->left,prev,minD);
        if(prev!=-1) minD=min(minD, root->val-prev);
        prev=root->val;
        solve(root->right,prev,minD);
    }
    int getMinimumDifference(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int minD=INT_MAX  , prev=-1;
        solve(root,prev,minD);
        return minD;
    }
};