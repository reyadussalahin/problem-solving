## Solutions
#### 1
##### Source Code
```c++
// problem name: Games on a CD
// problem link: https://codeforces.com/contest/727/problem/E
// contest link: https://codeforces.com/contest/727(Technocup 2017 - Elimination Round 1 (Unofficially Open for Everyone, Rated for Div. 2))
// time: (?)
// author: reyad

// other_tags: data structures, string suffix structures, strings
// difficulty_level: expert

// note: this problem's solution is very easy.
// but solving it with hash is a pain
// i had to use two hashes to avoid hash collision
// while implmenting hash make sure you choose base and mod very carefully


#include <bits/stdc++.h>

using namespace std;

#define N 1000100
#define M 1000000007
#define M2 1000000009

int n, k, gn, ans[N / 10], acnt = 0;
pair<int, int> s[N+N];
bool seen[N / 10];
char cd[N+N], g[N / 10];
map<pair<int, int>, int> gmp;


int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", cd);

	int l = n * k;
	for(int i=0; i<l; i++) cd[l+i] = cd[i];
	l += l;
	long long int h = 0, h2 = 0, pwm = 1, pwm2 = 1, p = 647, p2 = 2797;
	for(int i=0; i<k; i++) {
		pwm = (pwm * p) % M;
		pwm2 = (pwm2 * p2) % M2;
	}
	for(int i=0; i<l; i++) {
		h = (h * p + (cd[i] - 'a' + 1)) % M;
		h2 = (h2 * p2 + (cd[i] - 'a' + 1)) % M2;
		if(i >= k) {
			h = (h - (((cd[i-k] - 'a' + 1) * pwm) % M) + M) % M;
			h2 = (h2 - (((cd[i-k] - 'a' + 1) * pwm2) % M2) + M2) % M2;
		}
		if(i >= k-1) s[i-k+1] = make_pair(h, h2);
	}

	scanf("%d", &gn);
	for(int i=0; i<gn; i++) {
		scanf("%s", g);
		long long int hs = 0, hs2 = 0;
		for(int j=0; j<k; j++) {
			hs = (hs * p + (g[j] - 'a' + 1)) % M;
			hs2 = (hs2 * p2 + (g[j] - 'a' + 1)) % M2;
		}
		gmp[make_pair(hs, hs2)] = i;
	}

	assert(gmp.size() == gn);
	
	for(int i=0; i<gn; i++) seen[i] = false;
	for(int i=0; i<k; i++) {
		acnt = 0;
		for(int j=i, r=0; r<n; r++, j+=k) {
			if(gmp.count(s[j])) {
				int idx = gmp[s[j]];
				if(seen[idx]) break;
				ans[acnt++] = idx;
				seen[idx] = true;
			}
			else break;
		}
		if(acnt == n) break;
		for(int j=0; j<acnt; j++) seen[ans[j]] = false;
	}
	if(acnt == n) {
		printf("YES\n");
		for(int i=0; i<acnt; i++) printf("%d ", ans[i] + 1);
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}

```
