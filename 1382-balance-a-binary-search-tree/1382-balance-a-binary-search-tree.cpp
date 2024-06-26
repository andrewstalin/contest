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
    TreeNode* build(int l, int r, const std::vector<int>& data) {
        if (r == l) {
            return new TreeNode(data[l]);
        }
        
        auto mid = (r + l)/2;
        auto node = new TreeNode(data[mid]);
        
        if (l < mid) {
            node->left = build(l, mid - 1, data);
        }
        
        if (r > mid) {
            node->right = build(mid + 1, r, data);
        }
        
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        
        std::vector<int> data;
        data.reserve(1000);
        
        std::stack<TreeNode*> stack;
        stack.emplace(root);
        
        while (!stack.empty()) {
            auto& node = stack.top();
            
            if (node->left != nullptr) {
                auto left = node->left;
                node->left = nullptr;
                stack.emplace(left);
                continue;
            }
            
            data.emplace_back(node->val);
            auto right = node->right;
            stack.pop();
            
            if (right != nullptr) {
                stack.emplace(right);
            }
        }
        
        return build(0, data.size() - 1, data);
    }
};