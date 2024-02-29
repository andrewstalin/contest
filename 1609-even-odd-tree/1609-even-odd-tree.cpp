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
    bool isEvenOddTree(TreeNode* root) {
        bool even = true;
        int prev = -1;
        
        std::queue<TreeNode*> queue;
        queue.emplace(root);
        queue.emplace(nullptr);
        
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            
            if (node == nullptr) {
                if (queue.empty()) {
                    break;
                }
                
                queue.emplace(nullptr);
                even = !even;
                prev = even ? -1 : 10000000;
                continue;   
            }
            
            if ((even && (node->val % 2 == 0 || prev >= node->val))
               || (!even && (node->val % 2 != 0 || prev <= node->val))) {
                return false;
            }
            
            prev = node->val;
            
            if (node->left != nullptr) {
                queue.emplace(node->left);
            }
            
            if (node->right != nullptr) {
                queue.emplace(node->right);
            }
        }
        
        return true;
    }
};