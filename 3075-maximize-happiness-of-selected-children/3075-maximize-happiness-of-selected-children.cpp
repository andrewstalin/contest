class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        std::sort(happiness.begin(), happiness.end());
        
        long long res = 0;
        
        for (int i = (happiness.size() - 1), val = 0; i >= 0 && k > 0; --i, --k, ++val) {
            if (happiness[i] <= val) {
                break;
            }
            
            res += happiness[i] - val;
        }
        
        return res;
    }
};