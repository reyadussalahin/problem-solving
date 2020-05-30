// problem name: K-periodic Garland
// problem link: https://codeforces.com/contest/1353/problem/E
// contest link: https://codeforces.com/contest/1353
// time: (?)
// author: reyad

// other_tags: brute force, dp
// difficulty_level: easy


// solution hint:
// >> first count no of all '1's
// >> let's consider a start point u
// >> then, we've to check [u, u+k, u+2k, ..., u+rk]...(i)
// >> let, diff = 0, which increases if '0' found in u+x
//    and cecreases if '1' found in u+x
// >> so, if diff > 0, it means we've to turn more light on than turn off
// >> and, when that happens we would just decide to turn off rather
//    than turning on and set diff to 0


#include <bits/stdc++.h>

using namespace std;

#define N 1000100

char s[N];

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, k;
		scanf("%d %d %s", &n, &k, s);
		int one = 0;
		for(int i=0; i<n; i++) {
			if(s[i] == '1') {
				one++;
			}
		}
		int mn = 987654321;
		for(int i=0; i<k; i++) {
			int diff = 0;
			for(int j=i; j<n; j+=k) {
				if(s[j] == '0') diff++;
				else diff--;
				if(diff > 0) diff = 0;
				mn = min(mn, one + diff);
			}
		}
		printf("%d\n", mn);
	}
	return 0;
}