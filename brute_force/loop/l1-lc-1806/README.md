## Solutions
#### 1
##### Source Code
```python
# problem name: Minimum Number of Operations to Reinitialize a Permutation
# problem link: https://leetcode.com/contest/weekly-contest-234/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
# contest link: https://leetcode.com/contest/weekly-contest-234/
# time: (?)
# author: reyad


# other_tags: (?)
# difficulty_level: beginner


class Solution:
    def reinitializePermutation(self, n: int) -> int:
        b = [_ for _ in range(n)]
        p = b[:]
        a = b[:]
        cnt = 0
        while True:
            for i in range(n):
                if (i&1) == 0:
                    a[i] = p[(i // 2)]
                else:
                    a[i] = p[(n // 2) + ((i-1) // 2)]
            cnt += 1
            if a == b:
                break
            p = a[:]
        return cnt

```
