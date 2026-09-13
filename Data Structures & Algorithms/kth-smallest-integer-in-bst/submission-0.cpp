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
 void dfs(TreeNode* root, int k, priority_queue<int>& q){
        if(!root) return;

        q.push(root->val);

        while(q.size() > k) q.pop();

        dfs(root->left, k, q);
        dfs(root->right, k, q);

    }
    
    int kthSmallest(TreeNode* root, int k) {
         if(!root) return 0;

        priority_queue<int> q;        

        dfs(root, k, q);        

        return q.top();
    }
};
