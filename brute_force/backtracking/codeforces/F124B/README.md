# Problem Description
### Problem: [Permutations](https://codeforces.com/contest/124/problem/B)

### Contest: [Codeforces Beta Round #92 (Div. 2 Only)](https://codeforces.com/contest/124)

### Statement
You are given n k-digit integers. You have to rearrange the digits in the integers so that the difference between the largest and the smallest number was minimum. Digits should be rearranged by the same rule in all integers.

<!-- #### Constraints
```
1 <= a, b, c, d <= 1000
``` -->

#### Input
The first line contains integers n and k — the number and digit capacity of numbers correspondingly (1 ≤ n, k ≤ 8). Next n lines contain k-digit positive integers. Leading zeroes are allowed both in the initial integers and the integers resulting from the rearranging of digits.

#### Output
Print a single number: the minimally possible difference between the largest and the smallest number after the digits are rearranged in all integers by the same rule.

# Solution
The solution is pretty easy. First, let min_diff = infinite. As there are k digits, there could be at most k! different patterns for rearranging digits. So, we generate all the patterns. And for each pattern, iterate through all the n numbers, rearrange them and find the max number and min number. And then find the difference between those two. If it's lesser, we update the min_diff.  
The complexity of this solution is O(nk\*k!)
