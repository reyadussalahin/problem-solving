// problem name: Cards
// problem link: https://codeforces.com/contest/701/problem/A
// contest link: https://codeforces.com/contest/701
// time: (?)
// author: reyad

// other_tags: implementation
// difficulty_level: beginner

#include <bits/stdc++.h>

using namespace std;

int a[128];
int x[128];

bool cmp(const int i, const int j) {
	return a[i] < a[j];
}

int main() {
	int n;
	scanf("%d", &n);
	int tot = 0;
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		tot += a[i];
		x[i] = i;
	}
	sort(x, x+n, cmp);
	int l = n / 2;
	for(int i=0; i<l; i++) {
		printf("%d %d\n", x[i]+1, x[n-i-1]+1);
	}
	return 0;
}