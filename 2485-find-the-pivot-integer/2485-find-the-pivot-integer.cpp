class Solution {
public:
    int pivotInteger(int n) {
        int v1 = 0;
        int v2 = 0;
        int i1 = 1;
        int i2 = n;
        
        while (i1 < i2) {
            if (v1 <= v2) {
                v1 += i1;
                ++i1;
            } else {
                v2 += i2;
                --i2;
            }
        }
        
        return v1 == v2 ? i1 : -1;
    }
};