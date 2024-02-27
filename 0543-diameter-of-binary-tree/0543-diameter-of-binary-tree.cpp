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
    int func(TreeNode* node, int& res) {
        int left = 0;
        int right = 0;
        
        if (node->left != nullptr) {
            left += 1 + func(node->left, res);
        }
        
        if (node->right != nullptr) {
            right += 1 + func(node->right, res);
        }
        
        res = std::max(res, left + right);
        return std::max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        func(root, res);
        return res;
    }
};