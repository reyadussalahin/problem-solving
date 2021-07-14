## Solutions
#### 1
##### Source Code
```python
# problem name: Minimum Absolute Sum Difference
# problem link: https://leetcode.com/contest/weekly-contest-235/problems/minimum-absolute-sum-difference/
# contest link: https://leetcode.com/contest/weekly-contest-235/
# time: (?)
# author: reyad


# other_tags: sorting
# difficulty_level: beginner


class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        d = [abs(nums1[i] - nums2[i]) for i in range(0, len(nums1))]
        x = []
        for i, v in enumerate(d):
            if len(x) == 0:
                x.append(i)
            else:
                if v == d[x[0]]:
                    x.append(i)
                elif v > d[x[0]]:
                    x = [i]
        sel = d[x[0]]
        b = sorted(nums1)
        for y in x:
            s = 0
            e = len(nums1)-1
            p = -1
            while s <= e:
                m = (s + e) // 2
                if b[m] < nums2[y]:
                    p = m
                    s = m + 1
                else:
                    e = m - 1
            if p < len(b)-1 and abs(b[p+1]-nums2[y]) < abs(b[p]-nums2[y]):
                p += 1
            sel = min(sel, abs(b[p]-nums2[y]))
        ans = sum(d) - d[x[0]] + sel
        return ans % 1000000007
    
```
