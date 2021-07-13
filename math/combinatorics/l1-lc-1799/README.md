## Solutions
```python
# problem name: Maximize Score After N Operations
# problem link: https://leetcode.com/contest/biweekly-contest-48/problems/maximize-score-after-n-operations/
# contest link: https://leetcode.com/contest/biweekly-contest-48/
# time: (?)
# author: reyad


# other_tags: bitmask, dynamic programming
# difficulty_level: beginner


import math

n = 0
nums = []
g = []
taken = []

def find(at, p):
    if at == n:
        sc = 0
        # note, sorted `g`, cause
        #       can't change order in `g`
        #       the numbers in g would be
        #       needed later
        for i, v in enumerate(sorted(g)):
            sc += (i+1) * v
        return sc
    if not taken[at]:
        mx = 0
        taken[at] = True
        for i in range(n):
            if not taken[i]:
                taken[i] = True
                g[p] = math.gcd(nums[at], nums[i])
                tmx = find(at+1, p+1)
                mx = max(mx, tmx)
                taken[i] = False
        taken[at] = False
        return mx
    return find(at+1, p)

class Solution:
    def maxScore(self, _nums):
        global n, nums, g, taken
        nums = _nums
        n = len(nums)
        taken = [False] * n
        g = [0] * (n // 2)
        return find(0, 0)

```
