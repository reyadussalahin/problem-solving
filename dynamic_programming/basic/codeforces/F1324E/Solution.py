# problem name: Sleeping Schedule
# problem link: https://codeforces.com/contest/1324/problem/E
# contest link: https://codeforces.com/contest/1324
# time: (?)
# author: reyad

# other_tags: implementation


n, h, l, r = map(int, input().split())
a = [int(_) for _ in input().split()]

d = [[-2024] * h for _ in range(n)]

d[0][a[0]] = (1 if l <= a[0] and a[0] <= r else 0)
d[0][a[0] - 1] = (1 if l <= a[0]-1 and a[0]-1 <= r else 0)
for i in range(1, n):
	x = a[i]
	for v in range(h):
		d[i][v] = max(d[i-1][v-x], d[i-1][v-x+1]) + (1 if l <= v and v <= r else 0)

print(max(d[-1]))