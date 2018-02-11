package reverseLinkedListII;

public class ListNode {
	public int val;
	public ListNode next;
	public ListNode(int x) {
		val = x;
	}
	@Override
	public String toString() {
		return "ListNode [val=" + val + "]";
	}
	public ListNode(int val, ListNode next) {
		super();
		this.val = val;
		this.next = next;
	}
	/**
	 * This is an assistant function, use it, we can easily see the structure of list
	 */
	public static String listToString(ListNode head) {
		if (head == null) {
			return "";
		}
		StringBuilder sb = new StringBuilder();
		while (head.next != null) {
			sb.append(head.val).append(",");
			head = head.next;
		}
		sb.append(head.val);
		return sb.toString();
	}
	
	/**
	 * This is an assistant function, use it, we can create a linkedList by array.
	 */
	public static ListNode arrayToList(int[] array) {
		ListNode head = new ListNode(0);
		ListNode p = head;
		for (int i : array) {
			p.next = new ListNode(i);
			p = p.next;
		}
		return head.next;
	}
}
