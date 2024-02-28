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
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.emplace(root);
        queue.emplace(nullptr);
        
        TreeNode* res = nullptr;
        bool level = true;
        
        while(!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            
            if (node == nullptr) {
                if (queue.empty()) {
                    break;
                }
                
                level = true;
                queue.emplace(nullptr);
                continue;   
            } else {
                if (level) {
                    level = false;
                    res = node;
                }
                
                if (node->left != nullptr) {
                    queue.emplace(node->left);
                }
                
                if (node->right != nullptr) {
                    queue.emplace(node->right);
                }
            }
        }
        
        return res->val;
    }
};