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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            auto node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
        std::vector<TreeNode*> nodes;
        std::queue<TreeNode*> queue;
        queue.emplace(root);
        queue.emplace(nullptr);
        
        int level = 2;
        
        while(!queue.empty()) {
            auto item = queue.front();
            queue.pop();
            
            if (item == nullptr) {                
                if (level == depth) {
                    for (int i = 0; i < nodes.size(); ++i) {
                        auto node = nodes[i];
                        
                        auto right = new TreeNode(val);
                        right->right = node->right;
                        node->right = right;
                        
                        auto left = new TreeNode(val);
                        left->left = node->left;
                        node->left = left;
                    }
                    
                    break;
                }
                
                ++level;
                queue.emplace(nullptr);
            } else {
                if (level == depth) {
                    nodes.emplace_back(item);
                } else {
                    if (item->left != nullptr) {
                        queue.emplace(item->left);
                    }

                    if (item->right != nullptr) {
                        queue.emplace(item->right);
                    }   
                }
            }
        }
        
        return root;
    }
};