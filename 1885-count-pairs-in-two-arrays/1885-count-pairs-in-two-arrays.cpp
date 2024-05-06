class Solution {
public:
    // sum on interval [l, end)
    int query(int r, const std::vector<int>& data) {
        int res = 0;
        int l = 0;

        int N = data.size() / 2;
        l += N;
        r += N;

        while (l < r) {
            if (l & 1) {
                res += data[l++];
            }

            if (r & 1) {
                res += data[--r];
            }

            l >>= 1;
            r >>= 1;
        }

        return res;
    }

    // add 1 at position p
    void modify(int p, std::vector<int>& data) {
        p += data.size() / 2;
        data[p] += 1;

        while (p > 1) {
            data[p >> 1] = data[p] + data[p ^ 1];
            p >>= 1;
        }
    }
    
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> data(400004, 0);
    
        long long res = 0;
        modify(nums2.back() - nums1.back() + 100000, data);
        
        int r;
        for (int i = (nums1.size() - 2); i >= 0; --i) {
            r = nums1[i] - nums2[i] + 100000;
            res += query(r, data);
            modify(nums2[i] - nums1[i] + 100000, data);
        }
        
        
        return res;
    }
};