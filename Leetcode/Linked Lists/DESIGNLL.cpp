/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are
0-indexed.
Implement the MyLinkedList class:
MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be 
appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]
*/
class Node {
public:
    int     val;
    Node*   next;
    Node(int val) { this->val = val; next = NULL; }
};

class MyLinkedList {
private:
    Node* head;
    
public:
    MyLinkedList() { head = new Node(0); }
    ~MyLinkedList() { delete head; }
    
    /** Get the value of the index-th node in the linked list.
    If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0) return -1;
        Node* temp = head->next;
        for (int i = 0; i < index; i++) temp = temp->next;
        return temp == nullptr ? -1 : temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list.
    After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *new_first = new Node(val);
        new_first->next = head->next;
        head->next = new_first;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* tail = head;
        while(tail->next != NULL) tail = tail->next;
        tail->next = new Node(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list.
    If index equals to the length of linked list, the node will be appended to the end of linked list.
    If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0) return;
        if (index == 0) { addAtHead(val); return; }
               
        Node* node = head;
        for (int i = 0; i < index; i++) { node = node->next; }
        if (node == NULL) { return; }
        if (node->next == NULL) { addAtTail(val); return; }
        
        Node* next_node = node->next;
        node->next = new Node(val);
        node->next->next = next_node;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0) return;
        
        Node* temp=head;
        for(int i = 0; i < index; i++) temp=temp->next;
        if (temp == NULL) { return; }
        if (temp->next == NULL) { return; }
        
        Node* temp1=temp->next;
        temp->next=temp1->next;
        temp1->next=NULL;
        
        delete temp1;
    }
};
