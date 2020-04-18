// problem: https://www.facebook.com/hackercup/problem/2448144345414246/
// contest: https://www.facebook.com/hackercup/contest
// author: reyad


#include <bits/stdc++.h>

using namespace std;


#define N 1000000
#define MOD 1000000007

int main() {
	long long int pw[N+10];
	char s[N+10];

	pw[0] = 1;
	for(int i=1; i<=N; i++) {
		pw[i] = (pw[i-1] * 2) % MOD;
	}

	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, k;
		scanf("%d %d", &n, &k);
		scanf("%s", s);

		int nb = 0;
		long long int ans = 0;
		for(int i=n-1; i>=0; i--) {
			nb = nb + ((s[i] == 'B') ? 1 : -1);
			if(nb > k) {
				ans = (ans + pw[i+1]) % MOD;
				nb = nb - 2;
			}
			if(nb < 0) {
				nb = 0;
			}
		}
		printf("Case #%d: %lld\n", cc+1, ans);
	}

	return 0;
}
