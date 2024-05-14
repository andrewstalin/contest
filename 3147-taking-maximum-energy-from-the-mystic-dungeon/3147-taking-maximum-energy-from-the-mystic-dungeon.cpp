class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        std::vector<int> dp(energy.size(), 0);
        int res = INT32_MIN;
        
        for (int i = (energy.size() - 1), end = (energy.size() - k); i >= end; --i) {
            dp[i] = energy[i];
            res = std::max(res, dp[i]);
        }
        
        for (int i = (energy.size() - k - 1); i >= 0; --i) {
            dp[i] = dp[i + k] + energy[i];
            res = std::max(res, dp[i]);
        }
        
        return res;
    }
};