// problem_name: Card Constructions
// problem_link: https://codeforces.com/contest/1345/problem/B
// contest_link: https://codeforces.com/contest/1345
// time: (?)
// author: reyad

// other_tags: brute force, dp, math
// difficulty_level: easy


#include <stdio.h>

using namespace std;


int main() {
	int tc;

	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d", &n);
		int cnt = 0;
		while(n > 0) {
			int s = 0, e = 1000000000, x = 0;
			while(s <= e) {
				int m = (s + e) / 2;
				if(((3LL * m * m + m) / 2) <= n) {
					x = m;
					s = m + 1;
				}
				else {
					e = m - 1;
				}
			}
			if(x) {
				n = n - (3LL * x * x + x) / 2;
				cnt++;
			}
			else n = 0;
		}
		printf("%d\n", cnt);
	}
	return 0;
}