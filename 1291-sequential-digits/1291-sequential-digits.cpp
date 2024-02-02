class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int tail = 2;
        int val = 12;
        int k = 3;
        int d = 10;
        
        std::vector<int> res;
        
        while (true) {
            if (val >= low && val <= high) {
                res.emplace_back(val);
            }
            
            if (k == 10) {
                ++tail;
                
                if (tail == 10) {
                    break;
                }
                
                val = 1;
                
                for (int i = 2; i <= tail; ++i) {
                    val *= 10;
                    val += i;
                }
                
                k = tail + 1;
                d *= 10;
                continue;
            }
            
            val %= d;
            val *= 10;
            val += k;
            ++k;
        }
        
        return res;
    }
};