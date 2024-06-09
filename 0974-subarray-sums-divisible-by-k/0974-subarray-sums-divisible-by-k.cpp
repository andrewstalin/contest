class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0;
        std::vector<int> map(k + 1, 0);
        map[0] = 1;
        int sum = 0;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            auto& it = map[(sum % k + k) % k];
            res += it;
            ++it;
        }

        return res;
    }
};



/*

[-5]
5
[-1,2,9]
2
[4,5,0,-2,-3,1]
5
[5]
9


*/