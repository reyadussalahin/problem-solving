# problem name: Convert Binary Number in a Linked List to Integer
# problem link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
# contest link: (?)
# time: (?)
# author: ratul14


# other_tags: math
# difficulty_level: easy




#submission_details: https://leetcode.com/submissions/detail/363880101/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        binary = 0;
        while (head is not None):
            binary = binary * 10 + head.val;
            head = head.next;
        return int(str(binary), 2);
