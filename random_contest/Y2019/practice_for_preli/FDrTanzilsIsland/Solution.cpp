// problem name: Dr. Tanzil's Island
// problem link: https://toph.co/p/dr-tanzil-s-island
// contest link: https://toph.co/c/practice-icpc-2019-dhaka
// author: reyad
// time: (?)

#include <stdio.h>
#include <math.h>


int main() {
	int tc, cc, x;
	double pi = acos(-1);
	scanf("%d", &tc);
	for(cc=0; cc<tc; cc++) {
		scanf("%d", &x);
		printf("%lf\n", pi * x * x);
	}
	return 0;
}
