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

    int func(TreeNode* node, int val) {
        val *= 10;
        val += node->val;
        
        if (node->left == nullptr && node-> right == nullptr) {
            return val;
        }
        
        int res = 0;
        
        if (node->left != nullptr) {
            res += func(node->left, val);
        }
        
        if (node->right != nullptr) {
            res += func(node->right, val);
        }
        
        return res;
    }
    
    int sumNumbers(TreeNode* root) { 
        return func(root, 0);
    }
};