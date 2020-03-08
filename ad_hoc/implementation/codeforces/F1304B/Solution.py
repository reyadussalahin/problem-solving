# problem name: Longest Palindrome
# problem link: https://codeforces.com/contest/1304/problem/B
# contest link: https://codeforces.com/contest/1304
# time: (?)
# author: reyad

# other_tags: brute force, constructive algorithms, greedy


n, m = map(int, input().split())
b = [input().rstrip() for _ in range(n)]
c = set(b)
l, r = [], []
x = ""
for p in b:
	q = p[::-1]
	if p in c:
		if p == q:
			if len(p) > len(x):
				x = p
		elif q in c:
			l.append(p)
			r.append(q)
			c.remove(q)
		c.remove(p)

a = "".join(l) + x + "".join(reversed(r))
print(len(a))
print(a)