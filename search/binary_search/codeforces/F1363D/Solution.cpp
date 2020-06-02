// problem name: Guess The Maximums
// problem link: https://codeforces.com/contest/1363/problem/D
// contest link: https://codeforces.com/contest/1363
// time: (?)
// author: reyad

// other_tags: implementation, interactive, math
// difficulty_level:

// note: this is a interactive problem. read problem description well, don't assume anything.


#include <bits/stdc++.h>

using namespace std;

char status[32];

int query(vector<int> &buf, bool ispw = false) {
	if(ispw) {
		printf("!");
	}
	else {
		printf("? %d", buf.size());
	}
	for(auto v: buf) {
		printf(" %d", v);
	}
	printf("\n");
	fflush(stdout);

	if(ispw) {
		scanf("%s", status);
		return 0;
	}
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, k;
		scanf("%d %d", &n, &k);
		vector<vector<int>> subset(k);
		for(auto &it: subset) {
			int c;
			scanf("%d", &c);
			it.resize(c);
			for(auto &v: it) {
				scanf("%d", &v);
			}
		}
		vector<int> q;
		for(int i=1; i<=n; i++) {
			q.push_back(i);
		}
		int mx = query(q);
		int s = 0, e = k-1;
		while(s < e) {
			vector<int> q;
			int m = (s + e) / 2;
			for(int i=s; i<=m; i++) {
				for(auto v: subset[i]) {
					q.push_back(v);
				}
			}
			int x = ((q.size() > 0) ? query(q) : 0);
			if(x < mx) {
				s = m + 1;
			} else {
				e = m;
			}
		}
		set<int> mxSet(subset[s].begin(), subset[s].end());
		vector<int> qq;
		for(int i=1; i<=n; i++) {
			if(!mxSet.count(i)) {
				qq.push_back(i);
			}
		}
		int y = ((qq.size() > 0) ? query(qq) : 0);
		vector<int> p;
		for(int i=0; i<k; i++) {
			if(i != s) {
				p.push_back(mx);
			} else {
				p.push_back(y);
			}
		}
		query(p, true);
	}
	return 0;
}