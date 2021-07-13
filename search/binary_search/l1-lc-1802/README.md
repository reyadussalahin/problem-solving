## Solutions
```python
# problem name: Maximum Value at a Given Index in a Bounded Array
# problem link: https://leetcode.com/contest/weekly-contest-233/problems/maximum-value-at-a-given-index-in-a-bounded-array/
# contest link: https://leetcode.com/contest/weekly-contest-233/
# time: (?)
# author: reyad


# other_tags: (?)
# difficulty_level: beginner



class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        ans = 1
        s = 0
        e = int(1e9)
        while s <= e:
            m = (s + e) // 2 # here, `m` represents max possible height candidate
            # now, check if m satisfies given array constructing constraints
            l = min(index+1, m)
            r = min(n-index, m)
            # print(f"m: {m}, l:{l}, r:{r}")
            tot = (l * (l+1) + r * (r+1)) // 2
            tot += (index+1-l) if l == m else (index+1) * (m-l)
            tot += (n-index-r) if r == m else (n-index) * (m-r)
            tot -= m
            # print(f"tot: {tot}")
            if tot <= maxSum:
                ans = m
                s = m + 1
            else:
                e = m - 1
        return ans

```
