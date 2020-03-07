# problem name: Unusual Competitions
# problem link: https://codeforces.com/contest/1323/problem/C
# contest link: https://codeforces.com/contest/1323
# author: reyad
# time: (?)

# other_tags: constructive algorithms

n, b, a, r = int(input()), input(), 0, 0
for c in b:
	a += -1 if (c == ")") else 1
	if(a < 0 or (a == 0 and c == "(")):
		r += 1
print(r if (a == 0) else -1)