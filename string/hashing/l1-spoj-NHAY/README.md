## Solutions
```c++
// problem name: NHAY - A Needle in the Haystack
// problem link: https://www.spoj.com/problems/NHAY/
// contest link: (?)
// time: (?)
// author: reyad

// other_tags: substring finding and similiar
// difficulty_level: beginner


// note: this is very easy straight forward problem
// one may solve it using multiple ways


#include <bits/stdc++.h>
 
using namespace std;
 
 
#define N 2000010
#define MOD 1000000007

char txt[N], pat[N];
 
int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		scanf("%s %s", pat, txt);
		int m = strlen(pat);
		int n = strlen(txt);

		long long int base = 47, pwm = 1;
		for(int i=0; i<m; i++) pwm = (pwm * base) % MOD;

		long long int hpat = 0;
		for(int i=0; i<m; i++) hpat = (hpat * base + (pat[i] - 'a' + 1)) % MOD;

		long long int htxt = 0;
		bool flag = false;
		for(int i=0; i<n; i++) {
			htxt = (htxt * base + (txt[i] - 'a' + 1)) % MOD;
			if(i >= m) htxt = (htxt - (((txt[i-m] - 'a' + 1) * pwm) % MOD) + MOD) % MOD;
			if(i >= m-1 && htxt == hpat) {
				printf("%d\n", i-m+1);
				flag = true;
			}
		}
		if(!flag) printf("\n");
	}
	return 0;
}
```
