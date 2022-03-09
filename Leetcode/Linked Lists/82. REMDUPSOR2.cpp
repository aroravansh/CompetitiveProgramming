/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted 
as well.
Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *tmp = head; ListNode *prev,*curr,*forw;
        ListNode *node = new ListNode(0,head); head = node;
        prev = head; curr = head->next; forw = head->next->next;
        while(forw)
        {
            if(curr->val == forw->val)
            {
                tmp = curr;
                while(forw && curr->val == forw->val)
                {
                    curr = curr->next;
                    forw = forw->next;
                }
                curr = forw;
                forw = forw?forw->next:forw;
                prev->next = curr;
            }
            else{
            prev = curr;
            curr = forw;
            forw = forw->next; }
        }
        tmp = head;
        head = head->next;
        delete tmp;
        
        return head;
    }
};
