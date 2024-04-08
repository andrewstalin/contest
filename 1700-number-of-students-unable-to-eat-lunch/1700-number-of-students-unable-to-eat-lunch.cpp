class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero = 0 ;
        int one = 0;
        
        for (int i = 0; i < students.size(); ++i) {
            if (students[i] == 1) {
                ++one;
            } else {
                ++zero;
            }
        }
        
        for (int i = 0; i < sandwiches.size(); ++i) {
            if (sandwiches[i] == 1) { 
                if (one == 0) {
                    return zero;
                }
                
                --one;
            } else {
                if (zero == 0) {
                    return one;
                }
                
                --zero;
            }
        }
        
        return zero + one;
    }
};