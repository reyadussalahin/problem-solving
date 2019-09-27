// problem name: Ne-Zu-Ko Chaaaaaaaaaaaaan!
// problem link: https://toph.co/p/ne-zu-ko-chaaaaaaaaaaaaan
// contest link: https://toph.co/c/practice-icpc-2019-dhaka
// author: reyad
// time: (?)

#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b) {
	while(b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	double pi = acos(-1);
	int tc;
	scanf("%d", &tc);

	for(int cc=0; cc<tc; cc++) {
		int n, r;
		scanf("%d %d", &n, &r);
		
		int c = (n+1)/2;
		while(gcd(n+1, c) != 1) c--;

		double half_b = c * pi / (n+1);
		double chord_length = 2 * r * sin(half_b);

		printf("%0.4lf\n", (n+1) * chord_length);
	}

	return 0;
}