// problem name: Timofey and a tree
// problem link: https://codeforces.com/contest/764/problem/C
// contest link: https://codeforces.com/contest/764
// author: reyad
// time: (?)


#include <bits/stdc++.h>

using namespace std;


vector<int> adj[100010];
int color[100010], instck[100010] = {0}, stck[100010];

void dfs(int u, int oldColor, int newColor) {
	color[u] = newColor;
	for(int v: adj[u]) {
		if(color[v] == oldColor) {
			dfs(v, oldColor, newColor);
		}
	}
}

int main() {
	int n, u, v;

	scanf("%d", &n);
	for(int i=1; i<n; i++) {
		scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}

	for(int i=0; i<n; i++) {
		scanf("%d", &color[i]);
	}

	int colorCnt = 0;
	for(int i=0; i<n; i++) {
		if(color[i] > 0) {
			dfs(i, color[i], colorCnt);
			colorCnt--;
		}
	}

	// printf("colorCnt: %d\n", colorCnt);

	int top = 0, ans = -1;
	for(int i=0; i<n; i++) {
		stck[top++] = -color[i];
		instck[-color[i]] = 1;
		for(int v: adj[i]) {
			if(!instck[-color[v]]) {
				stck[top++] = -color[v];
				instck[-color[v]] = 1;
			}
		}
		// printf("top: %d\n", top);
		if(top == -colorCnt) {
			ans = i + 1;
			break;
		}
		while(top > 0) instck[stck[--top]] = 0;
	}
	
	if(ans == -1) printf("NO\n");
	else printf("YES\n%d\n", ans);

	return 0;
}
