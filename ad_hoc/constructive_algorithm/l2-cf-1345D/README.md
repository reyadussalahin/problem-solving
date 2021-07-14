## Solutions
#### 1
##### Source Code
```c++
// problem_name: Monopole Magnets
// problem_link: https://codeforces.com/contest/1345/problem/D
// contest_link: https://codeforces.com/contest/1345
// time: (?)
// author: reyad

// other_tags: dfs, dsu
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;

int n, m;
char b[1024][1024];
int p[1024 * 1024];

int find(int i) {
	return (i == p[i]) ? i : (p[i] = find(p[i]));
}

int _hash(int i, int j) {
	return (i * m) + j;
}

int countBlack() {
	int cntBlack = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(b[i][j] == '#') cntBlack++;
		}
	}
	return cntBlack;
}

bool okay() {
	bool rw = false, cw = false;
	for(int i=0; i<n; i++) {
		int cnt = (b[i][0] == '.') ? 0 : 1;
		for(int j=1; j<m; j++) {
			if(b[i][j] == '#' && b[i][j-1] != '#') cnt++;
		}
		if(cnt > 1) return false;
		if(cnt == 0) rw = true;
	}
	for(int j=0; j<m; j++) {
		int cnt = (b[0][j] == '.') ? 0 : 1;
		for(int i=1; i<n; i++) {
			if(b[i][j] == '#' && b[i-1][j] != '#') cnt++;
		}
		if(cnt > 1) return false;
		if(cnt == 0) cw = true;
	}
	return (rw == cw);
}

bool inrange(int i, int j) {
	return (0 <= i && i < n && 0 <= j && j < m);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%s", b[i]);
	}
	if(okay()) {
		if(!countBlack()) {
			printf("0\n");
			return 0;
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				int u = _hash(i, j);
				p[u] = u;
			}
		}
		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1, 0, 0};
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(b[i][j] != '#') {
					continue;
				}
				int u = _hash(i, j);
				for(int k=0; k<4; k++) {
					int ti = i + dx[k];
					int tj = j + dy[k];
					if(!inrange(ti, tj) || b[ti][tj] != '#') {
						continue;
					}
					int v = _hash(ti, tj);
					if(find(u) != find(v)) {
						p[find(u)] = find(v);
					}
				}
			}
		}
		int res = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				int u = _hash(i, j);
				if(b[i][j] == '#' && find(u) == u) res++;
			}
		}
		printf("%d\n", res);
	}
	else {
		printf("-1\n");
	}
	return 0;
}
```
