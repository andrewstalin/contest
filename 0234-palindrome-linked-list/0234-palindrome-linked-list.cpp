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
        ListNode* next;
        
        while (node != nullptr) {
            next = node->next;
            node->next= prev;
            prev = node;
            node = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) {
            return true;
        }
        
        int count = 0;
        auto node = head;
        while (node != nullptr) {
            ++count;
            node = node->next;
        }
        
        int middle = (count + 1)/2;
        node = head;
        
        while (middle > 0) {
            --middle;
            node = node->next;
        }
        
        auto node1 = head;
        auto node2 = reverse(node);
        
        middle = count/2;
        while (middle > 0) {
            --middle;
            
            if (node1->val != node2->val) {
                return false;
            }
            
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return true;
    }
};