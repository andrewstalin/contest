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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        std::queue<std::pair<TreeNode*, TreeNode*>> queue;
        queue.emplace(p, q);
        
        while(!queue.empty()) {
            auto item = queue.front();
            queue.pop();
            
            auto node1 = item.first;
            auto node2 = item.second;
            
            if (node1->left != nullptr || node2->left != nullptr) {
                if (node1->left == nullptr || node2->left == nullptr 
                    || node1->left->val != node2->left->val) {
                    return false;
                }
                
                queue.emplace(node1->left, node2->left);
            }
            
            if (node1->right != nullptr || node2->right != nullptr) {
                if (node1->right == nullptr || node2->right == nullptr 
                    || node1->right->val != node2->right->val) {
                    return false;
                }
                
                queue.emplace(node1->right, node2->right);
            }
        }
        
        return true;
    }
};