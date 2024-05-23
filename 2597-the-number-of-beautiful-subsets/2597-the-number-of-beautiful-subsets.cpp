class Solution {
public:
    int func(int pos, const std::vector<int>& nums, std::vector<int>& set, int k) {
        if (pos >= nums.size()) {
            return 1;
        }
        
        int res = func(pos + 1, nums, set, k);

        if ((nums[pos] <= k || set[nums[pos] - k] == 0) 
                && (nums[pos] + k > 1000 || set[nums[pos] + k] == 0)) {
            ++set[nums[pos]];
            res += func(pos + 1, nums, set, k);
            --set[nums[pos]];
        }
        
        return res;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        std::vector<int> set(1001, 0);
  
        return func(0, nums, set, k) - 1;
    }
};




/*

[2,4,6]
2
[1]
1
[4,2,5,9,10,3]
1
[10,4,5,7,2,1]
3
[1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000]
1
[590,136,844,976,670,485,794,114,434,82,245,673,738,416,252,1000,518,520,1,622]
999
[18, 12, 10, 5, 6, 2, 18, 3]
8


*/