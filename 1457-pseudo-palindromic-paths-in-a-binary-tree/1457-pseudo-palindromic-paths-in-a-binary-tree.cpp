struct Item {
    TreeNode* node;
    bool visited{ false };
    
    Item(TreeNode* node): node(node) {}
};

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

    int func(int odd, int total, std::vector<int>& digits, TreeNode* node) {
        ++total;
        
        if ((++digits[node->val]) % 2 == 0){
            --odd;
        } else {
            ++odd;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            --digits[node->val];
            
            if (total % 2 == 0) {
                return odd == 0 ? 1 : 0;
            } else {
                return odd == 1 ? 1 : 0;  
            }
        }
        
        int res = 0;
        
        if (node->left != nullptr) {
            res += func(odd, total, digits, node->left);
        }
        
        if (node->right != nullptr) {
            res += func(odd, total, digits, node->right);
        }
        
        --digits[node->val];
        return res;
    }
    
    // use recursion
    int pseudoPalindromicPaths_(TreeNode* root) {
        std::vector<int> digits(10, 0);
        int odd = 0;
        int total = 0;
        
        return func(odd, total, digits, root);
    }
    
    // use iterator
    int pseudoPalindromicPaths(TreeNode* root) {
        std::stack<Item> stack;
        stack.emplace(root);
        
        std::vector<int> digits(10, 0);
        ++digits[root->val];
        int odd = 1;
        int total = 1;
        
        auto node = root->left;
        while(node != nullptr) {
            stack.emplace(node);
            
            if ((++digits[node->val]) % 2 == 0) {
                --odd;
            } else {
                ++odd;
            }
            
            ++total;
            node = node->left;
        }
        
        int res = 0;
        
        while (!stack.empty()) {
            auto& item = stack.top();
            
            if (item.node->left == nullptr && item.node->right == nullptr) {
                if (total % 2 == 0) {
                    res += odd == 0 ? 1 : 0;
                } else {
                    res += odd == 1 ? 1 : 0;  
                }
                
                if ((--digits[item.node->val]) % 2 == 0) {
                    --odd;
                } else {
                    ++odd;
                }
                
                stack.pop();
                --total;
            } else {
                if (item.visited) {
                    if ((--digits[item.node->val]) % 2 == 0) {
                        --odd;
                    } else {
                        ++odd;
                    }
                    
                    stack.pop();
                    --total;
                    continue;
                }
                
                item.visited = true;
                
                if (item.node->right != nullptr) {
                    node = item.node->right;
     
                    while(node != nullptr) {
                        stack.emplace(node);

                        if ((++digits[node->val]) % 2 == 0) {
                            --odd;
                        } else {
                            ++odd;
                        }

                        ++total;
                        node = node->left;
                    }
                }
            }
        }
        
        return res;
    }
};