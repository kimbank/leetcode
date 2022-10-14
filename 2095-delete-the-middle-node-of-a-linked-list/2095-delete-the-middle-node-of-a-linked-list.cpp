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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* cur = head;
        ListNode* mid = head;
        
        if (cur->next == nullptr) return nullptr;
        
        for (int i = -1;;i++) {
            if (cur->next == nullptr) break;
            
            if (i % 2 == 1) {
                mid = mid->next;
            }
            
            cur = cur->next;
        }
        
        mid->next = mid->next->next;
        
        return head;
    }
};