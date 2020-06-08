// problem name: As Fast As Possible
// problem link: https://codeforces.com/contest/701/problem/D
// contest link: https://codeforces.com/contest/701
// time: (?)
// author: reyad

// other_tags: math
// difficulty_level: medium

#include <bits/stdc++.h>

using namespace std;

// solution idea:
// (01) first we've to observe that, if we want to minimize the time, we've to consider that, all
//      the pupils reach the end of the line at the same time
// (02) now, let the time, t = t1 + t2(here, t1 pupil has v1 speed, and t2 was the time on bus they spend)
//      (note: each pupil has spent exactly t2 time on bus i.e. they were at v2 speed)
// (03) so, to carry all the pupils bus has to be used cnt = ceil(n / k) times and return i.e. go to
//      opposite direction (cnt - 1) times
// (04) let's assume: t = t1 + t2 = (l1 / v1) + (l2 / v2)
//      we know that, v2 > v1, so increasing l2 will minimize the time(cause, l1 + l2 = l, constant)
// (05) so, a pupil crosses l2 length on bus and l1 on its own
//      let's assume, the bus has to came back(i.e. travel in opposite direction) to pick up next k
//      pupil which is a distance of x
//      so, we may say that:
//      => the time bus travel = the time pupil travel
//      => (l2 + x) / v2 = (l2 - x) / v1
//      => x = l2 * (v2 - v1) / (v1 + v2)
// (05) so, the total distance the bus has to travel is: cnt * l2 + (cnt - 1) * x
// (06) so, the total time the bus has to travel: b_time = (cnt * l2 + (cnt - 1) * x) / v2;
// (07) and, the total time a pupil has to travel: p_time = (l2 / v2) + ((l - l2) / v1)
// (08) when, b_time <= p_time, we can see for larger l2, if that's also satisfy b_time <= p_time
//      else, we reduce l2 and watch for that
//      and bibary serach can perfectly do this job

int main() {
	int n, l, v1, v2, k;
	scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);
	double s = 0.0, e = 0.0 + l, optimal = 0.0 + l;
	int cnt = (n+k-1) / k;
	while(e - s > 1e-9) {
		double l2 = (s + e) / 2.0;
		double x = (l2 * (v2 - v1)) / (0.0 + v1 + v2);
		double b_time = (l2 * cnt + (cnt - 1) * x) / v2;
		double p_time = (l2 / v2) + ((l - l2) / v1);
		if(b_time <= (p_time + 1e-9)) {
			optimal = p_time;
			s = l2;
		} else {
			e = l2;
		}
	}
	printf("%.9f\n", optimal);
	return 0;
}