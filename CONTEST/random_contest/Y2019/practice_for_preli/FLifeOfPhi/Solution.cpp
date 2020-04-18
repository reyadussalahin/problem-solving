// problem name: Life of Phi
// problem link: https://toph.co/p/life-of-phi
// contest link: https://toph.co/c/practice-icpc-2019-dhaka
// author: reyad
// time: (?)

#include <bits/stdc++.h>

using namespace std;

#define N 1000000


long long int phi[N + 10], sum[N + 10];
int mark[N + 10] = {0};

int main() {
	sum[0] = 0; phi[0] = 0;
	for(int i=1; i<=N; i++) {
		phi[i] = i;
		sum[i] = sum[i-1] + i;
	}

	phi[1] = 1;
	mark[1] = 1;
	for(int i=2; i<=N; i++) {
		if(!mark[i]) {
			for(int j=i; j<=N; j+=i) {
				mark[j] = 1;
				phi[j] = (i - 1) * phi[j] / i;
			}
		}
	}

	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", sum[n-1] - n * phi[n] / 2);
	}

	return 0;
}