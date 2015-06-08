/*
*   leetcode 206 Reverse Linked List
*   A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

ListNode* Solution::reverseListIteratively(ListNode *head) {
    
    if (head == NULL) {
        return head;
    }
    
    // A pointer points to the next node
    ListNode* next = head;
    // A pointer points to the previous node
    ListNode* pre = head;
    
    next = head->next;
    head->next = NULL;
    
    
    while (next != NULL) {
        head = next;
        next = head->next;
        head->next = pre;
        pre = head;
    }
    
    return head;
};

ListNode* Solution::reverseListRecursively(ListNode* head) {
    
    if (head == NULL) {
        return head;
    }
    
    if (head->next == NULL) {
        // This is the tail node, so we return it back
        return head;
    }
    
    // tailNode will be the new head in reversed list
    ListNode* tailNode = reverseListRecursively(head->next);
    
    // Reverse node
    head->next->next = head;
    head->next = NULL;
    
    // Return back the pointer that points to tail node
    return tailNode;
}