## Solutions
#### 1
##### Source Code
```c++
// problem name: New Year and the Permutation Concatenation
// problem link: https://codeforces.com/contest/1091/problem/D
// contest link: https://codeforces.com/contest/1091
// time: (?)
// author: reyad


// other_tags: dynamic programming
// difficulty_level: beginner

/**
 * Solution idea:
 * 1 2 3 4 -> 3
 * 1 2 4 3 -> 2
 * 1 3 2 4 -> 3
 * 1 3 4 2 -> 2
 * 1 4 2 3 -> 3
 * 1 4 3 2 -> 1
 * 2 1 3 4 -> 3
 * 2 1 4 3 -> 2
 * 2 3 1 4 -> 3
 * 2 3 4 1 -> 3
 * 2 4 1 3 -> 2
 * 2 4 3 1 -> 1
 * ...
 * ...
 *
 *
 * answer must be formed of an subarray which contains all the elements from 1, 2, ..., n
 * Observation says, there are two ways to form an answer
 * 1. each individual row (such as just the second row: `1 2 4 3`)
 * 2. start with ith position in xth row and expand to (i-1)th element of (x+1)th row
 *    (such as the second to third row, starting from 2: `2 4 3 1`)
 * 
 * (Also observation says)
 * check 1st and 2nd row closely, and check the position where it mismatches:
 * 1 2 3 4 (check the 3rd position, it gives 3)
 * 1 2 4 3 (check the 3rd position, it gives 4)
 * So, the first row will give `3` subarray which's sum = (n * (n+1)) / 2
 * check 2nd and 3rd array, and check the position where it mismatches:
 * 1 2 4 3 (check the 2nd position, it gives 2)
 * 1 3 2 4 (check the 2nd position, it gives 3)
 * So, 2nd row will give `2` subarray which's sum will be (n * (n+1)) / 2
 *
 * and so on...
 *
 * Now, observe the count of results(subarray those give sum (n * (n+1))/2) of each row
 * 1. `1` will appear [`n`] times i.e. `4` times in the example
 * 2. `2` will appear [`n * (n-1)` - no of times `1` appear] = n * (n-1) - n = `8` times
 * 3. `3` will appear [`n * (n-1) * (n-2)` - no of times `1` and `2` appear] = n * (n-1) * (n-2) - [n + (n * (n-1) - n)] = `12` times
 * 4. ans so on ...(if `n` is greater than `4` of course..., the example is only for `n=4`, so its stops at `step 3`)
 */

/**
 * To calculate answer:
 * let,
 * number of changes in 1st position is c_1 = n
 * number of changes in 2nd position is c_2 = n * (n-1) - c_1
 * number of changes in 3rd position is c_3 = n * (n-1) * (n-2) - (c_1 + c_2)
 * ...
 * ...
 * number of changes in rth position is c_r = n * (n-1) * ... * (n-(r-1)) - (c_1 + c_2 + ... + c_(r-1))
 *                                          = nPr - (c_1 + c_2 + ... + c_(r-1))
 *
 * so, the ans will be:
 * ans = 1 * c_1 + 2 * c_2 + 3 * c_3 + ... + (n-1) * c_(n-1)
 */


#include <bits/stdc++.h>

using namespace std;

#define M 998244353


int main() {
    long long n;
    scanf("%lld", &n);
    if(n == 1) {
        printf("1\n");
        return 0;
    }
    long long sum_of_c_rs = 0;
    long long nPr = 1;
    long long ans = 0;
    for(int r=1; r<n; r++) {
        nPr = (nPr * (n-(r-1))) % M;
        long long c_r = (nPr - sum_of_c_rs + M) % M;
        ans = (ans + (c_r * r) % M) % M;
        sum_of_c_rs = (sum_of_c_rs + c_r) % M;
    }
    printf("%lld\n", ans);
    return 0;
}

```
