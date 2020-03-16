# Problem Description

### Problem: [Primitive Primes](https://codeforces.com/contest/1316/problem/C)
### Contest: [CodeCraft-20 (Div. 2)](https://codeforces.com/contest/1316)
### Statement
It is Professor R's last class of his teaching career. Every time Professor R taught a class, he gave a special problem for the students to solve. You being his favourite student, put your heart into solving it one last time.  

You are given two polynomials *f(x) = a<sub>0</sub> + a<sub>1</sub>x + ⋯ + a<sub>n−1</sub>x<sup>n−1</sup>*
and *g(x) = b<sub>0</sub> + b<sub>1</sub>x + ⋯ + b<sub>m−1</sub>x<sup>m−1</sup>*, with positive integral coefficients. It is guaranteed that the cumulative GCD of the coefficients is equal to 1 for both the given polynomials. In other words, *gcd(a<sub>0</sub>, a<sub>1</sub>, …, a<sub>n−1</sub>) = gcd(b<sub>0</sub>, b<sub>1</sub>, …, b<sub>m−1</sub>) = 1*. Let *h(x) = f(x)\*g(x)*. Suppose that *h(x) = c<sub>0</sub> + c<sub>1</sub>x + ⋯ + c<sub>n+m−2</sub>x<sup>n+m−2</sup>*.  

You are also given a prime number *p*. Professor R challenges you to find any *t* such that *c<sub>t</sub>* isn't divisible by *p*. He guarantees you that under these conditions such *t* always exists. If there are several such *t*, output any of them.  

As the input is quite large, please use fast input reading methods.
#### Input
The first line of the input contains three integers, *n*, *m* and *p* (1 ≤ n, m ≤ 10<sup>6</sup>, 2 ≤p ≤10<sup>9</sup>), — n and m are the number of terms in *f(x)* and *g(x)* respectively (one more than the degrees of the respective polynomials) and *p* is the given prime number.  

It is guaranteed that *p* is prime.  

The second line contains *n* integers *a<sub>0</sub>, a<sub>1</sub>, …, a<sub>n−1</sub> (1 ≤ a<sub>i</sub> ≤ 10<sup>9</sup>)* — *a<sub>i</sub>* is the coefficient of *x<sub>i</sub>* in *f(x)*.  

The third line contains *m* integers *b<sub>0</sub>, b<sub>1</sub>, …, b<sub>n−1</sub> (1 ≤ b<sub>i</sub> ≤ 10<sup>9</sup>)* — *b<sub>i</sub>* is the coefficient of *x<sub>i</sub>* in *g(x)*.  

# Solution
Let,  
*f(x) = a<sub>0</sub> + a<sub>1</sub>x + ⋯ + a<sub>n−1</sub>x<sup>n−1</sup>*  
*g(x) = b<sub>0</sub> + b<sub>1</sub>x + ⋯ + b<sub>m−1</sub>x<sup>m−1</sup>*  
*h(x) = c<sub>0</sub> + c<sub>1</sub>x + ⋯ + c<sub>n+m−2</sub>x<sup>n+m−2</sup>*  

Then we may say that,  
*c<sub>0</sub> = a<sub>0</sub> \* b<sub>0</sub>*  
*c<sub>1</sub> = a<sub>0</sub> \* b<sub>1</sub> + a<sub>1</sub> \* b<sub>0</sub>*  
*c<sub>2</sub> = a<sub>0</sub> \* b<sub>2</sub> + a<sub>1</sub> \* b<sub>1</sub> + a<sub>2</sub> \* b<sub>0</sub>*  
...  
...  
...  
...  
*c<sub>n+m-2</sub> = a<sub>n-1</sub> \* b<sub>m-1</sub>*  


It is given that, *p* is a prime.  

Let us try to check one by one that if p may divide c<sub>0</sub>, c<sub>1</sub>, c<sub>2</sub>, ...etc  

Now, if p \| c<sub>0</sub>, then we may say, either p \| a<sub>0</sub> or p \| b<sub>0</sub> (but if in case, if p does not divide c<sub>0</sub>, then t=0 is the ans).  

For the sake of dicussion, let us assume that p \| a<sub>0</sub> and p may or may not divide b<sub>0</sub>, so t=0 is not the answer.  

Now, let's check for, t=1  
We know that, c<sub>1</sub> = a<sub>0</sub> \* b<sub>1</sub> + a<sub>1</sub> \* b<sub>0</sub>  
So, p \| c<sub>1</sub> if either p \| a<sub>1</sub> or p \| b<sub>0</sub> [cause, p \| a<sub>0</sub>]  

Again for the sake of discussion let's assume p \| b<sub>0</sub>  
so, for c<sub>2</sub> we have to check,  
either p \| a<sub>1</sub> or p \| b<sub>1</sub>  
...  
...  
I hope you can see, where this process is going. If there is a pair a<sub>x</sub> \* b<sub>y</sub> such that, p does not divide both of a<sub>x</sub> \* b<sub>y</sub>, then the co-efficient c<sub>t</sub> which include these two terms won't be divisible by *p*.  

Now, its been said that, gcd(a<sub>0</sub>, a<sub>1</sub>, …, a<sub>n−1</sub>) = gcd(b<sub>0</sub>, b<sub>1</sub>, …, b<sub>m−1</sub>) = 1. So, there is at least one a<sub>i</sub>(where, 1 <= i <= n) and at least one b<sub>j</sub>(where, 1 <= j <= m) such that, *p* does not divide them.  

Let's find *t* for a<sub>x</sub>b<sub>y</sub>  
assume, c<sub>t</sub> = a<sub>0</sub>b<sub>t</sub> + ... + a<sub>x</sub>b<sub>y</sub> + ... + a<sub>t</sub>b<sub>0</sub>  
```
so, we may say, x-0 = t-y
or, t = x+y
```

Solution is given [here](Solution.py).