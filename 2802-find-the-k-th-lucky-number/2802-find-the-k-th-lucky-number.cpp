class Solution {
public:
    inline std::string to_binary(int val) {
        std::string res;
        res.reserve(32);
        
        while (val > 0) {
            res.push_back((val & 1) == 1 ? '1' : '0');
            val >>= 1;
        }
        
        return res;
    }
    
    string kthLuckyNumber(int k) {
        if (k == 1) {
            return "4";
        }
        
        if (k == 2) {
            return "7";
        }
        
        int val = 2;
        int sum = 0;
        int count = 0;
        
        while (sum < k) {
            sum += val;
            val *= 2;
            ++count;
        }
        
        sum -= val/2;
        
        std::string res;
        res.reserve(32);
        
        auto bin = to_binary(k - sum - 1);
        
        for (int i = bin.size(); i < count; ++i) {
            res.push_back('4');
        }
        
        for (int i = (bin.size() - 1); i >= 0; --i) {
            res.push_back(bin[i] == '0' ? '4' : '7');
        }
        
        return res;
    }
};