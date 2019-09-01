// problem name: Firetruck
// problem link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=144
// contest link: (?)
// time: (?)
// author: reyad

#include <bits/stdc++.h>

using namespace std;

int x, cnt, top;
int g[32][32], st[32], qu[32], instack[32] = {0};

void way(int u) {
	if(u == x) {
		printf("%d", 1);
		for(int i=0; i<top; i++) {
			printf(" %d", st[i]);
		}
		printf("\n");
		cnt++;
		return;
	}
	for(int i=1; i<=20; i++) {
		if(g[u][i] && !instack[i]) {
			int flag = 0, qs = 0, qe = 0, new_top = top;
			qu[qe++] = i;
			while(qs != qe) {
				int at = qu[qs++];
				if(at == x) {
					flag = 1;
					break;
				}
				for(int j=1; j<=20; j++) {
					if(!instack[j] && g[at][j]) {
						qu[qe++] = j;
						instack[j] = 1;
						st[new_top++] = j;
					}
				}
			}
			while(new_top > top) instack[st[--new_top]] = 0;
			
			if(!flag) continue;

			instack[i] = 1;
			st[top++] = i;
			way(i);
			top--;
			instack[i] = 0;
		}
	}
}

int main() {
	int cc = 0;
	while(scanf("%d", &x) == 1) {
		for(int i=1; i<=21; i++) {
			for(int j=1; j<=21; j++) {
				g[i][j] = 0;
			}
		}
		
		int u, v;
		do {
			scanf("%d %d", &u, &v);
			g[u][v] = g[v][u] = 1;
		} while(u != 0 && v != 0);
		
		printf("CASE %d:\n", cc+1);
		cnt = top = 0;
		instack[1] = 1;
		way(1);
		printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, x);
		cc++;
	}
	return 0;
}