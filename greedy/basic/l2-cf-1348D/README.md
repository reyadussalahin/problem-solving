## Solutions
#### 1
##### Source Code
```c++
// problem_name: Phoenix and Science
// problem_link: https://codeforces.com/contest/1348/problem/D
// contest_link: https://codeforces.com/contest/1348
// time: (?)
// author: reyad

// other_tags: binary search, constructive algorithm, implementation, math
// difficulty_level: medium


#include <bits/stdc++.h>

using namespace std;


int main() {
	int tc;

	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d", &n);
		vector<int> v;
		for(int i=1; i<=n; i+=i) {
			n -= i;
			v.push_back(i);
		}
		if(n > 0) v.push_back(n);
		sort(v.begin(), v.end());
		printf("%d\n", (int)v.size() - 1);
		for(int i=1; i<(int)v.size(); i++) printf("%d ", v[i] - v[i-1]);
		printf("\n");
	}

	return 0;
}
```
