## Solutions
#### 1
##### Source Code
```python
# problem name: Maximum Number of Consecutive Values You Can Make
# problem link: https://leetcode.com/contest/biweekly-contest-48/problems/maximum-number-of-consecutive-values-you-can-make/
# contest link: https://leetcode.com/contest/biweekly-contest-48/
# time: (?)
# author: reyad


# other_tags: (?)
# difficulty_level: beginner


class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        ans = 1
        for v in sorted(coins):
            if v > ans:
                break
            ans += v
        return ans

```
