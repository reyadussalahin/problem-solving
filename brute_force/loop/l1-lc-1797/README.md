## Solutions
#### 1
##### Source Code
```python
# problem name: Design Authentication Manager
# problem link: https://leetcode.com/contest/biweekly-contest-48/problems/design-authentication-manager/
# contest link: https://leetcode.com/contest/biweekly-contest-48/
# time: (?)
# author: reyad


# other_tags: ad hoc
# difficulty_level: beginner


class AuthenticationManager:

    def __init__(self, timeToLive: int):
        self.buf = dict()
        self.ttl = timeToLive

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.buf[tokenId] = currentTime + self.ttl

    def renew(self, tokenId: str, currentTime: int) -> None:
        if tokenId in self.buf and self.buf[tokenId] > currentTime:
            self.buf[tokenId] = currentTime + self.ttl

    def countUnexpiredTokens(self, currentTime: int) -> int:
        cnt = 0
        for tokenId, finishTime in self.buf.items():
            if finishTime > currentTime:
                cnt += 1
        return cnt

# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)

```
