class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) {
            return true;
        }
        
        uint32_t end = c;
        uint32_t k = 1;
        uint32_t v1 = 1;
        uint32_t v2;
        
        while (v1 <= end) {
            if (2*v1 == end) {
                return true;
            }
            
            v2 = end - v1;
            
            if (v2 == 0) {
                return true;
            }
            
            uint32_t l = 0;
            uint32_t r = std::sqrt(v2) + 1;
            
            while (r - l > 1) {
                uint32_t mid = l + (r - l)/2;
                uint32_t s = mid*mid;
                
                if (s > v2) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            
            if (l*l == v2){
                return true;
            }
            
            ++k;
            v1 = k*k;
        }
        
        return false;
    }
    
    bool judgeSquareSum0(int c) {
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