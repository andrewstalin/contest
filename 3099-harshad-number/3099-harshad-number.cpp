class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int val = x;
        int sum = 0;
        
        while (val > 0) {
            sum += val % 10;
            val /= 10;
        }
        
        return x % sum == 0 ? sum : -1;
    }
};