## Solutions
#### 1
##### Source Code
```c++
// problem name: Constructing the Array
// problem link: https://codeforces.com/contest/1353/problem/D
// contest link: https://codeforces.com/contest/1353
// time: (?)
// author: reyad

// other_tags: constructive algorithm, sortings
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

#define N 200010

struct Range {
	int l, r;
	Range() {}
	Range(int l_, int r_) {
		l = l_;
		r = r_;
	}
	bool operator<(const Range &v) const {
		// cpp by default max priority queue
		if((r - l) == (v.r - v.l)) {
			return l > v.l; // max priority queue..so, reversing operation
		}
		return (r - l) < (v.r - v.l); // reversing operation..max priority queue
	}
};

int a[N];

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d", &n);
		priority_queue<Range> pq;
		pq.push(Range(1, n));
		int action = 1;
		while(!pq.empty()) {
			Range u = pq.top();
			pq.pop();
			int m = (u.l + u.r) / 2;
			a[m] = action++;
			if(u.l < m) pq.push(Range(u.l, m-1));
			if(u.r > m) pq.push(Range(m+1, u.r));
		}
		for(int i=1; i<=n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}
```
