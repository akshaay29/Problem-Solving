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
    bool check(TreeNode* root,long long high,long long low){
        if(root==NULL) return true;
        if(root->val<low || root->val>high) return false;
        bool leftSub=check(root->left,root->val,low);
        bool rightSub=check(root->right,high,root->val);
        if(leftSub && rightSub && (root->val<high && root->val>low)) return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long high=LLONG_MAX,low=LLONG_MIN;
        return check(root,high,low);
    }
};