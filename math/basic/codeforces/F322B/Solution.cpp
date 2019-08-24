// problem name: Ciel and Flowers
// problem link: https://codeforces.com/contest/322/problem/B
// contest link: Ciel and Flowers
// author: reyad
// time: (?)


#include<bits/stdc++.h>


using namespace std;


int main() {
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	
	int mn = min(r, min(g, b));

	int ans = 0;
	for(int e=0; e<3; e++) {
		if(e <= mn) {
			ans = max(ans, (r-e)/3 + (g-e)/3 + (b-e)/3 + e);
		}
	}
	
	printf("%d\n", ans);

	return 0;
}
