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
    TreeNode* buildTreeFnc(vector<int>& preorder, int preStart, int preEnd,
                          vector<int>& inorder, int inorderStart, int inorderEnd, map<int,int>& hash){
        
        // invalid range
        if(preStart > preEnd || inorderStart > inorderEnd) return nullptr;

        // Build root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find index of where root present in inorder
        int rootInInorder = hash[root->val];
        int leftNodesCnt = rootInInorder - inorderStart;

        // left Call and Link
        root->left = buildTreeFnc(preorder, preStart + 1, preStart + leftNodesCnt, inorder, inorderStart, rootInInorder - 1, hash);

        // right Call and Link
        root->right = buildTreeFnc(preorder, preStart + leftNodesCnt + 1, preEnd, inorder, rootInInorder + 1, inorderEnd, hash);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // Hash for fast look-up
        map<int,int> hash;

        for(int i=0; i < inorder.size(); i++){
            hash[inorder[i]] = i;
        }

        TreeNode* root = buildTreeFnc(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, hash);

        return root;
    }
};
