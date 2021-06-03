/*
Designing a Simple Double Linked list
*/
struct DoublyListNode {
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

class MyLinkedList {
public:
    DoublyListNode* head;
    int numOfNodes;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        numOfNodes = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0)
            return -1;
 
        int count = 0;
        DoublyListNode* temp = head;
        while(temp)
        {
            if(count == index)
                return temp->val;
            temp = temp->next;
            count++;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        DoublyListNode* node = new DoublyListNode(val);
        if(head == NULL)
            head = node;
        else
        {
            DoublyListNode* temp = head;
            node->next = temp;
            temp->prev = node;
            head = node;
        }
        numOfNodes++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        DoublyListNode* node = new DoublyListNode(val);
        if(head == NULL)
            head = node;
        else
        {
            DoublyListNode* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
            node->prev = temp;
        }
        numOfNodes++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > numOfNodes)
            return;

        if(index == 0)
        {
            addAtHead(val);
            return;
        }
                
        if(index == numOfNodes)
        {
            addAtTail(val);
            return;
        }
        
        if(head != NULL)
        {
            int count = 0;
            DoublyListNode* temp = head;
            while(temp->next != NULL)
            {
                if(count == index)
                    break;
                temp = temp->next;
                count++;
            }

            DoublyListNode* node = new DoublyListNode(val);
            temp->prev->next = node;
            node->prev = temp->prev;
            node->next = temp;
            temp->prev = node;
            numOfNodes++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= numOfNodes || head == NULL)
            return;
        
        if(index == 0)
        {
            DoublyListNode* temp = head;
            head = head->next;
            delete(temp);
        }
        else
        {
            int count = 0;
            DoublyListNode* temp = head;
            while(temp->next != NULL)
            {
                if(count == index)
                    break;
                temp = temp->next;
                count++;
            }

            if(index == numOfNodes-1)
            {
                temp->prev->next = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete(temp);
        }
        numOfNodes--;
    }
};
