// problem: https://www.facebook.com/hackercup/problem/862237970786911/
// contest: https://www.facebook.com/hackercup/contest
// author: reyad


#include <bits/stdc++.h>

using namespace std;


#define M 1024
#define N 64
#define INF 1000000000

int main() {
	long long int w[N][N];
	int x[M], y[M], z[M];

	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, m;
		scanf("%d %d", &n, &m);
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				w[i][j] = INF;
			}
		}
		
		for(int i=0; i<m; i++) {
			scanf("%d %d %d", &x[i], &y[i], &z[i]);
			w[x[i]][y[i]] = w[y[i]][x[i]] = z[i];
		}

		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					if(w[i][j] > w[i][k] + w[k][j]) {
						w[i][j] = w[i][k] + w[k][j];
					}
				}
			}
		}

		int flag = 0;
		for(int i=0; i<m; i++) {
			assert(w[x[i]][y[i]] == w[y[i]][x[i]]);
			// printf("(x, y, z, w[x][y]): %d %d %d %lld\n", x[i], y[i], z[i], w[x[i]][y[i]]);
			if(w[x[i]][y[i]] != z[i]) {
				flag = 1;
				break;
			}
		}

		if(flag) {
			printf("Case #%d: Impossible\n", cc+1);
		}
		else {
			printf("Case #%d: %d\n", cc+1, m);
			for(int i=0; i<m; i++) {
				printf("%d %d %d\n", x[i], y[i], z[i]);
			}
		}
	}

	return 0;
}
