class Solution {
public:
    inline bool check(int val) {
        uint32_t mask = 0;
        int v;
        
        while (val > 0) {
            v = val % 10;
            val /= 10;
            
            if (((1u << v) & mask) != 0) {
                return false;
            }
            
            mask |= (1u << v);
        }
        
        return true;
    }
    
    int numberCount(int a, int b) {
        int res = 0;
        
        for (int i = a; i <= b; ++i) {
            if (check(i)) {
                ++res;
            }
        }
        
        return res;
    }
};