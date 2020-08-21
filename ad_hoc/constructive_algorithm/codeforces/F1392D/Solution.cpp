// problem name: Omkar and Bed Wars
// problem link: https://codeforces.com/contest/1392/problem/D
// contest link: https://codeforces.com/contest/1392
// author: reyad
// time: (?)


// other tags: greedy, dp
// difficulty level: medium


#include <bits/stdc++.h>

using namespace std;

// solution idea:
// -----------------------
// only (RRR...) and 
//      (LLL...) are the wrongs
// i.e. no substring of length 3 with same char is allowed

char a[200020];

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d %s", &n, a);
		int c = 1;
		int cost = 0;
		for(int i=n-1; i>0; i--) {
			if(a[i] == a[0]) {
				c++;
			} else {
				break;
			}
		}
		if(c == n) { // then, all th chars are same
			cost = (n / 3) + (((n%3) == 0) ? 0 : 1); // playing method is circular, and all chars are same
			// so, we need take one more if n is not divided by 3
			// cause, RRR -> RLR it's good
			// but,   RRRR -> RRLR, not good(still, RRR is possible). Rather, LRLR would be good(no RRR)
		} else {
			n = n - c + 1; // reducing n by the number of last char's which
			// are same as first char of string, cause playing method is circular
			for(int i=1; i<n; i++) {
				if(a[i] == a[i-1]) {
					c++;
				} else {
					cost = cost + (c / 3); // splitting up length c of same chars
					// printf("%d: %d\n", i, c);
					c = 1;
				}
			}
			cost = cost + (c / 3);
		}
		printf("%d\n", cost);
	}
	return 0;
}