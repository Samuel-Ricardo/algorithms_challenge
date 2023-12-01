/**
 * Definition for singly-linked list.
 */
class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function addTwoNumbers(
  l1: ListNode | null,
  l2: ListNode | null
): ListNode | null {
  let next = true;
  const node = new ListNode(0);

  let sum = l1.val + l2.val;
  let up = 0;

  if (sum > 9) {
    sum -= 10;
    up = 1;
  }

  let nextNode = new ListNode(sum);
  node.next = nextNode;

  if (!l1.next && !l2.next) {
    if (up > 0) nextNode.next = new ListNode(up);
    return node.next;
  }

  while (next) {
    l1.next ? (l1 = l1.next) : (l1 = new ListNode(0));
    l2.next ? (l2 = l2.next) : (l2 = new ListNode(0));

    sum = l1.val + l2.val + up;
    up = 0;

    if (sum > 9) {
      sum -= 10;
      up = 1;
    }

    while (nextNode.next) nextNode = nextNode.next;

    nextNode.next = new ListNode(sum);

    next = !!l1.next || !!l2.next;
    if (!next && up > 0) nextNode.next.next = new ListNode(up);
  }

  return node.next;
}
