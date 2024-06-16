
std::vector<int> build(const std::vector<int>& data) {
    std::vector<int> result(data.size()*2, 0);

    for(int i = 0; i < data.size(); ++i) {
        result[data.size() + i] = data[i];
    }

    for (int i = data.size() - 1; i > 0; --i) {
        result[i] = result[i << 1] + result[(i << 1) | 1];
    }

    return result;
}

int query(int l, int r, const std::vector<int>& data) {
    int res = 0;
    
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

void modify(int p, std::vector<int>& data) {
    p += data.size() / 2;
    data[p] = data[p] == 0 ? 1 : 0;

    while (p > 1) {
        data[p >> 1] = data[p] + data[p ^ 1];
        p >>= 1;
    }
}

inline int get_value(int pos, const std::vector<int>& data) {
    return data[pos + data.size()/2];
}

class Solution {
public:
    inline void check_peak(int pos, const std::vector<int>& nums, std::vector<int>& segment_tree) {
        if (pos == 0 || pos >= (nums.size() - 1)) {
            return;
        }
        
        int cur = get_value(pos, segment_tree);
        
        if ((cur == 1 && (nums[pos] <= nums[pos - 1] || nums[pos] <= nums[pos + 1]))
            || (cur == 0 && nums[pos] > nums[pos - 1] && nums[pos] > nums[pos + 1])) {
            modify(pos, segment_tree);
        }
    }
    
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        std::vector<int> data(nums.size());
        size_t end = nums.size() - 1;
        
        for (size_t i = 1; i < end; ++i) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                data[i] = 1;
            }
        }
        
        auto segment_tree = build(data);
        
        std::vector<int> res;
        res.reserve(queries.size());
        
        for (const auto& q : queries) {
            if (q[0] == 1) {
                if (q[2] - q[1] < 2) {
                    res.emplace_back(0);
                    continue;
                }
                int val = query(q[1], q[2] + 1, segment_tree);
                
                if (get_value(q[1], segment_tree) == 1) {
                    --val;
                }
                
                if (get_value(q[2], segment_tree) == 1) {
                    --val;
                }
                
                res.emplace_back(val);
            } else {
                nums[q[1]] = q[2];
                
                if (q[1] > 0) {
                    check_peak(q[1], nums, segment_tree);
                    check_peak(q[1] - 1, nums, segment_tree);
                }
                
                if (q[1] + 1 < (nums.size() - 1)) {
                    check_peak(q[1] + 1, nums, segment_tree);
                }
            }
        }
        
        return res;
    }
};




/*

[3,1,4,2,5]
[[2,3,4],[1,0,4]]
[4,1,4,2,1,5]
[[2,2,4],[1,0,2],[1,0,4]]
[8,10,10,9,10]
[[2,0,1],[2,2,7],[1,0,2]]
[5,4,8,6]
[[1,2,2],[1,1,2],[2,1,6]]
[3,9,9,5,3,10]
[[2,1,7],[2,1,4],[1,2,4]]

*/

