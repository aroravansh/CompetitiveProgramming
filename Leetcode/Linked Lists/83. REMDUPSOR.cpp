/**
 Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
 Input: head = [1,1,2]
 Output: [1,2]
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tmp = head; ListNode *prev;
        if(!head || !head->next)
            return head;
        prev = head;
        while(prev->next)
        {
            if(prev->val == prev->next->val)
            {
                tmp = prev->next;
                prev->next = tmp->next;
                delete tmp;
                continue;
            }
            prev = prev->next;
            
        }
        return head;
    }
};
