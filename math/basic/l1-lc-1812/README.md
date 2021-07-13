## Solutions
```python
# problem name: Determine Color of a Chessboard Square
# problem link: https://leetcode.com/contest/biweekly-contest-49/problems/determine-color-of-a-chessboard-square/
# contest link: https://leetcode.com/contest/biweekly-contest-49/
# time: (?)
# author: reyad


# other_tags: (?)
# difficulty_level: beginner

class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        v = (ord(coordinates[0]) - ord('a') + 1) + ord(coordinates[1]) - ord('0')
        print(v)
        if (v&1) == 0:
            return False
        return True
```
