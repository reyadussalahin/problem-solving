## Solutions
```c++
// problem name: Santa Claus and a Palindrome
// problem link: https://codeforces.com/contest/752/problem/D
// contest link: https://codeforces.com/contest/752
// time: (?)
// author: reyad


// other_tags: data structures, greedy, strings
// difficulty_level: expert



// note: this is by far the worst problem i've met while solving problems using hash
// the testcase is very strong, it hacks almost every single hash, and even some double hash
// i had to use double hashes simultaneously with two different bases and mods
// one my 'double hash without modulo' got hacked
// modulo with two different values saved the solution(for the provided testcase)


#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define M 1000000007
#define M2 1000000009

typedef long long int ll;

int a[N];
char g[N];

struct Compare {
	bool operator()(const int i, const int j) const {
		return a[i] < a[j];
	}
};

map<pair<ll, ll>, priority_queue<int, vector<int>, Compare>> hmp;
map<pair<ll, ll>, priority_queue<int, vector<int>, Compare>> rhmp;
map<pair<ll, ll>, priority_queue<int, vector<int>, Compare>> pmp;

int main() {
	int k, n;
	scanf("%d %d", &k, &n);
	for(int kk=0; kk<k; kk++) {
		scanf("%s %d", g, &a[kk]);
		ll h = 0, h2 = 0, rh = 0, rh2 = 0, p = 647, p2 = 2797;
		for(int i=0; i<n; i++) {
			h = (h * p + (g[i] - 'a' + 1)) % M;
			h2 = (h2 * p2 + (g[i] - 'a' + 1)) % M2;
			rh = (rh * p + (g[n-i-1] - 'a' + 1)) % M;
			rh2 = (rh2 * p2 + (g[n-i-1] - 'a' + 1)) % M2;
		}
		pair<ll, ll> hp = make_pair(h, h2);
		pair<ll, ll> hrev = make_pair(rh, rh2);
		if(hp == hrev) {
			pmp[hp].push(kk);
		} else {
			hmp[hp].push(kk);
			rhmp[hrev].push(kk);
		}
	}
	ll mxb = 0;
	for(auto it = hmp.begin(); it != hmp.end(); it++) {
		auto it2 = rhmp.find(it->first);
		if(it2 == rhmp.end()) continue;
		auto &q = it->second;
		auto &q2 = it2->second;
		while(!q.empty() && !q2.empty() && a[q.top()] + a[q2.top()] > 0) {
			mxb = mxb + a[q.top()] + a[q2.top()];
			q.pop();
			q2.pop();
		}
	}
	mxb = mxb / 2;
	int x = 0;
	for(auto it = pmp.begin(); it != pmp.end(); it++) {
		auto &q = it->second;
		while(q.size() >= 2) {
			int u = q.top();
			q.pop();
			if(a[u] + a[q.top()] > 0) {
				int v = q.top();
				q.pop();
				mxb = mxb + a[u] + a[v];
				if(a[v] < 0) x = max(x, -a[v]);
			} else {
				q.push(u);
				break;
			}
		}
		if(!q.empty()) x = max(x, a[q.top()]);
	}
	mxb = mxb + x;
	printf("%lld\n", mxb);
	return 0;
}

```
