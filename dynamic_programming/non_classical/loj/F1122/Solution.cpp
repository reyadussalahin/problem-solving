// problem: http://lightoj.com/volume_showproblem.php?problem=1122
// contest: (?)
// problem name: Digit Count
// author: reyad
// time: (?)


#include <bits/stdc++.h>

using namespace std;


int main() {
	int tc;
	scanf("%d", &tc);

	int a, has[32];
	int dp[16][16];

	for(int cc=0; cc<tc; cc++) {
		int m, n;
		scanf("%d %d", &m, &n);

		for(int i=0; i<=10; i++) has[i] = 0;

		for(int i=0; i<m; i++) {
			scanf("%d", &a);
			has[a] = 1;
		}

		for(int i=0; i<=n; i++) {
			for(int j=0; j<=10; j++) {
				dp[i][j] = 0;
			}
		}

		for(int i=0; i<=10; i++) if(has[i]) dp[0][i] = 1;

		for(int i=1; i<n; i++) {
			for(int j=0; j<=10; j++) {
				if(!has[j]) continue;
				for(int k=-2; k<=2; k++) {
					int take = k + j;
					if(0 <= take && take <= 10 && has[take]) dp[i][j] += dp[i-1][take];
				}
			}
		}

		int ans = 0;
		for(int i=0; i<=10; i++) ans += dp[n-1][i];

		printf("Case %d: %d\n", cc+1, ans);
	}

	return 0;
}
