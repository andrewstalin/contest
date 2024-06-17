class Solution {
public:
    bool judgeSquareSum(int c) {

        
        uint32_t end = c;
        uint32_t k = 0;
        uint32_t v1 = 0;
        uint32_t v2;
        
        std::unordered_set<int> set;
        
        while (v1 <= end) {
            if (2*v1 == end) {
                return true;
            }
            
            v2 = end - v1;
            
            if (set.find(v2) != set.end()) {
                return true;
            }
            
            set.emplace(v1);
            
            ++k;
            v1 = k*k;
        }
        
        return false;
    }
};