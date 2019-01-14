def insertionSortList(self, head):
    if not head: return head
    
    dummy = ListNode(0)
    curr = head
    prev = dummy
    
    while curr:
        next = curr.next
        while prev.next and prev.next.val < curr.val:
            prev = prev.next
        
        curr.next = prev.next
        prev.next = curr
        prev = dummy
        
        curr = next
    
    return dummy.next