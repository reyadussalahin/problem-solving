# Problem Description

### Problem: [Life of Phi](https://toph.co/p/life-of-phi)
### Contest: [Practice Contest for the 2019 ICPC Asia Regional Dhaka Site Preliminary | Toph](https://toph.co/c/practice-icpc-2019-dhaka)
### Statement
The Great Khami is learning Number Theory. He is very excited to know that Euler’s Totient Function is very useful in Cryptography. Euler’s Totient function, also known as the Phi function is defined over all positive integers. For each input value n, the function returns the number of co-primes with n that are less than n. Two numbers are said to be co-primes if their greatest common divisor is 1. Khami started exploring different properties of Euler’s Totient function. He became fascinated with one property of this function, it states:

Phi( N * M ) = Phi( N ) * Phi( M ), where N and M are co-primes.

Excited by this property, Khami went on to prove it. But it turned out that the proof itself is a demanding problem. It requires some fundamentals of number theory along with a complicated theorem called the Chinese Remainder Theorem or CRT.

Khami’s expedition continued as he mastered CRT and finally managed to prove the multiplicative property of Phi function. Desperate to show off his skills, he challenged others with the following problem:

”““For any integer N, find the sum of the numbers x from 1 to N-1, where the GCD of x and N, denoted as (x,n) is greater than 1. “””

### Input
The first line of the input contains T (<=1000000), the number of test cases. The next T lines have one number, each positive and within the range of 1000000.

### Output
For each test case, print the answer on a line by itself.


# Solution
So, solve this problem, one has know about Euler's Totient function. It is used to find the number of coprimes of a number n(Search google you'll find a lot of topics about it and how to implement it).

Let's say *phi(n)* denotes the number of coprimes of a number n.
Then, we can find the sum of all coprimes of n by using the following formula:
```
sum of all coprimes of n, s(n) = n * phi(n) / 2
```
The proof of the above formula can be found in this [link](https://math.stackexchange.com/questions/569210/sum-of-all-coprimes-of-a-number)
```
Let us assume sum(n)  = 1 + 2 + 3 + ... + n
```
But we are told to find sum of numbers which less than n and are not coprimes
```
So, the answer would be = sum(n-1) - s(n)
```