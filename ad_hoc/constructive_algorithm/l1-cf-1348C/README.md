## Solutions
#### 1
##### Source Code
```c++
// problem_name: Phoenix and Distribution
// problem_link: https://codeforces.com/contest/1348/problem/C
// contest_link: https://codeforces.com/contest/1348
// time: (?)
// author: reyad

// other_tags: greedy, strings, sorting
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

int cnt[128];
char s[100010];
char b[32];

int main() {
	int tc;

	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, k;
		
		scanf("%d %d", &n, &k);
		scanf("%s", s);
		
		for(int i='a'; i<='z'; i++) cnt[i] = 0;
		for(int i=0; i<n; i++) cnt[s[i]]++;
		int bc = 0;
		for(int i='a'; i<='z'; i++) if(cnt[i]) b[bc++] = i;

		int p = 0, tot = 0;
		while(tot + cnt[b[p]] < k) {
			tot += cnt[b[p]];
			p++;
		}
		if(p > 0) printf("%c", b[p]);
		else {
			printf("%c", b[p]);
			cnt[b[p]] -= k;
			if(bc == 1) {
				while(cnt[b[p]] > 0) {
					printf("%c", b[p]);
					cnt[b[p]] -= k;
				}
			}
			else if(!cnt[b[p]] && bc == 2) {
				int x = (cnt[b[++p]] + k - 1) / k;
				for(int i=0; i<x; i++) printf("%c", b[p]);
			}
			else {
				while(p < bc) {
					for(int i=0; i<cnt[b[p]]; i++) {
						printf("%c", b[p]);
					}
					p++;
				}
			}
		}
		printf("\n");
	}

	return 0;
}
```
