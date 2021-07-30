# problem name: Swap Nodes in Pairs
# problem link: https://leetcode.com/problems/swap-nodes-in-pairs/
# contest link: (?)
# time: (?)
# author: psimanta


# other_tags: (?)
# difficulty_level: medium


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head:
            return head

        dummy = ListNode()
        dummy.next = head
        head = dummy
        # if input 1 -> 2 -> 3 -> 4
        # head -> 0 -> 1 -> 2 -> 3 -> 4
        # dummy -> 0 -> 1 -> 2 -> 3 -> 4

        while head.next and head.next.next:
            t1, t2 = head.next, head.next.next
            head.next = t2
            t1.next = t2.next
            t2.next = t1
            head = t1

        return dummy.next
