# problem name: Ehab and Path-etic MEXs
# problem link: https://codeforces.com/contest/1325/problem/C
# contest link: https://codeforces.com/contest/1325
# time: (?)
# author: reyad

# other_tags: constructive algorithm, tree, dfs and similar


from sys import stdin
from collections import deque
input = stdin.buffer.readline

n = int(input())

d = [0] * (n+1)
g = [[] for _ in range(n+1)]
l = []
for _ in range(1, n):
	u, v = map(int, input().split())
	l.append((u, v))
	g[u].append(v)
	g[v].append(u)
	d[u] += 1
	d[v] += 1

q = deque()
for i in range(1, n+1):
	if d[i] == 1:
		q.append(i)

a = dict()
color = 0
while q:
	u = q.popleft()
	d[u] -= 1
	for v in g[u]:
		if (u, v) not in a:
			a[(u, v)] = a[(v, u)] = color
			color += 1
		d[v] -= 1
		if d[v] == 1:
			q.append(v)

print("\n".join(str(a[_]) for _ in l))
