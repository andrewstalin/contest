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

    
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        
        while (node != nullptr) {
            auto tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        auto node = head->next;
        auto prev = head;
        
        while (node != nullptr) {
            if (node->val >= prev->val) {
                prev->next = node;
                prev = node;
            }
            
            node = node->next;
        }
        
        prev->next = nullptr;
        return reverse(head);
    }
    
    ListNode* removeNodes0(ListNode* head) {
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