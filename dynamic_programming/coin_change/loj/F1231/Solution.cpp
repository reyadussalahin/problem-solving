// problem name: Coin Change (I)
// problem link: http://lightoj.com/volume_showproblem.php?problem=1231
// contest link: (?)
// author: reyad
// time: (?)


#include <bits/stdc++.h>

using namespace std;

#define N 1024
#define M 64

int main() {
	int w[M][N], a[M];

	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		
		for(int i=0; i<k; i++) w[0][i] = 0;
		w[0][0] = 1;

		for(int i=1; i<=n; i++) {
			int c;
			scanf("%d", &c);
			for(int h=0; h<=k; h++) {
				w[i][h] = w[i-1][h];
				int sub = a[i];
				for(int j=1; j <= c && h >= sub; j++) {
					w[i][h] = (w[i][h] + w[i-1][h - sub]) % 100000007;
					sub += a[i];
				}
			}
		}

		printf("Case %d: %d\n", cc+1, w[n][k]);
	}
	return 0;
}
