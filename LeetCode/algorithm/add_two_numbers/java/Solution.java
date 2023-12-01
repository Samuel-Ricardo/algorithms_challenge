 class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }

public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        boolean next = true;

        while(next) {
            int sum = l1.val + l2.val;
            int up = 0;

            if(sum > 9) {
                sum -= 10;
                up = 1;
            }

            new ListNode(sum, new ListNode());

            next = l1.next != null || l2.next != null;

        }

    }
}