// problem name: Misha and Forest
// problem link: https://codeforces.com/contest/501/problem/C
// contest link: https://codeforces.com/contest/501
// author: reyad
// time: (?)

// other_tags: data structure, greedy, sortings, constructive algorithms

// there is another way to do the solution using a greedy approach


#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100010];
int d[100010], s[100010], q[100010], p[100010];

int main() {
	int n;

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		p[i] = -1;
		scanf("%d %d", &d[i], &s[i]);
	}

	int m = 0, qs = 0, qe = 0;
	for(int i=0; i<n; i++) {
		if(d[i] == 1) {
			q[qe++] = i;
		}
	}

	while(qs != qe) {
		int x = q[qs++];
		if(d[x] == 0) continue;
		
		int y = s[x];
		s[y] ^= x;
		d[y]--;
		
		// if((x != y) && p[min(x, y)] != max(x, y)) {
		// 	p[min(x, y)] = max(x, y);
		// 	adj[x].push_back(y);
		// 	m++;
		// }

		adj[x].push_back(y);
		m++;

		if(d[y] == 1) {
			q[qe++] = y;
		}
	}

	printf("%d\n", m);
	for(int i=0; i<n; i++) {
		for(int j: adj[i]) {
			printf("%d %d\n", i, j);
		}
	}

	return 0;
}