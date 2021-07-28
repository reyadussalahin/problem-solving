## Solutions
#### 1
##### Source Code
```python
# problem name: Maximize Number of Nice Divisors
# problem link: https://leetcode.com/contest/weekly-contest-234/problems/maximize-number-of-nice-divisors/
# contest link: https://leetcode.com/contest/weekly-contest-234/
# time: (?)
# author: reyad


# other_tags: ternary search
# difficulty_level: beginner


class Solution:
    def maxNiceDivisors(self, primeFactors: int) -> int:
        # solution idea:
        # assume, n is primeFactors here(for writing convenience)
        # we just have to split primeFactors i.e. n into small euqal pieces to get the maximum product value
        # which euqals the number of nice divisors
        # let's break n into x such that (n/x)*x = n and x ^ (n/x) is maximum
        # now, if x^(n/x) is maximum, then it's derivative must be 0
        # we know that, d/dx x^(1/x) = x^(1/x) * (1/x^2) * (1-lnx)
        # so, x^(1/x) * (1/x^2) * (1-ln(x)) = 0
        # therefore, one of the term must be 0
        # here, the only potentilal candidate is (1-ln(x))
        # so, 1-ln(x) = 0
        # therefore, x = e[here, `e` from natural logarithm]
        # as, e's value is 2.718...
        # so, x must either 2 and 3
        # in this case, x must be 3 whenever possible except n <= 4
        # when, n <= 4, just take the value of n
        
        # this problem can also be solved using `ternary search`
        
        
        M = 1000000007
        n = primeFactors
        if n <= 4:
            return n
        n = n - 4
        q = n // 3
        ans = pow(3, q, M)
        r = n - (3 * q) + 4
        while r > 4:
            ans = (ans * 3) % M
            r -= 3
        return (ans * (1 if r == 0 else r)) % M

```
