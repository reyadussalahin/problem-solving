# A Deep Dive into Computing Binomial Coefficient

<div style="text-align:center"><img src="images/1.png" /></div>

### Calculate nCr where n*r<=10^7

The key idea to calculate the value nCr for this case is the properties of pascal's triangle. We are all familiar with the following formula:

<div style="text-align:center"><img src="images/2.png" /></div>

Let's take a look at the below pascal's triangle (bad looking one!), and figure out how the values of the triangle justify  the equation. In the below triangle, value at x'th row and y'th column represent the value of xCy.

<div style="text-align:center"><img src="images/3.png" /></div>

> The advantage with this formula is you can modulo ans with any number even though the number isn’t prime. ( n C r % P)

Solution:

- Iterative: **faster**
 
```c
#include <bits/stdc++.h>
using namespace std;

#define maxn 50
#define maxr 40
long long C[maxn + 2][maxr + 2];

void triangle ()
{
  C[0][0] = 1;
  for (int i = 1; i <= maxn + 1; i++)
    {
        for (int j = 1; j <= i && j <= maxr + 1; j++)
    	{
	        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);	// to perform mod operation: (C[i-1][j-1]+C[i-1][j])%P;
	    }
    }
}

long long nCr (long long n, long long r)
{
  if (r > n)
    return 0;
  if (r == n || r == 0)
    return 1;
  return C[n + 1][r + 1];
}

int main ()
{

  triangle ();
  cout << nCr (50, 33) << endl;

  return 0;
}
```
- 