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
    bool walk(TreeNode* node) {
        if (node->val < 2) {
            return node->val == 1;
        }
        
        return node->val == 2 ? (walk(node->left) || walk(node->right)) : (walk(node->left) && walk(node->right));
    }
    
    bool evaluateTree(TreeNode* root) {
        return walk(root);
    }
};