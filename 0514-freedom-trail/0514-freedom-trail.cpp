class Solution {
public:
    int func(int key_pos, int ring_pos, const std::string& key, const std::string& ring, const std::vector<std::vector<int>>& ring_data, std::vector<std::vector<int>>& dp) {
        if (key_pos >= key.size()) {
            return 0;
        }
        
        if (dp[key_pos][ring_pos] != -1) {
            return dp[key_pos][ring_pos];
        }
        
        if (ring[ring_pos] == key[key_pos]) {
            dp[key_pos][ring_pos] = 1 + func(key_pos + 1, ring_pos, key, ring, ring_data, dp);
            return dp[key_pos][ring_pos];
        }
        
        const auto& ring_chars = ring_data[key[key_pos] - 'a'];
        int val_right = 0;
        int pos_right = -1;
        
        if (ring_pos > ring_chars.back()) {
            pos_right = ring_chars[0];
            val_right = ring.size() - ring_pos + ring_chars[0];
        } else {
            int index = 0;
            
            while (ring_chars[index] < ring_pos) {
                ++index;
            }
            
            val_right = ring_chars[index] - ring_pos;
            pos_right = ring_chars[index];
        }
        
        val_right += func(key_pos + 1, pos_right, key, ring, ring_data, dp);
        
        int val_left = 0;
        int pos_left = -1;
        
        if (ring_chars[0] > ring_pos) {
            val_left = ring.size() - ring_chars.back() + ring_pos;
            pos_left = ring_chars.back();
        } else {
            int index = ring_chars.size() - 1;
            
            while (ring_chars[index] > ring_pos) {
                --index;
            }
            
            val_left = ring_pos - ring_chars[index];
            pos_left = ring_chars[index];
        }
        
        val_left += func(key_pos + 1, pos_left, key, ring, ring_data, dp);
        
        dp[key_pos][ring_pos] = std::min(val_left, val_right) + 1;
        return dp[key_pos][ring_pos];
    }
    
    int findRotateSteps(string ring, string key) {
        std::vector<std::vector<int>> ring_data(26, std::vector<int>());
        
        for (int i = 0; i < ring.size(); ++i) {
            ring_data[ring[i] - 'a'].push_back(i);
        }
        
        std::vector<std::vector<int>> dp(key.size(), std::vector<int>(ring.size(), -1));
        
        return func(0, 0, key, ring, ring_data, dp);
    }
};