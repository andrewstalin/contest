class Solution {
public:

    
    int numSquares(int n) {
        std::vector<int> squares(100, 0);
        for (int i = 1; i <= 100; ++i) {
            squares[i - 1] = i*i;
        }
        
        std::vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            for (int k = 0; k < squares.size(); ++k) {
                if (squares[k] > i) {
                    break;
                }
                
                dp[i] = std::min(dp[i], dp[i - squares[k]] + 1);
            }
        }
        
        return dp[n];
    }
};