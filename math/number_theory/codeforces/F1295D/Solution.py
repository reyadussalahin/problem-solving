# problem name: Same GCDs
# problem link: https://codeforces.com/contest/1295/problem/D
# contest link: https://codeforces.com/contest/1295
# author: reyad
# time: (?)

# other_tags: (?)


def gcd(a, b):
	while(b != 0):
		c = a % b
		a = b
		b = c
	return a

def totient(n):
	i = 2
	ret = n
	while i * i <= n:
		if (n % i) == 0:
			while (n % i) == 0:
				n //= i
			ret = ret * (i - 1) // i
		i += 1
	if n > 1:
		ret = ret * (n - 1) // n
	return ret

tc = int(input())
for _ in range(tc):
	a, m = map(int, input().split())
	d = gcd(a, m)
	v = m // d
	ans = totient(v)
	print(ans)