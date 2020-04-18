// problem name: Bulls, Cows, and Digits
// problem link: https://toph.co/p/bulls-cows-and-digits
// contest link: https://toph.co/c/practice-icpc-2019-dhaka
// author: reyad
// time: (?)

#include <bits/stdc++.h>

using namespace std;

int bull, cow;
int used[8], my_stack[8], selected[8];

int find(int r[], int s) {
	int c[16] = {0};
	for(int i=0; i<5; i++) {
		int bl = 0;
		for(int j=0; j<5; j++) {
			if(j == i) continue;
			printf("%d", s+j);
		}
		printf("\n"); fflush(stdout);
		scanf("%d %d", &bull, &cow);
		if(bull == 4) exit(0);
		for(int j=0; j<5; j++) {
			if(j == i) continue;
			c[s+j] += (bull + cow);
		}
	}
	int mx = -1, l = 0;
	for(int i=0; i<5; i++) mx = max(mx, c[s+i]);
	if(mx <= 0) return 0;
	for(int i=0; i<5; i++) {
		if(c[s+i] == mx) r[l++] = s+i;
	}
	return l;
}

void perm(int top) {
	if(top == 4) {
		for(int i=0; i<4; i++) printf("%d", selected[my_stack[i]]);
		printf("\n"); fflush(stdout);
		scanf("%d %d", &bull, &cow);
		if(bull == 4) exit(0);
		return;
	}
	for(int i=0; i<4; i++) {
		if(!used[i]) {
			used[i] = 1;
			my_stack[top] = i;
			perm(top+1);
			used[i] = 0;
		}
	}
}

int main() {
	int r[8];
	int l1 = find(r, 0);
	for(int i=0; i<l1; i++) selected[i] = r[i];

	int l2 = find(r, 5);
	for(int i=0; i<l2; i++) selected[l1+i] = r[i];

	for(int i=0; i<4; i++) used[i] = 0;
	perm(0);
	return 0;
}
