## Solutions
#### 1
##### Source Code
```c++
// problem name: Connecting Universities
// problem link: https://codeforces.com/contest/701/problem/E
// contest link: https://codeforces.com/contest/701
// time: (?)
// author: reyad

// other_tags: dp, graph, tree
// difficulty_level: medium

#include <bits/stdc++.h>

using namespace std;

#define N 200020

// solution idea:
// (1) the whole solution is dependent on properties of tree
// (2) the idea is to increase the number of usage of an edge to have the maximum possible sum(distance)
//     of university pairs
// (3) and it can be done by choosing maximum possible times an edge can be used(where we always take the
//     maximum for each edge), when the subtree which is hold by that edge(considering a rooted tree)
// (4) it can be proved that, the maximum possible number of times an edge can be used is:
//     let's consider an edge u-v, where u is parent of v
//     and v subtree has tcnt universities(including v)
//     then, maximum no. of times u-v edge can be used is: min(tcnt, (k+k) - tcnt)
//     i.e. the no. of pairs that can be constructed with outside of the v subtree
// (5) the proof of min(tcnt, (k+k) - tcnt) is maximum:
//     if it is not maxmimum, then consider other cases that could be maximum
//     and example of such cases would be: atleast one or more pairs are constructed inside v subtree and
//     atleast one or more pairs are construted outside v subtree which gives much more edge usage than our
//     provided formula. and if we van prove that such example couldn't give much than our provided formula
//     then we are done
//     proof by example:
//     consider a pair outside of v subtree is p, q and a pair inside of v subtree is x, y
//     then, the distance between p and q is: dist(p, q) = dist(p, lca(p, q)) + dist(q, lca(p, q))
//     and, the distance between x and y is: dist(x, y) = dist(x, lca(x, y)) + dist(y, lcs(x, y))
//     Now, let's consider the distance between: p, x and q, y
//     here we've to consider some cases regarding lca(p, q)
//     case-01: when lca(p, q) is nearer to v than both p and q
//              dist(p, x) = dist(p, lca(p, q)) + dist(lca(p, q), lca(x, y)) + dist(lca(x, y), x)
//              dist(q, y) = dist(q, lca(p, q)) + dist(lca(p, q), lca(x, y)) + dist(lca(x, y), y)
//       >> case-01 clearly shows that, dist(p, x) + dist(q, y) >= dist(p, q) + dist(x, y)
//     case-02: either p or q is nearer to v than lca(p, q), let's assume it p:
//              dist(p, x) = dist(p, lca(x, y)) + dist(lca(x, y), x)
//              dist(q, y) = dist(q, lca(p, q)) + dist(lca(p, q), lca(x, y)) + dist(lca(x, y), y)
//       >> case-02 also clearly shows that, dist(p, x) + dist(q, y) >= dist(p, q) + dist(x, y)
//     [[proved]]


vector<int> adj[N];
int seen[N] = {0};
int hasUniversity[N] = {0};

int n, k, k2;

long long maxSum = 0;

int dfs(int u) {
	seen[u] = 1;
	int cnt = (hasUniversity[u]) ? 1 : 0;
	for(int v: adj[u]) {
		if(!seen[v]) {
			/* we are calculating maximum possible use of edge (u to v) */
			/* tcnt refers to no of nodes(i.e. cities) under
			 * edge u-v(i.e. v subtree) which has universities
			 */
			int tcnt = dfs(v);
			maxSum = maxSum + min(tcnt, k2 - tcnt); // updating maxSum with max possible
			// usage of edge u-v in pairs
			cnt += tcnt; // updating cnt i.e. no of universities to return to parent node
		}
	}
	return cnt;
}

int main() {
	scanf("%d %d", &n, &k);
	k2 = k + k;
	for(int i=0; i<k2; i++) {
		int uni;
		scanf("%d", &uni);
		hasUniversity[uni] = 1;
	}
	for(int i=1; i<n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	printf("%lld\n", maxSum);
	return 0;
}
```
