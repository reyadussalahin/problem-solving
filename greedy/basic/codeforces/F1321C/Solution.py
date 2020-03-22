# problem name: Remove Adjacent
# problem link: https://codeforces.com/contest/1321/problem/C
# contest link: https://codeforces.com/contest/1321
# time: (?)
# author: reyad

# other_tags: constructive algorithm, brute force, string


from sys import stdin
input = stdin.buffer.readline

n, s = int(input()), [_ - ord('a') for _ in input().rstrip()]
for v in range(25, 0, -1):
	u = v - 1
	for x in [_ for _, w in enumerate(s) if w == u]:
		for _ in range(x+1, len(s)):
			if s[_] != v:
				break
			s[_] = -1
		for _ in range(x-1, -1, -1):
			if s[_] != v:
				break
			s[_] = -1
	s = [_ for _ in s if _ != -1]
print(n - len(s))
