/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fillparent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)
            return;
        if (root->left) {
            parent[root->left] = root;
            fillparent(root->left, parent);
        }
        if (root->right) {
            parent[root->right] = root;
            fillparent(root->right, parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        fillparent(root, parent);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        vector<int> ans;
        int cnt = 0;
        q.push(target);
        visited.insert(target);
        while (!q.empty()) {
            int n = q.size();
            if (cnt == k)
                break;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if (curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if (parent[curr] != NULL && !visited.count(parent[curr])) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            cnt+=1;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val); q.pop();
        }
        return ans;
    }
};