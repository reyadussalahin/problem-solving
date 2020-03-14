# problem name: Frog Jumps
# problem link: https://codeforces.com/contest/1324/problem/C
# contest link: https://codeforces.com/contest/1324
# time: (?)
# author: reyad

# other_tags: greedy, binary search, data structures

for _ in range(int(input())):
	a = p = -1
	for i, c in enumerate(input().rstrip() + 'R'):
		if c == 'R':
			a = max(a, i-p)
			p = i
	print(a)