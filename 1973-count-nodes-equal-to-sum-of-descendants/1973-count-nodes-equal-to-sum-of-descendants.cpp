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
    uint32_t func(TreeNode* node, int& res) {
        uint32_t sum = 0;
        
        if (node->left != nullptr) {
            sum += func(node->left, res);
        }
        
        if (node->right != nullptr) {
            sum += func(node->right, res);
        }
        
        if (node->val == sum) {
            ++res;
        }
        
        return sum + node->val;
    }
    
    int equalToDescendants(TreeNode* root) {
        int res = 0;
        func(root, res);
        return res;
    }
};