// problem name: Minimax Problem
// problem link: https://codeforces.com/contest/1288/problem/D
// contest link: https://codeforces.com/contest/1288
// author: reyad
// time: (?)

// other_tags: binary search, bitmask


#include <bits/stdc++.h>

using namespace std;

int a[300030][10];


int main() {
	int n, m;
	int b[1024];

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int s = 0, e = (int)1e9;
	int ai = -1, aj = -1;
	while(s <= e) {
		int maxPossible = 1 << m;
		for(int i=0; i<maxPossible; i++) b[i] = 0;

		int bk = (s + e) / 2;
		for(int i=0; i<n; i++) {
			int bit = 0;
			for(int j=0; j<m; j++) {
				if(a[i][j] >= bk) bit = bit | (1<<j);
			}
			if(!b[bit]) b[bit] = i + 1;
		}

		bool flag = false;
		for(int i=0; i<maxPossible; i++) {
			if(b[i]) {
				for(int j=i; j<maxPossible; j++) {
					if(b[j] && ((i | j) == (maxPossible - 1))) {
						ai = b[i];
						aj = b[j];
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
		}

		if(flag) {
			s = bk + 1;
		}
		else {
			e = bk - 1;
		}
	}

	printf("%d %d\n", ai, aj);
	return 0;
}