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
    int walk(int val, TreeNode* node) {
        int res = 0;
        
        if (node->right != nullptr) {
            res += walk(val, node->right);    
        }
        
        res += node->val;
        node->val = res + val;
        
        if (node->left != nullptr) {
            res += walk(node->val, node->left);
        }
        
        return res;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        walk(0, root);
        return root;
    }
    
    TreeNode* bstToGst0(TreeNode* root) {
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