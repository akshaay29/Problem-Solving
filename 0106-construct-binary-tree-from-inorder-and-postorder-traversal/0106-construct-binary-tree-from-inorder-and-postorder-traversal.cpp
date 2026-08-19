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
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int inStart,int inEnd,int poStart,int poEnd,unordered_map<int,int>&mp){
        if(poStart > poEnd || inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(postorder[poEnd]);
        int idx=mp[root->val];
        int leftSize=idx-inStart;
        TreeNode* leftSub=build(inorder,postorder,inStart,idx-1,poStart,poStart+leftSize-1,mp);
        TreeNode* rightSub=build(inorder,postorder,idx+1,inEnd,poStart+leftSize,poEnd-1,mp);
        root->left=leftSub;
        root->right=rightSub;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            if(mp.find(inorder[i])==mp.end()) mp[inorder[i]]=i;
        }
        int inStart=0 , inEnd=inorder.size()-1 , poStart=0, poEnd=postorder.size()-1;
        return build(inorder,postorder,inStart,inEnd,poStart,poEnd,mp);
    }
};