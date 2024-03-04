class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        std::sort(tokens.begin(), tokens.end());
        
        int l = 0;
        int r = tokens.size() - 1;
        int score = 0;
        
        while (l < r) {
            if(tokens[l] <= power) {
                power -= tokens[l];
                ++score;
                ++l;
            } else if (score > 0) {
                --score;
                power += tokens[r];
                --r;
            } else {
                break;
            }
        }
        
        if (l == r && tokens[l] <= power) {
            ++score;
        }
        
        return score;
    }
};