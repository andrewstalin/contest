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
    ListNode* frequenciesOfElements(ListNode* head) {
        std::vector<int> data(100001, 0);
        
        auto node{ head };
        while (node != nullptr) {
            ++data[node->val];
            node = node->next;
        }
        
        node = head;
        ListNode* prev{ nullptr };
        
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] > 0) {
                node->val = data[i];
                prev = node;
                node = node->next;
            }
        }
        
        prev->next = nullptr;
        return head;
    }
};