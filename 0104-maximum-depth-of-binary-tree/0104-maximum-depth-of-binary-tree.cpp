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
    int maxDepth(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!root) return 0;
        int lsub=1+maxDepth(root->left);
        int rsub=1+maxDepth(root->right);
        return max(lsub,rsub);
    }
};