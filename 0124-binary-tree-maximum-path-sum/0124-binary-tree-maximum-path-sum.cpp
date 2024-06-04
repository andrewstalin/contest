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
        res = std::max(res, node->val);
        int val = node->val;
        int left = INT32_MIN;
        
        if (node->left != nullptr) {
            left = func(node->left, res);    
        }
        
        int right = INT32_MIN;
        
        if (node->right != nullptr) {
            right = func(node->right, res);
        }
        
        if (left > 0) {
            val += left;
        }
        
        if (right > 0) {
            val += right;
        }
        
        res = std::max(res, val);
        return node->val + (left < 0 && right < 0 ? 0 : (left > right ? left : right));
    }
        
    int maxPathSum(TreeNode* root) {
        int res = INT32_MIN;
        func(root, res);
        return res;
    }
};