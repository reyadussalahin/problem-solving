## Solutions
```c++
// problem name: Orac and Game of Life
// problem link: https://codeforces.com/contest/1350/problem/E
// contest link: https://codeforces.com/contest/1350
// time: (?)
// author: reyad

// other_tags: data structures, implementations, math
// difficulty_level: medium


// observation or solution hints:
// (i)   once a cell starts flipping color, after that it'll never stop
// (ii)  so, try to find out when a cell will start flipping
// (iii) according to definiton: two consecutive cell with same color starts the flipping at iteration 1
// (iv)  flipping cells will make the non-flipping start flipping
// (v)   so find out, what is the least possible time a cell may start flipping

#include <bits/stdc++.h>

using namespace std;

#define N 1004

int n;
int m;
int t;
char color[N][N];
int lev[N][N] = {0};
int qx[N * N];
int qy[N * N];
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};

bool inrange(int x, int y) {
	return (0 <= x && x <= n-1 && 0 <= y && y <= m-1);
}

int main() {
	scanf("%d %d %d", &n, &m, &t);
	for(int i=0; i<n; i++) {
		scanf("%s", color[i]);
	}
	int s = 0, e = 0;
	for(int x=0; x<n; x++) {
		for(int y=0; y<m; y++) {
			for(int k=0; k<4; k++) {
				int tx = x + dx[k];
				int ty = y + dy[k];
				if(!inrange(tx, ty)) continue;
				if(color[x][y] == color[tx][ty]) {
					lev[x][y] = 1;
					qx[e] = x;
					qy[e++] = y;
					break;
				}
			}
		}
	}
	while(s != e) {
		int ux = qx[s];
		int uy = qy[s++];
		for(int k=0; k<4; k++) {
			int vx = ux + dx[k];
			int vy = uy + dy[k];
			if(!inrange(vx, vy) || lev[vx][vy]) continue;
			lev[vx][vy] = lev[ux][uy] + 1;
			qx[e] = vx;
			qy[e++] = vy;
		}
	}
	for(int tt=0; tt<t; tt++) {
		int x, y;
		long long p;
		scanf("%d %d %lld", &x, &y, &p);
		--x;
		--y;
		if(!lev[x][y] || p < lev[x][y]) {
			printf("%c\n", color[x][y]);
		} else {
			if((p - lev[x][y]) & 1) {
				printf("%c\n", color[x][y]);
			} else {
				printf("%c\n", ((color[x][y] == '1') ? '0' : '1'));
			}
		}
	}
	return 0;
}
```
