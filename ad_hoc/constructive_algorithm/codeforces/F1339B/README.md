# Problem Description

### Problem: [Sorted Adjacent Differences](http://codeforces.com/contest/1339/problem/B)
### Contest: [Codeforces Round #633 (Div. 2)](http://codeforces.com/contest/1339/)
### Statement
You have array of *n* numbers *a<sub>1</sub>,a<sub>2</sub>,…,a<sub>n</sub>*.

Rearrange these numbers to satisfy *|a<sub>1</sub>−a<sub>2</sub>| ≤ |a<sub>2</sub>−a<sub>3</sub>| ≤…≤ |a<sub>n−1</sub>−a<sub>n</sub>|*, where |x| denotes absolute value of x. It's always possible to find such rearrangement.

Note that all numbers in *a* are not necessarily different. In other words, some numbers of *a* may be same.

You have to answer independent *t* test cases.

#### Constraints & Input
The first line contains a single integer *t (1 ≤ t ≤ 10<sup>4</sup>)* — the number of test cases.

The first line of each test case contains single integer *n (3 ≤ n ≤ 10<sup>5</sup>)* — the length of array *a*. It is guaranteed that the sum of values of *n* over all test cases in the input does not exceed 105.

The second line of each test case contains *n* integers *a<sub>1</sub>,a<sub>2</sub>,…,a<sub>n</sub> (−10<sup>9</sup>≤a<sub>i</sub> ≤ 10<sup>9</sup>)*.

#### Output
For each test case, print the rearranged version of array a which satisfies given condition. If there are multiple valid rearrangements, print any of them.

# Solution
First, sort the array in Ascending order.
Notice a statement on the problem:
> *It's always possible to find such rearrangement.*

So it has to work for any kind of input. To achieve this, we can take the middle index as *pivot* and take numbers from both side one by one *i.e:* take an index from left, then one from right, next from left and so on.

Choosing the *pivot*, we have to make sure it doesn't end with taking consequtive index from same side. This way, the adj difference is always greater or equal to previous one.
