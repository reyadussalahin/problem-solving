## Solutions
```python
# problem name: Number of Different Subsequences GCDs
# problem link: https://leetcode.com/contest/weekly-contest-235/problems/number-of-different-subsequences-gcds/
# contest link: https://leetcode.com/contest/weekly-contest-235/
# time: (?)
# author: reyad


# other_tags: data structure, sorting
# difficulty_level: beginner


class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        s = {v for v in nums}
        n = sorted(s)[-1] + 1
        cnt = 0
        for i in range(1, n):
            d = []
            for j in range(i, n, i):
                if j in s:
                    d.append(j // i)
            if len(d) > 0:
                g = d[0]
                for i in range(1, len(d)):
                    g = math.gcd(g, d[i])
                if g == 1:
                    cnt += 1
        return cnt

```
