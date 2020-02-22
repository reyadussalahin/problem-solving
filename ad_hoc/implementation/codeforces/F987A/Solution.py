'''
Problem Name: Infinity Gauntlet
Problem Link: https://codeforces.com/problemset/problem/987/A
Author: Ratul

'''

i = int(input())

gemtype = {
	"purple" : "Power",
	"green" : "Time",
	"blue" : "Space",
	"orange" : "Soul",
	"red" : "Reality",
	"yellow" : "Mind"
}

stones = set(gemtype.values())
seen = set()

for _ in range(i):
	seen.add(gemtype[input()]);

ans = list(stones - seen)

print(len(ans), *ans, sep='\n')
