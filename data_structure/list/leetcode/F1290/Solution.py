# problem name: Convert Binary Number in a Linked List to Integer
# problem link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
# contest link: (?)
# time: (?)
# author: ratul14


# other_tags: math
# difficulty_level: easy


class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        binary = 0;
        while (head is not None):
            binary = binary * 10 + head.val;
            head = head.next;
        return int(str(binary), 2);
