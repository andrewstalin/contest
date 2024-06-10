class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int index = skills[0] > skills[1] ? 0 : 1;
        int count = 1;
        
        for (size_t i = 2; i < skills.size() && count < k; ++i) {
            if (skills[i] < skills[index]) {
                ++count;
            } else {
                index = i;
                count = 1;
            }
        }
        
        return index;
    }
};