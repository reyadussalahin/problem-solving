# problem name: Pair of Topics
# problem link: https://codeforces.com/contest/1324/problem/D
# contest link: https://codeforces.com/contest/1324
# time: (?)
# author: reyad

# other_tags: sortings, two pointers, data structures

# note: this problem can be solved in various ways, so there are so many tags


from bisect import bisect_left

n = int(input())
a = [int(_) for _ in input().split()]
b = [int(_) for _ in input().split()]

u = sorted([i-j for i, j in zip(a, b)])
v = sorted([i-j for i, j in zip(b, a)])

a = 0
for x in u:
	a += bisect_left(v, x) - (1 if x > 0 else 0)

print(a//2)