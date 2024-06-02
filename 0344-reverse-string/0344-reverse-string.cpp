class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t l = 0;
        size_t r = s.size() - 1;

        while (l < r) {
            std::swap(s[l], s[r]);
            ++l;
            --r;
        }
    }
};