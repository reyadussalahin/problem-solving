# problem name: Primitive Primes
# problem link: https://codeforces.com/contest/1316/problem/C
# contest link: https://codeforces.com/contest/1316
# time: (?)
# author: reyad

# other_tags: constructive algorithms, ternary search


from sys import stdin
input = stdin.buffer.readline
r = lambda: map(int, input().split())

def f(_):
	for i, v in enumerate(_):
		if (v % p) != 0:
			return i;
	return -1

_, _, p = r()
print(f(r()) + f(r()))