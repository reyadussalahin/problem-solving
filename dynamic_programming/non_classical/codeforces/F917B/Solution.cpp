// problem name: MADMAX
// problem link: https://codeforces.com/contest/917/problem/B
// contest link: https://codeforces.com/contest/917
// author: reyad
// time: (?)

// other_tags: graph, dfs, games


#include <bits/stdc++.h>

using namespace std;

vector<int> g[128], w[128];
int dp[128][128][32];

int dfs(int i, int j, int k) {
	if(dp[i][j][k] != -1) return dp[i][j][k];

	int l1 = (int)g[i].size(), l2 = (int)g[j].size();
	for(int x=0; x<l1; x++) {
		if(w[i][x] >= k) {
			dp[i][j][k] = 1;
			for(int y=0; y<l2; y++) {
				if(w[j][y] >= w[i][x]) {
					if(!(dp[i][j][k] = dfs(g[i][x], g[j][y], w[j][y]))) break;
				}
			}
		}
		if(dp[i][j][k] == 1) break;
	}
	return (dp[i][j][k] != -1) ? dp[i][j][k] : (dp[i][j][k] = 0);
}

int main() {
	int n, m, u, v;
	char ch;

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%d %d %c", &u, &v, &ch);
		g[u-1].push_back(v-1);
		w[u-1].push_back((int)(ch - 'a' + 1));
	}

	for(int i=0; i<128; i++) {
		for(int j=0; j<128; j++) {
			for(int k=0; k<32; k++) {
				dp[i][j][k] = -1;
			}
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			dfs(i, j, 0);
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(dp[i][j][0]) printf("A");
			else printf("B");
		}
		printf("\n");
	}
	return 0;
}
