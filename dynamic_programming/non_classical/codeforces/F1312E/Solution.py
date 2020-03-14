# problem name: Array Shrinking
# problem link: https://codeforces.com/contest/1312/problem/E
# contest link: https://codeforces.com/contest/1312
# time: (?)
# author: reyad

# other_tags: greedy

# this solution style is a bit different for this problem than most of the cf solutions
# so i'm providing a tutorial link to the solution
# tutorial link: https://codeforces.com/blog/entry/74759


n = int(input())
b = [int(_) for _ in input().split()]
e = [[-1] * (n+1) for _ in range(2002)]

d = [[] for _ in range(n)]
for i, v in enumerate(b):
	e[v][i] = i
	d[i].append(i)

for v in range(1, 2002):
	for i in range(n):
		j = e[v][i]
		h = e[v][j+1] if j != -1 else -1
		if j != -1 and h != -1:
			e[v+1][i] = h
			d[i].append(h)

a = [_ for _ in range(1, n+1)]
for s in range(n):
	for e in d[s]:
		a[e] = min(a[e], a[s-1]+1 if s > 0 else 1)
print(a[n-1])
