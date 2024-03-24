class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (slow != fast);
        
        slow = nums[0];
        
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
    }
};