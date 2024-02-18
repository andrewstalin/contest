class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        std::vector<std::string> res;
        res.reserve(words.size());
        res.emplace_back(std::move(words[0]));
        int group = groups[0];
        
        for (int i = 1; i < words.size(); ++i) {
            if (group != groups[i]) {
                group = groups[i];
                res.emplace_back(std::move(words[i]));
            }
        }
         
        return res;
    }
};
