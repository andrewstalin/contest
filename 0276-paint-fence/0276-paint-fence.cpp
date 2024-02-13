class Solution {
public:

    
    int numWays(int n, int k) {
        int c1 = k;
        int c2 = 0;
        int tmp;
        --k;
        
        for (int i = 2; i <= n; ++i) {
            tmp = (c1 + c2)*k;
            c2 = c1;
            c1 = tmp;
        }
        
        return c1 + c2;
    }
};