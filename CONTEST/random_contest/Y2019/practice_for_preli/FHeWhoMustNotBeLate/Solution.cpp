// problem name: He Who Must Not Be Late
// problem link: https://toph.co/p/he-who-must-not-be-late
// contest link: https://toph.co/c/practice-icpc-2019-dhaka
// author: reyad
// time: (?)

#include <bits/stdc++.h>

int main() {
	char status[16];
	int ah[1024], am[1024];
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int h, m, ch, cm;
		scanf("%d %d %d %d %s", &h, &m, &ch, &cm, status);
		// meets after (h * m) / (h-1) minutes, so...
		int arrival = ch * m + cm;
		if(status[0] == 'P' && status[1] == 'M') arrival = arrival + h * m;
		int last = 2 * h * m;
		int cnt = 0;
		for(int i=0; i<=(h+h); i++) {
			double at = 1.0 * i * h * m / (h - 1);
			if(arrival < at && at < last) {
				double diff = at - arrival;
				ah[cnt] = (int)(diff / m);
				am[cnt] = round(diff - ah[cnt] * m);
				if(am[cnt] == m) {
					ah[cnt]++;
					am[cnt] = 0;
				}
				cnt++;
			}
		}
		printf("Case %d: %d\n", cc+1, cnt);
		for(int i=0; i<cnt; i++) {
			printf("%dh %dm\n", ah[i], am[i]);
		}
	}
	return 0;
}