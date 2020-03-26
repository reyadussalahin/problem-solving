# problem name: Count the Arrays
# problem link: https://codeforces.com/contest/1312/problem/D
# contest link: https://codeforces.com/contest/1312
# time: (?)
# author: reyad

# other_tags: (?)

# N.B. : This solution should be submitted with python 3.7, it doesn't work with
# previous versions of python because of 'pow' function. Python 3.7 'pow' function
# supports 'modular inverse' by default

n, m = map(int, input().split())
M = 998244353
f = [1]
for i in range(1, m+1):
	f.append((f[-1] * i) % M)
r = (((n-2) * pow(2, n-3, M)) % M) * ((f[m] * pow((f[n-1] * f[m-n+1]) % M, -1, M)) % M)
print(r % M)