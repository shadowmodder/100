/*
https://www.lintcode.com/en/problem/middle-of-linked-list/  

Return the middle node of the linkedlist

NOT TEST!!
*/

Node * getMidNode(Node *head) {
    Node * slow = head;
    Node * fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}