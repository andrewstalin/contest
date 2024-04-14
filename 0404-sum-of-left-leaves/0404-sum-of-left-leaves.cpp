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
    int func(TreeNode* node) {
        int res = 0;
        
        if (node->left != nullptr) {
            if (node->left->left == nullptr && node->left->right == nullptr) {
                res = node->left->val;
            } else {
                res += func(node->left);
            }
        }
        
        if (node->right != nullptr) {
            res += func(node->right);
        }
        
        return res;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return func(root);
    }
};