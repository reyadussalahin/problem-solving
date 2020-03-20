# problem name: Ehab the Xorcist
# problem link: https://codeforces.com/contest/1325/problem/D
# contest link: https://codeforces.com/contest/1325
# time: (?)
# author: reyad

# other_tags: bitmasks, implementation, greedy, number theory


from sys import stdin
input = stdin.buffer.readline

u, v = map(int, input().split())
if u > v or ((u&1) != (v&1)):
	print(-1)
elif u == v:
	print('1\n{}'.format(u) if u else '0')
else:
	z = (v - u) // 2
	print('3\n{} {} {}'.format(u, z, z) if (u&z) != 0 else '2\n{} {}'.format(u+z, z))
