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
    int dia=INT_MIN;
    int getHeight(TreeNode* root,int &dia){
        if(root==NULL) return 0;
        int leftSub=getHeight(root->left,dia);
        int rightSub=getHeight(root->right,dia);
        dia=max(dia,leftSub+rightSub);
        return 1+max(leftSub,rightSub);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int height=getHeight(root,dia);
        return dia;
    }
};