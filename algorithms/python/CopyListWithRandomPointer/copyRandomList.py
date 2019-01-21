# method 1: using a dict and store each node as key, each copied node as value
# Space complexity: O(n)
# Time complexity: O(n)

def copyRandomList(self, head):
    d = {}
    m = n = head
    while m:
        d[m] = RandomListNode(m.label)
        m = m.next
        
    while n:
        d[n].next = d.get(n.next)
        d[n].random = d.get(n.random)
        n = n.next
        
    return d.get(head)

# Method 2:
# Space complexity: O(1)
# Time complexity: O(n)

def copyRandomList(self, head):
    if not head: return None
    
    # Step 1: copy each node and link them together with original ones 
    curr = head
    while curr:
        new = RandomListNode(curr.label)
        new.next = curr.next
        curr.next = new
        curr = curr.next.next
    
    # Step 2: build random node for each copied nodes
    curr = head    
    while curr:
        if curr.random: curr.next.random = curr.random.next
        curr = curr.next.next
        
    # Step 3: restore the original list and extract copied list
    newhead = head.next
    pold = head
    pnew = newhead
    while pnew.next:
        pold.next = pnew.next
        pold = pold.next
        pnew.next = pold.next
        pnew = pnew.next
    pold.next = None
    pnew.next = None
    return newhead