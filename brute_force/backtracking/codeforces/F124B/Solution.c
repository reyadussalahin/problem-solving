// problem name: Permutations
// problem link: https://codeforces.com/contest/124/problem/B
// contest link: https://codeforces.com/contest/124
// time: (?)
// author: reyad

#include <stdio.h>

char num[16][16];
int n, k;
int min_diff = 111111111;
int stack[32], instack[32] = {0};

void update() {
	int i, j, temp, max = -1, min = 111111111;
	for(i=0; i<n; i++) {
		temp = 0;
		for(j=0; j<k; j++) {
			temp = 10 * temp + (int)(num[i][stack[j]] - '0');
		}
		if(temp > max) max = temp;
		if(temp < min) min = temp;
	}
	if(max - min < min_diff) min_diff = max - min;
}

void perm(int top, int total) {
	int i;
	if(top == total) {
		update();
		return;
	}
	for(i=0; i<total; i++) {
		if(!instack[i]) {
			instack[i] = 1;
			stack[top] = i;
			perm(top+1, total);
			instack[i] = 0;
		}
	}
}

int main() {
	int i;
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++) {
		scanf("%s", num[i]);
	}
	perm(0, k);
	printf("%d\n", min_diff);
	return 0;
}