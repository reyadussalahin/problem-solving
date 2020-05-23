// problem name: NAJPF - Pattern Find
// problem link: https://www.spoj.com/problems/NAJPF/
// contest link: (?)
// time: (?)
// author: reyad

// other_tags: substring finding and similiar
// difficulty_level: beginner


// note: this is very easy straight forward problem
// one may solve it using multiple ways


#include <bits/stdc++.h>
 
using namespace std;
 
 
#define N 1000010
#define MOD 1000000007
 
char txt[N], pat[N];
vector<int> v;
 
int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		v.clear();
		scanf("%s %s", txt, pat);
		int n = strlen(txt);
		int m = strlen(pat);
 
		long long int h = 0, hs = 0, p = 331, pw = 1;
		for(int i=0; i<m; i++) pw = (pw * p) % MOD;
		for(int i=0; i<m; i++) hs = (hs * p + (pat[i] - 'a' + 1)) % MOD;
		for(int i=0; i<n; i++) {
			h = (h * p + (txt[i] - 'a' + 1)) % MOD;
			if(i >= m) h = (h - (((txt[i-m] - 'a' + 1) * pw) % MOD) + MOD) % MOD;
			if(i >= m-1 && h == hs) v.push_back(i-m+1);
		}
 
		if(cc) printf("\n");
		if(v.size() == 0) {
			printf("Not Found\n");
			continue;
		}
		printf("%d\n", v.size());
		for(int it: v) printf("%d ", it+1);
		printf("\n");
	}
	return 0;
}