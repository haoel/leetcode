# merge sort:

def sortList(self, head):
    if not head or not head.next: return head
    leftHalf, rightHalf = self.split(head)
    left = self.sortList(leftHalf)
    right = self.sortList(rightHalf)
    return self.mergeSorted(left, right)
    
def mergeSorted(self, a, b):
    res = dummy = ListNode(0)
    while a and b:
        if a.val < b.val:
            dummy.next = a
            dummy = a
            a = a.next
        else:
            dummy.next = b
            dummy = b
            b = b.next
    if not a: dummy.next = b
    else: dummy.next = a

    return res.next
    
def split(self, node):
    if not node or not node.next:
        return node, None
    slow, fast = node, node
    prev = None
    while fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
        if not fast: break
    prev.next = None
    return node, slow