class Solution {
public:

    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        std::vector<int> dp(arr.size() + 1, 0);
        
        for(int i = (arr.size() - 1); i >= 0; --i) {
            int max = -1;
            int sum = 0;
            
            for (int j = i; j < arr.size() && j < (i + k); ++j) {
                max = std::max(max, arr[j]);
                sum = std::max(sum, max*(j - i + 1) + dp[j + 1]);
            }
            
            dp[i] = sum;
        }
        
        return dp[0];
    }
};