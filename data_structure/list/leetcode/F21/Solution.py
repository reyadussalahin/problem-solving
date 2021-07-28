# problem name: Merge Two Sorted Lists
# problem link: https://leetcode.com/problems/merge-two-sorted-lists/
# contest link: (?)
# time: (?)
# author: (?)


# other_tags: (?)
# difficulty_level: easy

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if None in (l1, l2):
            return l1 or l2
        # print(l1, l2)

        new = ListNode()
        start = new

        while l1 and l2:
            if l1.val <= l2.val:
                new.next = l1
                l1 = l1.next
            else:
                new.next = l2
                l2 = l2.next
            # print("new: ", new)
            new = new.next
            # print("new: ", new)
            # print("output_new: ", output_new)

        new.next = l1 or l2

        return start.next
