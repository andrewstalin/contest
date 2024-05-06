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

    ListNode* removeNodes(ListNode* head) {
        std::list<ListNode*> queue;
        auto node = head;
        
        while (node != nullptr) {
            while (!queue.empty() && queue.front()->val < node->val) {
                queue.pop_front();
            }
            
            queue.push_front(node);
            node = node->next;
        }
        
        head = queue.back();
        queue.pop_back();
        node = head;
        
        while (!queue.empty()) {
            node->next = queue.back();
            node = queue.back();
            queue.pop_back();
        }
        
        node->next = nullptr;
        return head;
    }
};