## Solutions
```c++
// problem name: Double Profiles
// problem link: https://codeforces.com/contest/154/problem/C
// contest link: https://codeforces.com/contest/154
// time: (?)
// author: reyad

// other_tags: graphs, sorting
// difficulty_level: expert


// solution idea:
// two possible cases:
// (case-01) when u and v are friend's
//         let u's friendlist be f(u) = {v, x, y, z}, a set;
//         let v's friendlist be f(v) = {u, x, y, z}, a set;
// Now, u and v would be duplicate if,
// f(u) - {v} == f(v) - {u}
// i.e. if their friendlist is same without including themselves(according to problem definition)
//
// (case-02) when u and v are not friend
//         let u's friendlist be f(u) = {x, y, z}, a set;
//         let v's friendlist be f(v) = {x, y, z}, a set;
// Now, in this case u and v would be friend if,
// f(u) == f(v)
// i.e. their friendlist totally same(according to problem definition)

// implementation idea:
// we can use hash to check if two sets are equal or not
// but the problem is removing an element from set(when u and v are friend)
// and then find the hash
// Now, the two solution to solve this issue:
// (01) first method:
//       - make graph using adjacency list
//       - sort adjacency list of each node
//       - use polynomial hash for each node to compute hash of neighbour/friend set
//       - first solve for case-02, calculate result for case-02
//       - insert 'u' into u's friendlist(for each node) in proper sorted position
//       - so, u's friendlist become f(u) = {u, v, x, y, z}, v's friendlist become
//         f(v) = {u, v, x, y, z} and so on..
//       - now, we can solve case-01 using the same procedure as case-02
//       - done
// (02) second method:
//       - notice: friendlist set consists of unique numbers i.e. no numbers twice
//       - so, we can use non-positional rolling hash in this case
//       - distribute 10^6 numbers in 10^18 numbers, so that their sum or xor of any set
//         always give use some unique result
//       - i've used xor in this case
//       - solve for case-01
//       - sort, then solve for case-02
//       - done


#include <bits/stdc++.h>

using namespace std;

#define N 1000010

#define B 1747591
#define P  479001599

long long int x[N], h[N];
int u[N], v[N];

int main() {
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	x[0] = P;
	for(int i=1; i<=n; i++) {
		x[i] = x[i-1] * B;
		h[i] = 0;
	}
	for(int i=0; i<m; i++) {
		scanf("%d %d", &u[i], &v[i]);
		h[u[i]] ^= x[v[i]];
		h[v[i]] ^= x[u[i]];
	}

	long long int cnt = 0;
	for(int i=0; i<m; i++) {
		if((h[u[i]] ^ x[v[i]]) == (h[v[i]] ^ x[u[i]])) cnt++;
	}

	sort(h+1, h+n+1);
	long long int c = 1;
	for(int i=2; i<=n; i++) {
		if(h[i] == h[i-1]) c++;
		else {
			cnt = cnt + ((1LL * c * (c-1)) / 2);
			c = 1;
		}
	}
	if(c) cnt = cnt + ((1LL * c * (c-1)) / 2);

	printf("%lld\n", cnt);
	return 0;
}
```
