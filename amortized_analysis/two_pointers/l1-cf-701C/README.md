## Solutions
```c++
// problem name: They Are Everywhere
// problem link: https://codeforces.com/contest/701/problem/C
// contest link: https://codeforces.com/contest/701
// time: (?)
// author: reyad

// other_tags: binary search, string
// difficulty_level: beginner

#include <bits/stdc++.h>

using namespace std;

#define N 100010

int c[128] = {0};
char s[N];
char u[128];
int k = 0;


set<char> unq;

int okay() {
	for(int i=0; i<k; i++) {
		if(!c[u[i]]) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	scanf("%d %s", &n, s);
	for(int i=0; i<n; i++) {
		unq.insert(s[i]);
	}
	for(char it: unq) {
		u[k++] = it;
	}
	int i = 0, j = 0, d = 987654321;
	while(i < n) {
		if(!okay()) {
			c[s[i]]++;
			i++;
		} else {
			// printf("i, j: %d %d\n", i, j);
			d = min(d, (i-1)-j+1);
			c[s[j]]--;
			j++;
		}
	}
	while(j < n && okay()) {
		d = min(d, (n-1)-j+1);
		c[s[j]]--;
		j++;
	}
	printf("%d\n", d);
	return 0;
}
```
