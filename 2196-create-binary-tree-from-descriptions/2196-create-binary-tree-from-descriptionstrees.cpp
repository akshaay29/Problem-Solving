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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int>s;
        TreeNode* head=new TreeNode();
        for(auto it:descriptions){
            int rootVal=it[0] ,  childVal=it[1] , side=it[2];
            s.insert(childVal);
            if(mp.find(rootVal)==mp.end()){
                TreeNode* root=new TreeNode(rootVal);
                mp[rootVal]=root;
            }
            if(mp.find(childVal)==mp.end()){
                TreeNode* child=new TreeNode(childVal);
                mp[childVal]=child;
            }
            if(side==1) mp[rootVal]->left=mp[childVal];
            else mp[rootVal]->right=mp[childVal];
        }
        for(auto it:descriptions) if(s.find(it[0])==s.end()) head=mp[it[0]];
        return head;
    }
};