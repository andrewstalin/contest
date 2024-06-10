class Solution {
public:
    int numberOfChild(int n, int k) {
        --n;
        int round = k / n;
        k %= n;
        return round % 2 == 0 ?  k : (n - k);
    }
};