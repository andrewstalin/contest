class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        
        bool not_done = true;
        while (n > 0 && not_done) {
            if ((n & 1) != 0) {
                not_done = false;
            }
            
            n >>= 1;
        }
        
        return n == 0;
    }
};