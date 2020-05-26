// problem name: The Gift Of Raksha Bandhan
// problem link: https://www.codechef.com/INSQ2015/problems/INSQ15_A
// contest link: https://www.codechef.com/INSQ2015
// time: (?)
// author: reyad

// other_tags:  binary-search, string suffix structures, strings
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;


#define N 5000010

char str[N];
long long int p = 647, pw[N], h[N];

int main() {
	scanf("%s", str);
	int l = strlen(str);
	h[0] = str[0] - 'a' + 1;
	pw[0] = 1;
	for(int i=1; i<l; i++) {
		pw[i] = pw[i-1] * p;
		h[i] = h[i-1] + (str[i] - 'a' + 1) * pw[i];
	}
	int q;
	scanf("%d", &q);
	for(int i=0; i<q; i++) {
		int k;
		scanf("%d", &k);
		int s = 0, e = k-1, x = -1;
		while(s <= e) {
			int m = (s + e) / 2;
			if((h[m] * pw[k]) + h[k-1] == h[k+m]) {
				x = m;
				s = m + 1;
			} else {
				e = m - 1;
			}
		}
		printf("%d\n", x+1);
	}
	return 0;
}