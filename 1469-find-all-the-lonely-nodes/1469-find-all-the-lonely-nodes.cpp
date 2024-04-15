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
    void func(TreeNode* node, int count, std::vector<int>& res) {
        if (count == 1) {
            res.push_back(node->val);
        }
        
        count = (node->left != nullptr) + (node->right != nullptr);
        
        if (node->left != nullptr) {
            func(node->left, count, res);
        }
        
        if (node->right != nullptr) {
            func(node->right, count, res);
        }
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
        std::vector<int> res;
        func(root, 2, res);
        return res;
    }
};