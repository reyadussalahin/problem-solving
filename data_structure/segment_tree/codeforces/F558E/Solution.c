#include<stdio.h>
#define N 100100
 
typedef struct {
	int c[28];
} Node;
 
Node merge(Node l, Node r) {
	int i;
	Node v;
	for(i=0; i<26; i++) v.c[i] = l.c[i] + r.c[i];
	return v;
}
 
void split(Node v, Node *l, Node *r, int m) {
	int i, cnt = 0;
	for(i=0; i<26; i++) {
		if(cnt < m) {
			r->c[i] = 0;
			if(cnt + v.c[i] < m) l->c[i] = v.c[i];
			else {
				l->c[i] = m - cnt;
				r->c[i] = v.c[i] - l->c[i];
			}
			cnt += l->c[i];
		}
		else {
			l->c[i] = 0;
			r->c[i] = v.c[i];
		}
	}
}
 
char a[N];
Node dflt, t[4 * N];
int flag[4 * N], sw[4 * N];
 
void build(int p, int l, int r) {
	if(l == r) {
		t[p] = dflt;
		t[p].c[a[l] - 'a']++;
		flag[p] = sw[p] = 0;
		return;
	}
	int m = (l+r)/2;
	build(2*p+1, l, m);
	build(2*p+2, m+1, r);
	t[p] = merge(t[2*p+1], t[2*p+2]);
	flag[p] = sw[p] = 0;
}
 
void lazy(int p, int l, int r) {
	int m = (l+r)/2;
	if(sw[p]&1) split(t[p], &t[2*p+1], &t[2*p+2], m-l+1);
	else split(t[p], &t[2*p+2], &t[2*p+1], r-m);
	sw[2*p+1] = sw[2*p+2] = sw[p];
	sw[p] = 0;
}
 
Node combine(int p, int l, int r, int i, int j) {
	if(l == i && r == j) {
		flag[p] = 1;
		return t[p];
	}
	if(sw[p]) lazy(p, l, r);
	int m = (l+r)/2;
	if(j <= m) return combine(2*p+1, l, m, i, j);
	if(i > m) return combine(2*p+2, m+1, r, i, j);
	return merge(combine(2*p+1, l, m, i, m), combine(2*p+2, m+1, r, m+1, j));
}
 
void distribute(int p, int l, int r, int i, int j, Node v, int _sw) {
	if(l == i && r == j) {
		t[p] = v;
		sw[p] = _sw;
		return;
	}
	int m = (l+r)/2;
	if(j <= m) distribute(2*p+1, l, m, i, j, v, _sw);
	else if(i > m) distribute(2*p+2, m+1, r, i, j, v, _sw);
	else {
		Node vl, vr;
		if(_sw&1) split(v, &vl, &vr, m-i+1);
		else split(v, &vr, &vl, j-m);
		distribute(2*p+1, l, m, i, m, vl, _sw);
		distribute(2*p+2, m+1, r, m+1, j, vr, _sw);
	}
	t[p] = merge(t[2*p+1], t[2*p+2]);
}
 
void update(int p, int l, int r, int i, int j, int _sw) {
	Node v = combine(p, l, r, i, j);
	distribute(p, l, r, i, j, v, _sw);
}
 
void show_char(Node v) {
	int i;
	for(i=0; i<26; i++) {
		if(v.c[i]) {
			printf("%c", (char)(i + 'a'));
			break;
		}
	}
}
 
void show(int p, int l, int r, int _flag) {
	_flag |= flag[p];
	if(l == r) {
		if(!_flag) printf("%c", a[l]);
		else show_char(t[p]);
		return;
	}
	if(sw[p]) lazy(p, l, r);
	int m = (l+r)/2;
	show(2*p+1, l, m, _flag);
	show(2*p+2, m+1, r, _flag);
}
 
int main() {
	int i, n, m, l, r, k;
	
	scanf("%d %d", &n, &m);
	scanf("%s", a);
	
	for(i=0; i<26; i++) dflt.c[i] = 0;
	
	build(0, 0, n-1);
	for(i=0; i<m; i++) {
		scanf("%d %d %d", &l, &r, &k);
		if(k == 0) k = 2;
		update(0, 0, n-1, l-1, r-1, k);
	}
	
	show(0, 0, n-1, 0);
	
	return 0;
}

