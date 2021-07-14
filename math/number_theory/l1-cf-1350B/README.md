## Solutions
#### 1
##### Source Code
```c++
// problem name: Orac and Models
// problem link: https://codeforces.com/contest/1350/problem/B
// contest link: https://codeforces.com/contest/1350
// time: (?)
// author: reyad

// other_tags: dp
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

#define N 100000

vector<int> dv[N+10];
int b[N+10], r[N+10];

int main() {
	for(int i=1; i<=N; i++) {
		for(int j=i+i; j<=N; j+=i) {
			dv[j].push_back(i);
		}
	}

	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &b[i]);
			r[i] = 1;
		}
		for(int i=n; i>=1; i--) {
			for(int d: dv[i]) {
				if(b[i] > b[d]) {
					r[d] = max(r[d], r[i] + 1);
				}
			}
		}
		int mx = 0;
		for(int i=1; i<=n; i++) {
			mx = max(mx, r[i]);
		}
		printf("%d\n", mx);
	}
	return 0;
}
```
