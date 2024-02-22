class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty()) {
            return n == 1 ? 1 : -1;
        }
        
        std::vector<int> persons(n + 1, 0);
        
        for (int i = 0; i < trust.size(); ++i) {
            ++persons[trust[i][1]];
            persons[trust[i][0]] = -1;
        }
        
        for (int i = 0; i <= n; ++i) {
            if(persons[i] == (n - 1)) {
                return i;
            }
        }
        
        return -1;
    }
};