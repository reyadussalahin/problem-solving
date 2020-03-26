# problem name: Count The Blocks
# problem link: https://codeforces.com/contest/1327/problem/E
# contest link: https://codeforces.com/contest/1327
# time: (?)
# author: reyad

# other_tags: dynamic programming

n = int(input())
M = 998244353
b = []
for p in range(1, n+1):
	m = n - p
	c = ((2 * 9 * pow(10, m-1, M)) + (((m-1) * 9 * 9 * pow(10, m-2, M)) % M) if m else 1)
	b.append(c % M)
print(" ".join([str((10 * _) % M) for _ in b]))