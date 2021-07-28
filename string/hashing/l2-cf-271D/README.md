## Solutions
#### 1
##### Source Code
```c++
// problem name: Good Substrings
// problem link: https://codeforces.com/contest/271/problem/D
// contest link: https://codeforces.com/contest/271
// time: (?)
// author: reyad

// other_tags: data structures
// difficulty_level: medium

// the problem can be solved in multiple ways
// hashing is an intelligent technique, but can be hacked easily
// while using polynomial hashing, choose your base and mod value carefully


#include <bits/stdc++.h>

using namespace std;

#define N 1520
#define MOD 1000000007

int main() {
	char s[N], gb[32];
	int k, bc = 0;
	long long int b[N * N];

	scanf("%s %s %d", s, gb, &k);
	
	int l = strlen(s);
	for(int i=0; i<l; i++) {
		int badCnt = 0, p = 47;
		long long int h = 0;
		for(int j=i; j<l; j++) {
			if(gb[s[j] - 'a'] == '0') badCnt++;
			if(badCnt > k) break;
			h = h * p + (s[j] - 'a' + 1);
			if(h >= MOD) h -= MOD;
			b[bc++] = h;
		}
	}

	sort(b, b + bc);
	int c = (bc) ? 1 : 0;
	for(int i=1; i<bc; i++) {
		if(b[i] == b[i-1]) continue;
		else c++;
	}
	printf("%d\n", c);
	
	return 0;
}
```
