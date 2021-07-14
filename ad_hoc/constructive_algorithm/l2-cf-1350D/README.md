## Solutions
#### 1
##### Source Code
```c++
// problem name: Orac and Medians
// problem link: https://codeforces.com/contest/1350/problem/D
// contest link: https://codeforces.com/contest/1350
// time: (?)
// author: reyad

// other_tags: greedy
// difficulty_level: medium


// solution:
// >> let's denote l_k for number of elements less than k
//                 e_k for number of elements equal to k
//                 g_k for number of lements greater than k
// Now it can be shown that there's no solution if
// for every possible subarray which's length greater than 1 the following
// condition is true:
// l_k >= e_k + g_k .....(i)
// it's easy to realize that, if equation(i) holds, then k could never the middle element ever
// notice that: if we can solve it for any value greater than k, then its also solvable
// for k, if there's at least one k present in the array in any place
// notice: there's only two type of transitions, positive transition(when value >= e_k) and
// negative transition(when value <= k)

// see below an example graph:
//         _   _   _
// (i)   _| |_| |_| |_...
//
//
// (ii)  _          
//        |_       _
//          |_   _| |_...
//            |_|
//
//               _
//             _| |_
//           _|     |_...
//         _|
// (iii) _|
//
// (point-01) So it clearly shows that there could only be a solution if and only if
//            there's at least 2 positive transitions in a window of three transitions...
//            cause, then in a three window e_k + g_k > l_k would satisfied
// (point-02) As there's only positive or negative transitions, it can be showed that,
//            if there's no solution for a window of size 'w'( we are considering all possible 'w' size
//            windows) then there's no solution for 'w+1' size windows
// (point-03) for n == 1 and 2 solve it manually


#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define INF 12345678

int b[N];

int main() {
	int tc;
	scanf("%d", &tc);
	for(int cc=0; cc<tc; cc++) {
		int n, k, np = 0;
		scanf("%d %d", &n, &k);
		bool flag = false, seenK = false;
		for(int i=0; i<n; i++) {
			scanf("%d", &b[i]);
			seenK |= (b[i] == k);
			np += (b[i] >= k);
			if(i >= 3) np -= (b[i-3] >= k);
			if(np >= 2) {
				flag = true;
			}
		}
		if(seenK && (flag || (n == 1 && np == 1))) {
			// note: for n == 2, flag has to be on
			// cause, np should be equal to 2
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}
```
