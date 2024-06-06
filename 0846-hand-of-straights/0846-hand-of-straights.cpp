class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        
        std::map<int, int> map;
        for (size_t i = 0; i < hand.size(); ++i) {
            ++map[hand[i]];
        }
        
        auto it = map.begin();
        
        while (it != map.end()) {
            int val = it->first;
            int count = 1;
            
            while (count < groupSize) {
                ++val;
                ++count;
                auto next = map.find(val);
                
                if (next == map.end() || next->second < it->second) {
                    return false;
                }
                
                next->second -= it->second;
                
                if (next->second == 0) {
                    map.erase(next);
                }
            }
            
            ++it;
        }
        
        return true;
    }
};