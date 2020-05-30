// problem name: Two Arrays And Swaps
// problem link: https://codeforces.com/contest/1353/problem/B
// contest link: https://codeforces.com/contest/1353
// time: (?)
// author: reyad

// other_tags: sortings
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

#define N 32

int a[N], b[N];

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		sort(a, a+n);
		sort(b, b+n);
		int i = n-1, j = n-1, h = 0, cnt = 0;
		long long sum = 0;
		while(cnt < n && h < k) {
			if(a[i] >= b[j]) {
				sum = sum + a[i];
				i--;
			}
			else {
				sum = sum + b[j];
				j--;
				h++;
			}
			cnt++;
		}
		while(i >= 0 && cnt < n) {
			sum = sum + a[i];
			i--;
			cnt++;
		}
		printf("%lld\n", sum);
	}
	return 0;
}