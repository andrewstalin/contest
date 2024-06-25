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
    
    TreeNode* bstToGst(TreeNode* root) {
        int a = 0;
        
        std::stack<std::pair<TreeNode*, bool>> stack;
        stack.emplace(root, false);
        
        while(!stack.empty()) {
            auto& item = stack.top();
            
            if (item.second == 0 && item.first->right != nullptr) {
                item.second = true;
                stack.emplace(item.first->right, false);
            } else {
                a += item.first->val;
                item.first->val = a;
                auto left = item.first->left;
                stack.pop();
                
                if (left != nullptr) {
                    stack.emplace(left, false);
                }
            }
        }
        
        return root;
    }
};