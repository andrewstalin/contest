class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        std::vector<int> data(101, 0);
        
        for (const auto& num : nums) {
            ++data[num];
        }
        
        for (const auto& val : data) {
            if (val > 2) {
                return false;
            }
        }
        
        return true;
    }
};