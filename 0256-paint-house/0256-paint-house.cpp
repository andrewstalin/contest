class Solution {
public:
    int func(int pos, int color, const std::vector<std::vector<int>>& costs, std::vector<std::vector<int>>& dp) {
        if (pos >= costs.size()) {
            return 0;
        }
        
        if (dp[color][pos] != -1) {
            return dp[color][pos];
        }
        
        int i1 = (color + 1) % 3;
        int i2 = (i1 + 1) % 3;
        int v1 = costs[pos][i1] + func(pos + 1, i1, costs, dp);
        int v2 = costs[pos][i2] + func(pos + 1, i2, costs, dp);
        
        dp[color][pos] = std::min(v1, v2);
        return dp[color][pos];
    }
    
    int minCost(vector<vector<int>>& costs) {
        std::vector<std::vector<int>> dp(3, std::vector<int>(costs.size(), -1));
        int v1 = costs[0][0] + func(1, 0, costs, dp);
        int v2 = costs[0][1] + func(1, 1, costs, dp);
        int v3 = costs[0][2] + func(1, 2, costs, dp);
        return std::min(v1, std::min(v2, v3));
    }
};