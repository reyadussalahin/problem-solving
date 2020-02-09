// problem name: Berland Beauty
// problem link: https://codeforces.com/contest/1296/problem/F
// contest link: https://codeforces.com/contest/1296
// author: reyad
// time: (?)

// other_tags: constructive algorithms, greedy, dfs

// note: this problem has also other kind of solutions.
// even this solution can be written in a more efficient
// manner.


#include <bits/stdc++.h>

using namespace std;

vector<int> adj[5010];
int a[5010][5010];
int b[5010][5010];
int c[5010] = {0};
int cc[5010];
int q[5010];
int p[5010] = {0};
int seen[5010] = {0};


int main() {
	int n, u, v, aa, bb;
	
	scanf("%d", &n);
	for(int i=1; i<n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		b[u][v] = b[v][u] = i;
	}

	int m;
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &aa, &bb, &cc[i]);

		int s = 0, e = 0;
		q[e++] = aa;
		seen[aa] = 1;
		p[aa] = 0;
		
		int flag = 0;
		while(s != e) {
			int u = q[s++];

			for(int v: adj[u]) {
				if(seen[v]) continue;
				seen[v] = 1;
				p[v] = u;
				q[e++] = v;
				if(v == bb) {
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}

		int u = bb;
		while(p[u]) {
			int k = b[u][p[u]];
			if(c[k]) {
				if(cc[i] > cc[a[k][0]]) {
					a[k][0] = i;
					c[k] = 1;
				}
				else if(cc[i] == cc[a[k][0]]) {
					a[k][c[k]++] = i;
				}
			}
			else a[k][c[k]++] = i;
			u = p[u];
		}

		for(int j=0; j<e; j++) {
			p[q[j]] = seen[q[j]] = 0;
		}
	}

	int cnt = 0;
	for(int i=1; i<n; i++) {
		for(int j=0; j < c[i]; j++) {
			if(!seen[a[i][j]]) {
				cnt++;
				seen[a[i][j]] = 1;
			}
		}
	}

	if(cnt == m) {
		for(int i=1; i<n; i++) {
			printf("%d ", ((cc[a[i][0]]) ? cc[a[i][0]] : 1000000));
		}
		printf("\n");
	}
	else {
		printf("-1\n");
	}

	return 0;
}