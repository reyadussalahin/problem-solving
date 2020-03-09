# problem name: Count Subrectangles
# problem link: https://codeforces.com/contest/1323/problem/B
# contest link: https://codeforces.com/contest/1323
# time: (?)
# author: reyad

# other_tags: greedy, binary search

from math import sqrt

n, m, k = map(int, input().split())
a = map(int, input().split())
b = map(int, input().split())

def make(a):
	d = dict()
	s = 0
	for v in a:
		s += v
		if v == 0 and s != 0:
			if s not in d:
				d[s] = 0
			d[s] += 1
			s = 0
	if s != 0:
		if s not in d:
			d[s] = 0
		d[s] += 1
	return d

def count(i, j, r, c):
	cnt = 0
	for _r, x in r:
		if i > _r:
			break
		for _c, y in c:
			if j > _c:
				break
			cnt += (_r - i + 1) * (_c - j + 1) * x * y
	return cnt

r = sorted(make(a).items(), key=lambda x: -x[0])
c = sorted(make(b).items(), key=lambda x: -x[0])
ans = 0
for i in range(1, int(sqrt(k) + 1e-4) + 1):
	if (k % i) == 0:
		j = k // i
		ans += count(i, j, r, c)
		if i != j:
			ans += count(j, i, r, c)
print(ans)