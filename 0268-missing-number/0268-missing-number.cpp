class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int v1 = nums.size();
        int v2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            v1 ^= i;
            v2 ^= nums[i];
        }
        
        return (v1^v2);
    }
};