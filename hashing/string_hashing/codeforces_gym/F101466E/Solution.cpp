// problem name: Text Editor
// problem link: https://codeforces.com/gym/101466/problem/E
// contest link: https://codeforces.com/gym/101466
// time: (?)
// author: reyad

// other_tags: binary search, dp, string suffix structures, substring searching
// difficulty_level: medium

// note: this problem can be solved in multiple ways

#include <bits/stdc++.h>

using namespace std;

#define N 100010

char a[N], b[N];
int k, na, nb;

int count(int w) {
	long long int h = 0, eh = 0, hs = 0, pwm = 1, p = 47;
	int count = 0;
	for(int i=0; i<w; i++) hs = hs * p + (b[i] - 'a' + 1);
	for(int i=0; i<w; i++) pwm = pwm * p;
	for(int i=0; i<na; i++) {
		h = h * p + (a[i] - 'a' + 1);
		if(i >= w) eh = eh * p + (a[i-w] - 'a' + 1) * pwm;
		if(i >= w-1 && (eh + hs) == h) count++;
	}
	return count;
}

int main() {
	gets(a);
	gets(b);
	scanf("%d", &k);
	na = strlen(a);
	nb = strlen(b);
	int s = 1, e = nb, x = -1;
	while(s <= e) {
		int m = (s + e) / 2; // m represents length of prefix that we're counting
		int cnt = count(m);
		if(cnt >= k) {
			x = m;
			s = m + 1;
		} else {
			e = m - 1;
		}
	}
	if(x == -1) printf("IMPOSSIBLE\n");
	else {
		b[x] = '\0';
		printf("%s\n", b);
	}
	return 0;
}