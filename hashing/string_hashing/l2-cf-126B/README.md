## Solutions
#### 1
##### Source Code
```c++
// problem name: Password
// problem link: https://codeforces.com/contest/126/problem/B
// contest link: https://codeforces.com/contest/126
// time: (?)
// author: reyad

// other_tags: binary search, dp, string suffix structures, substring searching
// difficulty_level: medium


// solution idea:
// let's assume k is the smallest length for
// which s[0...k-1] = s[n-k...n-1]
// let's denote this string as m_1(smallest string that both temporary buddies PREFIX and SUFFIX)
// so, we may say that, if there is a longer substring than m_1, let's denote as m_2
// then, m_2 must satisfy one of two forms written below:
// (form-01) m_2 = m_1 + m_1
// (form-02) m_2 = m_1 + some characters + m_1
// (cause, m_1 is the string that always has to be the suffix and prefix
//  as m_1 found both in prefix of 's[]' and suffix of 's[]')
// Now, if we think about m_3, then m_3 should follow the rules for m_2.
// i.e.: (form-01) m_3 = m_2 + m_2
//       (form-02) m_3 = m_2 + some characters + m_2
// so, that tells us: if a string contains m_3, then it must contain m_2 and of course m_1
// or, generally: if a string contains m_r, then it must contain m_(r-1), m_(r-2)...
// Now, if we somehow found out matching strings we can use binary search to determine to go which
// direction to find the maximum length

// implementation idea:
// To solve the problems of matching strings, we could use hashing, as hashing gives O(1) time
// to match two strings
// we would maintain two hashes, one from start and the other from end of 's[]'
// if hash matches, then we've found a match
// we'd be sucessively get m_1, m_2, ..., m_r
// then, we may use binary search based on length of matched strings and hashes to determine
// if 's[]' contains a substring or not
// for each selection of substring m_x we've to check inside 's[]' using a window of length
// so, the total complexity would be O(n * log(n))

#include <bits/stdc++.h>

using namespace std;

#define N 1000010

char s[N];
int n, l[N], mc = 0;
long long int m[N];
const long long int p = 47;

bool contains(long long int hs, int w) {
	long long int h = 0, eh = 0, pwm = 1;
	for(int i=0; i<w; i++) pwm = pwm * p;
	for(int i=1; i<n-1; i++) {
		h = h * p + (s[i] - 'a' + 1);
		if(i >= w+1) eh = eh * p + (s[i-w] - 'a' + 1) * pwm;
		if(i >= w && (eh + hs) == h) return true;
	}
	return false;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	long long int h = 0, rh = 0, pw = 1;
	for(int i=0, j=n-1; j>0; j--, i++) {
		h = h * p + (s[i] - 'a' + 1);
		rh = rh + (s[j] - 'a' + 1) * pw;
		pw *= p;
		if(h == rh) {
			m[mc] = h;
			l[mc++] = i+1;
		}
	}
	int start = 0, end = mc-1, x = -1;
	while(start <= end) {
		int mid = (start + end) / 2;
		if(contains(m[mid], l[mid])) {
			x = mid;
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	if(x == -1) printf("Just a legend\n");
	else {
		s[l[x]] = '\0';
		printf("%s\n", s);
	}
	return 0;
}
```
