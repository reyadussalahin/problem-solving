## Solutions
#### 1
##### Source Code
```python
# problem name: Finding the Users Active Minutes
# problem link: https://leetcode.com/contest/weekly-contest-235/problems/finding-the-users-active-minutes/
# contest link: https://leetcode.com/contest/weekly-contest-235/
# time: (?)
# author: reyad


# other_tags: sorting
# difficulty_level: beginner


class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        uam_set = {}
        for uid, time in logs:
            if uid not in uam_set:
                uam_set[uid] = set()
            uam_set[uid].add(time)
        ans = [0] * (k+1)
        for uid, uams in uam_set.items():
            # print(uid, ":", len(uams))
            ans[len(uams)] += 1
        return ans[1:]

```
