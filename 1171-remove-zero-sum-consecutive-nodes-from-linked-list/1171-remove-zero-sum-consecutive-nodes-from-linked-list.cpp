/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        std::vector<std::pair<int, int>> data(1001, std::make_pair(INT32_MAX, INT32_MAX));
        std::unordered_map<int, int> map(1000);
        int pos = -1;
        ListNode* node = head;
        int sum = 0;
        
        while (node != nullptr) {
            if (node->val == 0) {
                node = node->next;
                continue;
            }
            
            sum += node->val;
            
            if (sum == 0) {
                pos = -1;
                node = node->next;
                map.clear();
                continue;
            }
            
            auto it = map.find(sum);
            
            if (it != map.end()) {
                for (int j = pos; j > it->second; --j) {
                    map.erase(data[j].second);
                }
                
                pos = it->second;
                sum = it->first;
                node = node->next;
                continue;
            }
            
            ++pos;
            data[pos].first = node->val;
            data[pos].second = sum;
            map[sum] = pos;
            node = node->next;
        }
        
        ListNode* prev = nullptr;
        node = head;
        
        for (int i = 0; i <= pos; ++i) {  
            prev = node;
            node->val = data[i].first;
            node = node->next; 
        }
        
        if (prev == nullptr) {
            return nullptr;
        }
        
        prev->next = nullptr;
        return head;
    }
};


/*

[1,-1]
[2,0]
[3,4,3,4,-5,-4,5,-4,3,5,-5]

[1,2,-3,3,1]
[1,2,3,-3,4]
[1,2,3,-3,-2]

*/

