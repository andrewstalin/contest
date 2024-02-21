class Solution {
public:
    inline std::vector<bool> to_binary(int val) {
        std::vector<bool> res;
        
        while (val > 0) {
            res.emplace_back((val & 1) != 0 ? 1 : 0);
            val >>= 1;
        }
        
        return res;
    }
    
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0) {
            return 0;
        }
        
        if (left == right) {
            return left;
        }
        
        auto d1 = to_binary(left);
        auto d2 = to_binary(right);
        
        if (d1.size() != d2.size()) {
            return 0;
        }
        
        int index = d1.size() - 1;
        int res = 0;
        
        while (index >= 0) {
            if (d1[index] != d2[index]) {
                break;
            }
            
            res <<= 1;
            res |= (d1[index] ? 1 : 0);
            --index;
        }
        
        while (index >= 0) {
            res <<= 1;
            --index;
        }
        
        return res;
    }
};