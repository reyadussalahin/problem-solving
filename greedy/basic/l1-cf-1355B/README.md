## Solutions
#### 1
##### Source Code
```c++
// problem name: Young Explorers
// problem link: https://codeforces.com/contest/1355/problem/B
// contest link: https://codeforces.com/contest/1355
// time: (?)
// author: reyad

// other_tags: sortings, dp
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;

#define N 200020

int c[N] = {0};

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d", &n);
		set<int> unq;
		for(int i=0; i<n; i++) {
			int e;
			scanf("%d", &e);
			c[e]++;
			unq.insert(e);
		}
		int rem = 0, g = 0;
		for(int e: unq) {
			int x = c[e] / e;
			g += x;
			rem += c[e] - x * e;
			if(rem >= e) {
				int y = rem / e;
				g += y;
				rem -= y * e;
			}
			c[e] = 0; // resetting
		}
		printf("%d\n", g);
	}
	return 0;
}
```
