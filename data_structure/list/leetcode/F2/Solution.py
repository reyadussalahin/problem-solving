# problem name: Add Two Numbers
# problem link: https://leetcode.com/problems/add-two-numbers/
# contest link: (?)
# time: (?)
# author: (?)
# description: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.


# other_tags: (?)
# difficulty_level: medium

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ptr = ListNode(0)
        # two nodes where val = 0 and next = None
        carry = 0

        while l1 or l2:
            if l1 is None:
                l1 = ListNode(0)
            if l2 is None:
                l2 = ListNode(0)
            # if one list is shorter than other it will keep creating new nodes, so that the below expression can be executed

            s = l1.val + l2.val + carry
            carry = int(s / 10)

            ptr.next = ListNode(s % 10)
            ptr = ptr.next
            l1 = l1.next
            l2 = l2.next

        if carry > 0:
            ptr.next = ListNode(carry)

        return head.next
