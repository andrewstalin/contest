class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<uint8_t> data(1001, 0);
        for (const auto& num : nums1) {
            data[num] |= 1;
        }
        
        for (const auto& num : nums2) {
            data[num] |= 2;
        }
        
        std::vector<int> res;
        res.reserve(std::min(nums1.size(), nums2.size()));
        
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == 3) {
                res.emplace_back(i);
            }
        }
        
        return res;
    }
};