## Solutions
#### 1
##### Source Code
```python
# problem name: Count Nice Pairs in an Array
# problem link: https://leetcode.com/contest/biweekly-contest-49/problems/count-nice-pairs-in-an-array/
# contest link: https://leetcode.com/contest/biweekly-contest-49/
# time: (?)
# author: reyad


# other_tags: (?)
# difficulty_level: beginner


class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        rnums = [int(str(n)[::-1]) for n in nums]
        cnt = {}
        for n, rn in zip(nums, rnums):
            d = n - rn
            if d not in cnt:
                cnt[d] = 0
            cnt[d] += 1
        ans = 0
        for _, c in cnt.items():
            ans += (c * (c-1)) // 2
        return ans % 1000000007
```
