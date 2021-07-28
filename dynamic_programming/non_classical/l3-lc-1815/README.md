## Solutions
#### 1
##### Source Code
```python
# problem name: Maximum Number of Groups Getting Fresh Donuts
# problem link: https://leetcode.com/contest/biweekly-contest-49/problems/maximum-number-of-groups-getting-fresh-donuts/
# contest link: https://leetcode.com/contest/biweekly-contest-49/
# time: (?)
# author: reyad


# other_tags: (?)
# difficulty_level: expert


# Note: this problem can be more optimized by applying greedy technique by finding the numbers directly divisible by batchSize and also finding out the pairs which sum is divisible by batchSize. But 3 or more elements sum divisible by batchSize, for that we must apply dp technique. But by removing the 1 and 2 elements sum divisible by batchSize, we can significantly improve performance. But, keep in mind, the overall complexity in O notation does not improve. It's just the parameter get's a little bit smaller by constant factor.


class Solution:
    def maxHappyGroups(self, batchSize, groups):
        def calc(state, dp):
            if sum(state) == 0:
                return (0, 0)
            h = hash(tuple(state))
            if h in dp:
                return dp[h]
            dp[h] = (-1, 0)
            for i in range(batchSize):
                if state[i] <= 0:
                    continue
                tstate = state[:]
                tstate[i] -= 1
                tzcnt, trest = calc(tstate, dp)
                new_rest = (trest + i) % batchSize
                if new_rest == 0:
                    tzcnt += 1
                if tzcnt > dp[h][0]:
                    dp[h] = (tzcnt, new_rest)
            # print(state, ":", dp[h])
            return dp[h]
        arr = [(x % batchSize) for x in groups]
        # print(arr)
        state = [0] * batchSize
        for v in arr:
            state[v] += 1
        zcnt, rest = calc(state, {})
        return zcnt + (1 if rest > 0 else 0)

```
