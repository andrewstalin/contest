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
    inline bool compare(const std::string& str, const std::string& res) {
        int i1 = str.size() - 1;
        int i2 = res.size() - 1;
        
        while (i1 >= 0 && i2 >= 0) {
            if (str[i1] == res[i2]) {
                --i1;
                --i2;
                continue;
            }
            
            return str[i1] < res[i2];
        }
        
        return i2 >= 0;
    }
    
    void func(TreeNode* node, std::string& str, std::string& res) {
        str.push_back(node->val + 'a');
        
        if (node->left == nullptr && node->right == nullptr) {
            if (res.empty() || compare(str, res)) {
                res = str;
            }
            
            str.resize(str.size() - 1);
            return;
        }
        
        if (node->left != nullptr) {
            func(node->left, str, res);
        }
        
        if (node->right != nullptr) {
            func(node->right, str, res);
        }
        
        str.resize(str.size() - 1);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            std::string res;
            res.push_back(root->val + 'a');
            return res;
        }
        
        std::string res;
        std::string str;
        str.reserve(8000);
        
        func(root, str, res);
        std::reverse(res.begin(), res.end());
        return res;
    }
};


/*


[20,7,9,16,4,18,9,15,3,17,9,12,10,12,18,8,16,1,7,19,1,16,0,12,23,0,13,1,22,17,19,17,0,1,16,25,22,18,18,5,19,7,2,11,8,4,10,23,11,11,18,13,3,23,11,20,10,20,10,5,5,24,15,1,10,6,2,4,1,16,4,15,15,18,13,7,22,9,11,16,13,24,24,24,24,15,12,18,5,6,1,4,0,17,3,20,17,25,10,23]

*/


