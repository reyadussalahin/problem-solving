# Problem Description

### Problem: [Ehab the Xorcist](https://codeforces.com/contest/1325/problem/D)
### Contest: [Codeforces Round #628 (Div. 2)](https://codeforces.com/contest/1325)
### Statement
Given 2 integers *u* and *v*, find the shortest array such that [bitwise-xor](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of its elements is *u*, and the sum of its elements is *v*.

#### Input
The only line contains 2 integers *u* and *v* (0 ≤ *u,v* ≤ 10<sup>18</sup>).

#### Output
If there's no array that satisfies the condition, print "-1". Otherwise:  
The first line should contain one integer, *n*, representing the length of the desired array. The next line should contain *n* positive integers, the array itself. If there are multiple possible answers, print any.

# Solution
The path to solution of this problem can be broken down into several steps:  
1. The first point to realize, the answer can be formed in four different ways.
	- First case, if *u* equals *v*.
	- Second case, *u = x ^ y* (where *x* and *y* two random numbers and *x+y = v*). Let's denote *u<sub>i</sub>* as the *i<sub>th</sub>* bit of *u*, then *u<sub>i</sub> = x<sub>i</sub> ^ y<sub>i</sub>*. Now, if *u<sub>i</sub>* is set, then *(x<sub>i</sub>, y<sub>i</sub>) = (0, 1)* or *(x<sub>i</sub>, y<sub>i</sub>) = (1, 0)*. But, if *u<sub>i</sub>* is unset then, *(x<sub>i</sub>, y<sub>i</sub>) = (1, 1)* or *(x<sub>i</sub>, y<sub>i</sub>) = (0, 0)*. So, if *u* has a set bit, it can be said that, one of *x* or *y* has to have a set bit and the remaining other has to have a unset bit. For ease of discussion let's assume, *x* has all set bits, where *u* has set bits and *y* has all unset bits, where *u* has set bits, i.e. *x<sub>i</sub> = 1* and *y<sub>i</sub> = 0* for all *u<sub>i</sub> = 1*. Then, it can be said that, *x = u + z*, where *z* and *u* have no common set bits. So, *u = (u + z) ^ y*. And again, as *u* and *z* does not share any set bit, then *z ^ y* must be *0*. Otherwise, *(u + z) ^ y = u* is not possible. So, it must be true that, *z ^ y = 0* or, *z = y*. Therefore, *u = (u + y) ^ y* and *u+y+y = v(as, x+y = v)*.
	- Third case, *u = u ^ y ^ y* (where, *u+y+y = v*, and *u* and *y* have at least one common set bit).
	- Fourth case occurs, when *u* consists of more than three elements. But, we are going to show that, *u* can have atmost 3 elements. Let's first prove that, the least sigficant bit(*lsb*) of *u* and *v* have to be same. For proof, let's assume, *lsb* of *u* is *1*, then there should odd number elements which have their *lsb* set, but we also know that, the sum of odd number of *1's* is *1* **(note: we are discussing the position of lsb)**. So, the *lsb* of *v* must has to be set, if *u's* *lsb* is set. In same manner, we may also show that, if *u's* *lsb* is unset, then *v's* *lsb* must be unset**(proved)**. So, *v - u* must have to be an even number. Let's assume, *v - u = y + y*(where, *y* is a positive integer). Or, *v = u + y + y*. Now, if *u* and *y* share at least one common set bit, then this would be **third case** else, it would be the **second case**. So, it's not possible to have more than three elements**(showed)**.
2. The second point is to realize, where it won't give any answer. Firstly, if *u > v*(do it yourself, pretty easy). Secondly, if the *lsb(u) != lsb(v)*(it's already been proved above).  

Solution is given [here](Solution.py).