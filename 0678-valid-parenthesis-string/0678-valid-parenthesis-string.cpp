class Solution {    
public:    
    bool func(int pos, int open, const std::string& s, std::vector<std::vector<char>>& dp) {
        if (pos >= s.size()) {
            return open == 0;
        }
        
        if (dp[pos][open] != -1) {
            return dp[pos][open] == 1;
        }
        
        dp[pos][open] = false;
        
        if (s[pos] == '(') {
            dp[pos][open] = func(pos + 1, open + 1, s, dp);
        } else if (s[pos] == ')') {
            if (open != 0) {
                dp[pos][open] = func(pos + 1, open - 1, s, dp);
            }
        } else {
            dp[pos][open] = func(pos + 1, open, s, dp);
            
            if (!dp[pos][open]) {
                dp[pos][open] = func(pos + 1, open + 1, s, dp);
            }
            
            if (!dp[pos][open] && open > 0) {
                dp[pos][open] = func(pos + 1, open - 1, s, dp);
            }
        }
        
        return dp[pos][open];
    } 
    
    bool checkValidString(string s) {
        std::vector<std::vector<char>> dp(s.size(), std::vector<char>(s.size(), -1));
        return func(0, 0, s, dp);
    }
    
};

/*

"()"
"(*)"
"(*))"
"(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"
"(((((()*)(*)*))())())(()())())))((**)))))(()())()"
"((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"

*/




