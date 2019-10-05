# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        aux = head
        cont = 1
        while aux.next:
            cont += 1
            aux = aux.next
        print(cont)
        if cont%2 == 0:
            posicao = (cont/2)+1
        else:
            posicao = (cont//2)+1
        aux = head
        cont = 1
        while True:
            if cont == posicao:
                return aux
            aux = aux.next
            cont += 1