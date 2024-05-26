class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) {
            return 3;
        }
        
        std::vector<uint64_t> a(3, 0);
        std::vector<uint64_t> b(3, 0);
        
        a[0] = 1;
        b[0] = 1;
        b[1] = 1;
        
        uint64_t a0;
        uint64_t b0;
        
        for (int i = 1; i < n; ++i) {
            a0 = a[0];
            a[0] += a[1] + a[2] + b[0] + b[1] + b[2];
            a[2] = a[1];
            a[1] = a0;
            
            b0 = b[0];
            b[0] += b[1] + b[2];
            b[2] = b[1];
            b[1] = b0;
            
            a[0] %= 1000000007;
            b[0] %= 1000000007;
        }
        
        return (a[0] + a[1] + a[2] + b[0] + b[1] + b[2]) % 1000000007;
    }
};