## Solutions
#### 1
##### Source Code
```python
# problem name: Evaluate the Bracket Pairs of a String
# problem link: https://leetcode.com/contest/weekly-contest-234/problems/evaluate-the-bracket-pairs-of-a-string/
# contest link: https://leetcode.com/contest/weekly-contest-234/
# time: (?)
# author: reyad


# other_tags: string
# difficulty_level: beginner


class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        kd = {k:v for k, v in knowledge}
        new_s = []
        seen_b = False
        for ch in s:
            if seen_b:
                if ch == ")":
                    kw = "".join(kw)
                    w = kd[kw] if kw in kd else "?"
                    new_s.append(w)
                    seen_b = False
                else:
                    kw.append(ch)
            else:
                if ch == "(":
                    seen_b = True
                    kw = []
                else:
                    new_s.append(ch)
        return "".join(new_s)

```
