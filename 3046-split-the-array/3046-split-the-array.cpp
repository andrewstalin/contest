class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        std::vector<int> data(101, 0);
        
        for (auto num : nums) {
            ++data[num];
        }
        
        for (auto val : data) {
            if (val > 2) {
                return false;
            }
        }
        
        return true;
    }
};