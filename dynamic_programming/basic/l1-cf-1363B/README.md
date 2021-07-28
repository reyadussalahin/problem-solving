## Solutions
#### 1
##### Source Code
```c++
// problem name: Subsequence Hate
// problem link: https://codeforces.com/contest/1363/problem/B
// contest link: https://codeforces.com/contest/1363
// time: (?)
// author: reyad


// other_tags: data structures, brute force, strings, implementation
// difficulty_level: beginner


#include <bits/stdc++.h>

using namespace std;

#define N 1024

char s[N];
int one[N];
int zero[N];

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		scanf("%s", s);
		int n = strlen(s);
		for(int i=0; i<n; i++) {
			one[i] = 0;
			zero[i] = 0;
		}
		for(int i=0; i<n; i++) {
			if(s[i] == '1') {
				one[i] = ((i == 0) ? 1 : (one[i-1] + 1));
				zero[i] = ((i == 0) ? 0 : zero[i-1]);
			} else {
				one[i] = ((i == 0) ? 0 : one[i-1]);
				zero[i] = ((i == 0) ? 1 : (zero[i-1] + 1));
			}
		}
		// printf("%d %d\n", one[n-1], zero[n-1]);
		int mn = 987654321;
		for(int i=0; i<n; i++) {
			// taking 0..i as left and i+1...n-1 as right
			// taking left all 0 and right 1: so we've to change left 1's and right 0's
			mn = min(one[i] + zero[n-1] - zero[i], mn);
			// printf("%d: %d %d\n", i, one[i], zero[n-1] - zero[i]);
			// taking left all 1 and right 0: so we've to change left 0's and right 1's
			mn = min(zero[i] + one[n-1] - one[i], mn);
		}
		printf("%d\n", mn);
	}
	return 0;
}
```
