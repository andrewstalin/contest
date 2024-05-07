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
    inline ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* tmp;
        
        while (node != nullptr) {
            tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        
        ListNode* node = head;
        ListNode* prev = nullptr;
        int val = 0;
        
        while (node != nullptr) {
            prev = node;
            node->val *= 2;
            node->val += val;
            val = node->val / 10;
            node->val %= 10;
            node = node->next;
        }
        
        if (val > 0) {
            prev->next = new ListNode(1);
        }
        
        head = reverse(head);
        return head;
    }
};