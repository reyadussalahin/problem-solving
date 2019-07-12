# Problem Description

### Problem: [Archer](https://codeforces.com/problemset/problem/312/B)
### Contest: [Codeforces Round #185 (Div. 2)](https://codeforces.com/contest/312)
### Statement
SmallR is an archer. SmallR is taking a match of archer with Zanoes. They try to shoot in the target in turns, and SmallR shoots first. The probability of shooting the target each time is (a / b) for SmallR while (c / d) for Zanoes. The one who shoots in the target first should be the winner.  
Output the probability that SmallR will win the match.
#### Constraints
```
1 <= a, b, c, d <= 1000
0 < (a / b) < 1
0 < (c / d) < 1
```
#### Input
A single line contains four integers a, b, c, d
#### Output
Print a single real number, the probability that SmallR will win the match.  
The answer will be considered correct if the absolute or relative error doesn't exceed 10^-6.

# Solution
```
let p = a / b; // probability that SmallR wins in the first round  
let q = c / d; // probability that Zanoes wins in the first round  
```
Let's say SmallR hit the target in the first round, then  
probabilty of win in the first round is (a/b) i.e. simply p(as p = (a/b))  

Now let's say SmallR was not successful in the first round, then two cases arise
1. Zanoes will hit the target and win
2. Zanoes will miss the target and SmallR would again have some chance to shoot  
In the second case, SmallR's probalility of win will be
(probability that SmallR loses in the first round * probability that Zanoes loses in the first round * probability that SmallR wins in the second round)  
And it is ((1 - (a/b)) * (1 - (c/d)) * (a/b))  
Or simply ((1-p) * (1-q) * p)  

This process will go on for third round  
And the probability of win in the third round is ((1-p) * (1-q) * (1-p) * (1-q) * p) i.e. simply ((1-p)^2 * (1-q)^2 * p)  

For fourth round, it'll be ((1-p)^3 * (1-q)^3 * p) and this will go on for infinity.  

And by adding those probabilities of each round, we'll be able to found the answer i.e. the probability that SmallR will win.  

```
So, ans = p + ((1-p) * (1-q) * p) + ((1-p)^2 * (1-q)^2 * p) + ...
Let us consider, (1-p) * (1-q) = r
Then, ans = p + (r * p) + (r^2 * p) + (r^3 * p) + ...
as 0 < p < 1 and 0 < q < 1, then 0 < r < 1
So, ans = p / (1 - r) (by applying formula of geometric progression)
```

