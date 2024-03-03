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
    ListNode* removeNthFromEnd(ListNode* head, int n) {  
        ListNode* prev{ nullptr };
        ListNode* l{ head };
        ListNode* r{ head };
        
        while (n > 0) {
            r = r->next;
            --n;
        }
        
        while (r != nullptr) {
            r = r->next;
            prev = l;
            l = l->next;
        }
        
        if (prev != nullptr) {
            prev->next = l->next;
        } else {
            head = head->next;
        }

        return head;
    }
};