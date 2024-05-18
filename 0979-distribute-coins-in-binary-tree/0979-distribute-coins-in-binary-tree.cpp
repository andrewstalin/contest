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

        
        int val = 0;
        
        if (node->left != nullptr){
            val += func( node->left, res);
        }
        
        if (node->right != nullptr) {
            val += func(node->right, res);
        }
        
        val += node->val - 1;
        res += std::abs(val);
        return val;
    }
    
    int distributeCoins(TreeNode* root) {
        int res= 0;
        
        if (root->left != nullptr) {
            func(root->left, res);
        }
        
        if (root->right != nullptr) {
            func(root->right, res);
        }
        
        return res;
    }
};