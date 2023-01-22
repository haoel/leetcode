/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry=0,sum=0,add=0;
        ListNode head=new ListNode();
        ListNode n=new ListNode(0,head);
        while(l1!=null || l2!=null){
            ListNode l3=new ListNode();
            if(l1!=null && l2!=null){
                add=l1.val+l2.val;
                l1=l1.next;
                l2=l2.next;
            }
            else if(l1!=null){
                add=l1.val;
                l1=l1.next;
            }
            else{
                add=l2.val;
                l2=l2.next;
            }

            sum=(add+carry)%10;
            carry=(add+carry)/10;

            if(head==null){
                head.val=sum;
                head.next=null;
            }
            else{
                // n=head;
                while(n.next!=null){
                    n=n.next;
                }
                l3.val=sum;
                l3.next=null;
                n.next=l3;

            }

        }
        if(carry==1){
            ListNode node=new ListNode();
            node.val=carry;
            node.next=null;
            while(n.next!=null)
            n=n.next;
            n.next=node;
        }

        return head.next;
    }
}
