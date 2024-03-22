class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        std::sort(capacity.begin(), capacity.end());
        int res = 1;
        
        int apple_index = 0;
        int apple_value = apple[apple_index];
        int capacity_index = capacity.size() - 1;
        int capacity_value = capacity[capacity_index];
        
        while (apple_index < apple.size()) {
            int min = std::min(capacity_value, apple_value);
            apple_value -= min;
            capacity_value -= min;
            
            if (apple_value == 0) {
                if(++apple_index < apple.size()) {
                    apple_value = apple[apple_index];
                }
                continue;
            }
            
            if (--capacity_index >= 0) {
                ++res;
                capacity_value = capacity[capacity_index];
            }
        }
        
        return res;
    }
};