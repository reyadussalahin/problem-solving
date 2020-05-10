// problem_name: Hilbert's Hotel
// problem_link: https://codeforces.com/contest/1345/problem/C
// contest_link: https://codeforces.com/contest/1345
// time: (?)
// author: reyad

// other_tags: sorting
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n;
		scanf("%d", &n);
		set<int> s;
		for(int i=0; i<n; i++) {
			int a;
			scanf("%d", &a);
			a = (a % n);
			if(a < n) a += n;
			s.insert((i + a) % n);
		}
		if((int)s.size() == n) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}