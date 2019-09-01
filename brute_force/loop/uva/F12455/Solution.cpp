// // problem name: Bars
// // problem link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3886
// // contest link: (?)
// // time: (?)
// // author: reyad

#include <bits/stdc++.h>

using namespace std;

int main() {
	int a[1024];
	int tc;
	scanf("%d", &tc);

	for(int cc=0; cc<tc; cc++) {
		int n, p; 
		scanf("%d %d", &n, &p);
		for(int i=0; i<p; i++) scanf("%d", &a[i]);

		int flag = 0;
		int l = (1 << p);
		for(int i=0; i<l; i++) {
			int sum = 0;
			for(int j=0; j<p; j++) {
				if((i&(1<<j))) sum += a[j];
			}
			if(sum == n) {
				flag = 1;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
