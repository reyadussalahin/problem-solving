## Solutions
#### 1
##### Source Code
```c++
// problem name: Problem Makes Problem
// problem link: http://lightoj.com/volume_showproblem.php?problem=1102
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: expert


#include <bits/stdc++.h>

using namespace std;


#define M 1000000007
#define N 2000000


long long f[N+10];

long long modpow(long long b, long long pw, long long mod) {
    if(pw == 0) {
        return 1;
    }
    long long x = modpow(b, pw/2, mod);
    x = (x * x) % mod;
    if(pw&1) x = (x * b) % mod;
    return x;
}

long long modinv(long long a, long long b, long long mod) {
    return (a * modpow(b, mod-2, mod)) % mod;
}

int main() {
    f[0] = 1;
    for(int i=1; i<=N; i++) {
        f[i] = (f[i-1] * i) % M;
    }

    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("Case %d: %lld\n", cc+1, modinv(f[n+k-1], (f[n] * f[k-1]) % M, M));
    }
    return 0;
}

```
