## Solutions
```c++
// problem_name: Puzzle Pieces
// problem_link: https://codeforces.com/contest/1345/problem/A
// contest_link: https://codeforces.com/contest/1345
// time: (?)
// author: reyad

// other_tags: game
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;


int main() {
	int tc;

	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, m;
		scanf("%d %d", &n, &m);

		if(n == 1 || m == 1) {
			printf("YES\n");
		} else {
			if(n <= 2 && m <= 2) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
```
