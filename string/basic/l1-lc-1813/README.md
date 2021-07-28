## Solutions
#### 1
##### Source Code
```python
# problem name: Sentence Similarity III
# problem link: https://leetcode.com/contest/biweekly-contest-49/problems/sentence-similarity-iii/
# contest link: https://leetcode.com/contest/biweekly-contest-49/
# time: (?)
# author: reyad


# other_tags: (?)
# difficulty_level: beginner


class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split()
        s2 = sentence2.split()
        while len(s1) > 0 and len(s2) > 0 and s1[-1] == s2[-1]:
            s1.pop()
            s2.pop()
        s1 = [_ for _ in reversed(s1)]
        s2 = [_ for _ in reversed(s2)]
        while len(s1) > 0 and len(s2) > 0 and s1[-1] == s2[-1]:
            s1.pop()
            s2.pop()
        return len(s1) == 0 or len(s2) == 0
```
