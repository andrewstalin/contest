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
    string gameResult(ListNode* head) {
        int odd{ 0 };
        int even{ 0 };
        auto node = head;
        
        while (node != nullptr) {
            if (node->val == node->next->val) {
                node = node->next->next;
                continue;
            }
            
            if (node->val > node->next->val) {
                ++even;
            } else {
                ++odd;
            }
            
            node = node->next->next;
        }
        
        if (odd == even) {
            return "Tie";
        }
        return odd > even ? "Odd" : "Even";
    }
};