// problem name: Coin Change (II)
// problem link: http://lightoj.com/volume_showproblem.php?problem=1232
// contest link: (?)
// author: reyad
// time: (?)


#include <bits/stdc++.h>

using namespace std;

#define N 110
#define K 10010
#define MOD 100000007

int main() {
	int dp[N][K];

	int tc;
	scanf("%d", &tc);

	for(int cc=0; cc<tc; cc++) {
		int n, k;
		scanf("%d %d", &n, &k);
		
		for(int j=0; j<=k; j++) dp[0][j] = 0;
		dp[0][0] = 1;
		
		for(int i=1; i<=n; i++) {
			int a;
			scanf("%d", &a);
			for(int j=0; j<=k; j++) dp[i][j] = 0;
			for(int j=0; j+a <= k; j++) dp[i][j+a] = (dp[i][j+a] + dp[i][j] + dp[i-1][j]) % MOD;
			for(int j=0; j<=k; j++) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
		}

		printf("Case %d: %d\n", cc+1, dp[n][k]);
	}
	return 0;
}
