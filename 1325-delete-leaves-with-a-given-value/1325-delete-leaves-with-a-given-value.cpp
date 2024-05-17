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
    inline void try_delete_node(TreeNode* node, TreeNode* prev, int targert) {
         if (node->left == nullptr && node->right == nullptr 
                && node->val == targert && prev != nullptr) {
             
            if (prev->left == node) {
                prev->left = nullptr;
            } else {
                prev->right = nullptr;
            }
        }       
    }
    
    void walk(TreeNode* node, TreeNode* prev, int targert) {
        if (node->left == nullptr && node->right == nullptr) {
            try_delete_node(node, prev, targert);            
            return;
        }
        
        if (node->left != nullptr) {
            walk(node->left, node, targert);
        }
        
        if (node->right != nullptr) {
            walk(node->right, node, targert);
        }
        
        try_delete_node(node, prev, targert);
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int targert) {
        walk(root, nullptr, targert);
        
        return root->left == nullptr && root->right == nullptr && root->val == targert
                ? nullptr : root;
    }
};