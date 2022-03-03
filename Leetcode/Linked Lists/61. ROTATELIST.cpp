/**
Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        ListNode *tmp = head; ListNode *prev = NULL; int count = 1;
        while(tmp->next)
        {
            tmp = tmp->next; count++;
        }
        k %= count;
        tmp = head;
        while(k--)
        {
            while(tmp->next)
            {
                prev = tmp;
                tmp = tmp->next;
            }
            tmp->next = head;
            prev->next = NULL;
            head = tmp;
            tmp = head; prev = NULL;
            
        }
        return head;
    }
};
