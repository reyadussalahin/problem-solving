## Solutions
#### 1
##### Source Code
```c++
// problem name: Johnny and Contribution
// problem link: https://codeforces.com/contest/1362/problem/D
// contest link: https://codeforces.com/contest/1362
// time: (?)
// author: reyad

// other_tags: graph, constructive algorithm, implementation, sorting
// difficulty_level: medium

// very bad problem statement

// in summary:
// let, blogs be nodes
// let, topics be colors
// let, references be edges
// the problem requires us to find a sequence of n nodes in the graph
// those satisfies the following conditions:
// (1) no two graph node has same color if they
//     have an edge between them
// (2) if a graph node x has neighbors where their colors
//     from a set S, and the all colors are of set
//     T(of course S is subset of T), then the color
//     of node x will be min({color | color is from set {T - S}})
// also, notice that, the problem tells us to when we visit the first node
// does not have any neighbors(cause, the neighbours have not visited yet, i.e.)
// they have been assigned with any color

// solution idea:
// the problems is greedy itself, requires/forces us to construct the node
// with the less color(means smaller integer value) first
// when construcing the sequence, we just need to check two things
// let the current node be x
// (1) colors of neighbours x != color of x
// (2) colors of neighbours x covers all color
//     less than x

#include <bits/stdc++.h>

using namespace std;

#define N 500050

vector<int> t;
vector<int> idx;
vector<int> adj[N];
vector<int> seq;

bool cmp(int i, int j) {
	return t[i] < t[j];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	for(int i=0; i<n; i++) {
		int topic;
		scanf("%d", &topic);
		t.push_back(topic);
		idx.push_back(i);
	}
	sort(idx.begin(), idx.end(), cmp);
	bool flag = true;
	set<int> unq;
	vector<int> seen(n, 0);
	for(int i=0; i<n; i++) {
		int u = idx[i];
		seen[u] = 1;
		set<int> vtop;
		for(int v: adj[u]) {
			if(seen[v]) {
				if(t[v] == t[u]) {
					flag = false;
					break;
				}
				vtop.insert(t[v]);
			}
		}
		if(vtop.size() != unq.size()) {
			flag = false;
		}
		if(!flag) {
			break;
		}
		if((i+1) < n && t[idx[i]] != t[idx[i+1]]) {
			unq.insert(t[u]);
		}
		seq.push_back(u+1); // cause we subtracted 1 when taking input
	}
	if(!flag) {
		printf("-1\n");
	} else {
		for(int i=0; i<n; i++) {
			printf("%d ", seq[i]);
		}
		printf("\n");
	}
	return 0;
}
```
