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
    ListNode* mergeTwoLists(ListNode* s1, ListNode* s2) {
        if(s1==NULL) return s2; if(s2==NULL) return s1;
        struct ListNode* res = NULL; struct ListNode* p = NULL; struct ListNode* r = NULL;
        while(s1!=NULL && s2!=NULL)
        {
            if(s1->val < s2->val)
            {
                p = s1;
                s1 = s1->next;
                p->next = NULL;
            }
            else
            {
                p = s2;
                s2 = s2->next;
                p->next = NULL;
            }
            if(res==NULL)
            {
                res = p; r = p;
            }
            else{
                r->next = p;
                r = p;
            }
        
        }
        if(s1==NULL) r->next = s2; 
        if(s2==NULL) r->next = s1;
        return res;
    }
};
