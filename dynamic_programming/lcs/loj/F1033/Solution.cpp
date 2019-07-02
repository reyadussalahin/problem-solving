// problem: http://lightoj.com/volume_showproblem.php?problem=1033
// contest:
// problem name: Generating Palindromes
// author: reyad


#include <bits/stdc++.h>

using namespace std;


#define N 128

int main() {;
	char s[N], r[N];
	int dp[N][N];

	int tc;
	scanf("%d", &tc);

	for(int cc=0; cc<tc; cc++) {
		scanf("%s", s+1);
		int n = strlen(s+1);
		for(int i=0; i<=n; i++) {
			dp[i][0] = dp[0][i] = 0;
			r[i] = s[n-i+1];
		}
		// printf("n: %d\n", n);
		// printf("s: %s\n", s+1);
		// printf("r: %s\n", r+1);
		int ans = n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n-i; j++) {
				if(s[i] == r[j]) dp[i][j] = 1 + dp[i-1][j-1];
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
			ans = min(ans, n - 1 - 2 * dp[i-1][n-i]);
			ans = min(ans, n - 2 * dp[i][n-i]);
		}
		printf("Case %d: %d\n", cc+1, ans);
	}

	return 0;
}
