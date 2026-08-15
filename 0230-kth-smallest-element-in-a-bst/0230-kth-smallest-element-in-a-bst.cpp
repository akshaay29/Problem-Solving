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
    void solve(TreeNode* root,int &cnt,int k,int &ans){
        if(!root) return;
        solve(root->left,cnt,k,ans);
        cnt+=1;
        if(cnt==k) ans=root->val;
        solve(root->right,cnt,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0,cnt=0;
        solve(root,cnt,k,ans);
        return ans;
    }
};