// problem name: Omkar and Waterslide
// problem link: https://codeforces.com/contest/1392/problem/C
// contest link: https://codeforces.com/contest/1392
// author: reyad
// time: (?)


// other tags: implementation
// difficulty level: beginner


#include <bits/stdc++.h>

using namespace std;

int x[200020];
int a[200020];
int seen[200020];

bool cmp(int i, int j) {
	if(a[i] == a[j]) {
		return i < j;
	}
	return a[i] < a[j];
}

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
			x[i] = i;
			seen[i] = false;
		}
		sort(x, x + n, cmp);
		
		long long cost = 0;
		int i = 0;
		while(i < n) {
			if(!seen[i]) {
				if(x[i] == 0 || a[x[i]-1] <= a[x[i]]) {
					i++;
					continue;
				}
				int j = i+1;
				while(j < n && a[x[j]] == a[x[i]] && x[j] == x[j-1]+1) {
					seen[j] = true;
					j++;
				}
				cost = cost + a[x[i]-1] - a[x[i]];
				i = j;
			} else {
				i++;
			}
		}

		printf("%lld\n", cost);
	}
	return 0;
}