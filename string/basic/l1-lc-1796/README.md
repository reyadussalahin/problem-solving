## Solutions
#### 1
##### Source Code
```python
# problem name: Second Largest Digit in a String
# problem link: https://leetcode.com/contest/biweekly-contest-48/problems/second-largest-digit-in-a-string/
# contest link: https://leetcode.com/contest/biweekly-contest-48/
# time: (?)
# author: reyad


# other_tags: set, brute force
# difficulty_level: beginner


class Solution:
    def secondHighest(self, s: str) -> int:
        b = [0] * 12
        for ch in s:
            if ch.isdigit():
                b[ord(ch) - 48] += 1
        c = 0
        for i in range(9, -1, -1):
            if b[i] != 0:
                c += 1
            if c == 2:
                return i
        return -1
        
```
