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
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int preStart,int preEnd,int inStart,int inEnd,unordered_map<int,int>&mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int idx=mp[root->val];
        int leftsize=idx-inStart;
        TreeNode* leftSub=build(preorder,inorder,preStart+1,preStart+leftsize,inStart,idx-1,mp);
        TreeNode* rightSub=build(preorder,inorder,preStart+leftsize+1,preEnd,idx+1,inEnd,mp);
        root->left=leftSub;
        root->right=rightSub;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++) {
            if(mp.find(inorder[i])==mp.end()) mp[inorder[i]]=i;
        }
        int preStart=0 , preEnd=preorder.size()-1  , inStart=0, inEnd=inorder.size()-1;
        return build(preorder,inorder,preStart,preEnd,inStart,inEnd,mp);
    }
};