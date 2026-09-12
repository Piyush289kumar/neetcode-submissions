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
 bool check(TreeNode* root, int targetSum, int pathSum){
        if(!root) return (pathSum == targetSum);

        pathSum += root->val;

        if(pathSum == targetSum && !root->left && !root->right) return true;

        if(root->left && check(root->left, targetSum, pathSum)) return true;
        if(root->right && check(root->right, targetSum, pathSum)) return true;

        pathSum -= root->val;
        
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        return check(root, targetSum, 0);
    }
};