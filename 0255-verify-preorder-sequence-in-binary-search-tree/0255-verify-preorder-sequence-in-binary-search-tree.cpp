class Solution {
public:
    int func(int min, int max, int pos, const std::vector<int>& preorder) {
        if (pos + 1 >= preorder.size()) {
            return preorder.size();
        }
        
        int left = pos + 1;
        int right;
        
        if (preorder[left] < preorder[pos] && preorder[left] > min && preorder[left] < max) {
            right = func(min, preorder[pos], left, preorder);
        } else {
            right = pos + 1;
        }
        
        if (right < preorder.size() && preorder[right] > preorder[pos] && preorder[right] > min && preorder[right] < max) {
            return func(preorder[pos], max, right, preorder);
        }
        
        return right;
    }
    
    bool verifyPreorder(vector<int>& preorder) {
        return func(INT32_MIN, INT32_MAX, 0, preorder) == preorder.size();
    }
};