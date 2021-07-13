## Solutions
```python
# problem name: Truncate Sentence
# problem link: https://leetcode.com/contest/weekly-contest-235/problems/truncate-sentence/
# contest link: https://leetcode.com/contest/weekly-contest-235/
# time: (?)
# author: reyad


# other_tags: two pointers
# difficulty_level: beginner


class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        return " ".join(s.split()[:k])

```
