// problem name: Palindromic characteristics
// problem link: https://codeforces.com/contest/835/problem/D
// contest link: https://codeforces.com/contest/835
// time: (?)
// author: reyad

// other_tags: brute force, dp
// difficulty_level: medium


// note: solution is done using the following formula
// (1) if p_k is a k plindrome, then it is also a (k-1) palindrome
// (2) p_k = p_(k-1) + p_(k-1) if substring length is even
// (3) p_k = p_(k-1) + some character + p_(k-1) if sunstring length is odd
// using 2 and 3 one may find the max_k for a particular substring in a bottom
// up approach i.e. from using smaller substring for constructing result for
// larger substring in a iterative fashion
// complexity of this solution is O(n^2)

// there's also a faster dp solution for this problem
// there may have multiple other solution(faster)
// one such solution(complexity O(n)) is using palindromic tree
// read the comments in the editorial to find the link for that solution


#include <bits/stdc++.h>

using namespace std;

#define N 5004
#define MOD 1000000007

int memo[N][N];
int maxk[N][N] = {0}, cnt[N] = {0};

int main() {
	char str[N];
	
	scanf("%s", str);
	int n = strlen(str);
	for(int i=0; i<n; i++) {
		long long int h = 0, rh = 0, p = 47, pw = 1;
		for(int j=i; j<n; j++) {
			int v = str[j] - 'a' + 1;
			h = (h * p + v) % MOD;
			rh = (rh + v * pw) % MOD;
			pw = (pw * p) % MOD;
			memo[i][j] = (int)h;
			memo[j][i] = (int)rh;
		}
	}

	for(int l=1; l<=n; l++) {
		for(int i=0, j=i+l-1; j<n; i++, j++) {
			if(memo[i][j] == memo[j][i]) {
				maxk[i][j] = 1;
				if(l&1) {
					int m = (i+j) / 2;
					if(memo[i][m-1] == memo[m+1][j]) {
						maxk[i][j] = max(maxk[i][j], maxk[m+1][j] + 1);
					}
				} else {
					int m = (i+j) / 2;
					if(memo[i][m] == memo[m+1][j]) {
						maxk[i][j] = max(maxk[i][j], maxk[m+1][j] + 1);
					}
				}
				cnt[maxk[i][j]]++;
			}
		}
	}
	for(int i=n-1; i>0; i--) cnt[i] += cnt[i+1];

	for(int i=1; i<=n; i++) printf("%d ", cnt[i]);
	printf("\n");

	return 0;
}