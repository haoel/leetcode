def reorderList(self, head):
    if not head or not head.next: return
    
    # Step 1: find the middle node
    middle = None
    slow, fast = head, head
    while fast and fast.next:
        middle = slow
        slow = slow.next
        fast = fast.next.next
    middle.next = None
    
    # Step 2: reverse the second half
    prev = None
    while slow:
        nextNode = slow.next
        slow.next = prev
        prev, slow = slow, nextNode
        
    # Step 3: merge two lists
    while head and prev:
        first, second = head.next, prev.next
        head.next = prev
        if first: prev.next = first
        head, prev = first, second