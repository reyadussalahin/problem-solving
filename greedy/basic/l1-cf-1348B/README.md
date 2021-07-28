## Solutions
#### 1
##### Source Code
```c++
// problem_name: Phoenix and Beauty
// problem_link: https://codeforces.com/contest/1348/problem/B
// contest_link: https://codeforces.com/contest/1348
// time: (?)
// author: reyad

// other_tags: constructive algorithm, data structures, sorting
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;


int main() {
	int tc, b[128], p[128];

	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, k;
		scanf("%d %d", &n, &k);
		
		set<int> s;
		for(int i=0; i<n; i++) {
			scanf("%d", &b[i]);
			s.insert(b[i]);
		}

		if((int)s.size() > k) {
			printf("-1\n");
			continue;
		}
		
		int h = 0;
		for(int it: s) {
			p[h++] = it;
		}
		while(h < k) p[h++] = 1;
		printf("%d ", n * k);
		for(int i=0; i<n; i++) {
			for(int j=0; j<k; j++) {
				printf("%d ", p[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

```
