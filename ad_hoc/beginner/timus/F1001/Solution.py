# problem name: Reverse Root
# problem link: https://acm.timus.ru/problem.aspx?space=1&num=1001
# contest link: (?)
# time: (?)
# author: reyad

# other tags: (?)


# difficulty level: beginner
import sys
from math import sqrt
a = []
for line in sys.stdin:
	a += [int(_) for _ in line.split()]
for _ in a[::-1]:
	print(sqrt(_))