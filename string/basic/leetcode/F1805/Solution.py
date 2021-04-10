# problem name: Number of Different Integers in a String
# problem link: https://leetcode.com/contest/weekly-contest-234/problems/number-of-different-integers-in-a-string/
# contest link: https://leetcode.com/contest/weekly-contest-234/
# time: (?)
# author: reyad


# other_tags: (?)
# difficulty_level: beginner


class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        a = ord('a')
        for i in range(26):
            ch = chr(a + i)
            word = word.replace(ch, " ")
        return len(set([int(_) for _ in word.split()]))
