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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        auto slow = head;
        auto fast = head;
        
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next != nullptr ? fast->next->next : nullptr;
        }
        
        ListNode* prev = nullptr;
        ListNode* next;
        while(slow != nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        auto node1 = head;
        auto node2 = prev;
        ListNode* next1;
        ListNode* next2;
        
        do {
            next1 = node1->next;
            next2 = node2->next;
            node1->next = node2;
            node2->next = next1;
            node1 = next1;
            node2 = next2;
        } while (next2 != nullptr);
        
        node1->next = nullptr;
    }
};