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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto node2 = list2;
        while (node2->next != nullptr) {
            node2 = node2->next;
        }
        
        auto node1 = list1;
        while (a > 1) {
            node1 = node1->next;
            --a;
            --b;
        }
        
        auto tail = node1->next;
        node1->next = list2;
        
        while (b > 0) {
            tail = tail->next;
            --b;
        }
        
        node2->next = tail;
        return list1;
    }
};