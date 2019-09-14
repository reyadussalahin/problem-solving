// problem name: Division
// problem link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=666
// contest link: (?)
// time: (?)
// author: reyad

#include <stdio.h>
#include <string.h>

void update(int n, int c[]) {
	int i;
	for(i=0; i<5; i++) {
		c[(n%10)]++;
		n = n / 10;
	}
}

int check(int c[]) {
	int i;
	for(i=0; i<10; i++) {
		if(c[i] != 1) return 0;
	}
	return 1;
}

int main() {
	int i, n, l, f, cc=0;
	int c[16];
	while(scanf("%d", &n) == 1 && n != 0) {
		l = 100000 / n;
		f = 0;
		if(cc > 0) printf("\n");
		for(i=1; i<=l; i++) {
			memset(c, 0, sizeof(c));
			update(i, c);
			update(i * n, c);
			if(!check(c)) continue;
			printf("%05d / %05d = %d\n", i * n, i, n);
			f |= 1;
		}
		if(!f) printf("There are no solutions for %d.\n", n);
		cc++;
	}
	return 0;
}