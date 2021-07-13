## Solutions
```c++
// problem name: Game With Array
// problem link: https://codeforces.com/contest/1355/problem/D
// contest link: https://codeforces.com/contest/1355
// time: (?)
// author: reyad

// other_tags: math
// difficulty_level: easy

// solution idea:
// observation-01: let avg = (S / N)
//                 if avg < 2, then its not possible to construct any solution
//                 cause, 1 would be present, at least once, and if not then multiple times
//                 which ensures that one can make any possible value between 1...S
// onservation-02: if avg >= 2, then:
//                 2, 2, ...2(n-1 times), S - (2 * (n-1)) could be a possible answer
//                 cause, the sum is S and 1 can't be made from any subarray


#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	if(s < 2 * n) { // if avg is less than 2 i.e. between 1 <= avg < 2
		printf("NO\n");
	} else {
		printf("YES\n");
		for(int i=0; i<n-1; i++) {
			printf("2 ");
		}
		printf("%d\n", s - 2 * (n-1));
		printf("1\n");
	}
	return 0;
}
```
