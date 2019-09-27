# Problem Description

### Problem: [Ne-Zu-Ko Chaaaaaaaaaaaaan!](https://toph.co/p/ne-zu-ko-chaaaaaaaaaaaaan)
### Contest: [Practice Contest for the 2019 ICPC Asia Regional Dhaka Site Preliminary | Toph](https://toph.co/c/practice-icpc-2019-dhaka)
### Statement
Tanjiro and his sister Nezuko live in a village that is shaped like a circle with a radius R. There’s also a crazy boy Zenitsu who loves Nezuko but he is so annoying that Tanjiro doesn’t want him anywhere near his sister Nezuko, the cutest of all. So, he gives punishment to Zenitsu.

Zenitsu must start running from a point on the circle boundary to some inward direction. He runs in a straight line. Whenever he reaches a point on the boundary of the circle (say such a point is A), his direction is reflected with respect to the line connecting A and the centre of the circle. And he starts running again. He only stops running when he reaches the point from which he started running initially.

Tanjiro wants Zenitsu to run in such a way that before he stops running, his direction is reflected exactly N times. Besides, Tanjiro wants Zenitsu to get as much tired as it’s possible. So, Zenitsu has to choose the longest possible route where his direction reflects exactly N times before he stops running.

While running, Zenitsu keeps screaming “Ne-Zu-Ko chaaaaaaaaaaan” on top of his voice to express his love.

Can you help Zenitsu determine how much distance he has to cover?

### Input
There will be several test cases.

In the first line, there will be an integer T (1 ≤ T ≤ 104), the number of test cases.

Each of the next T lines will contain two integers N (1 ≤ N ≤ 2 * 105) and R (1 ≤ R ≤ 103), the number of times Zenitsu’s direction will reflect and the radius of the village, respectively.

### Output
For each test case, output the distance of the longest route Zenitsu can take. The output should be rounded to 4 digits after the decimal.

# Solution
*The problem statement is weak. Lets denote start point and end point as x(as both are same). The problem statement does not clearly say that - in the middle of the race, can zenitsu use point x or he can not use...The truth is Zenitsu can't use point x(i.e. the start point) in the middle of the race(for reflection)...*

#### Finding angular distance for reflection
Consider, a chord in a circle, which produces an circle angle of 'b' (0 <= b <= 180)
Lets say zenitsu is running through the chord.
```
Then, we can say for first reflection, it would cross 2b angular distance
and for second reflection 3b
and for nth, it would be (n+1)b
```

#### Angular distance should be multiple of 360
Condition is, Zenitsu has to return to its original position.
```
So, we may say that, 360 | (n+1)b
i.e. 360 divides (n+1)b
or, (n+1)b = c * 360 where c = 0, 1, 2, 3,....
```

#### Condition for 'c'(Zenitsu can't use the start point for reflection)
Again there is a condition zenitsu can't use the start point for reflection in the middle of the race. He can only use it for start and end.
```
So,  i*b can't be divided by 360 where i = 1...n(i.e. 1<=i<=n)
```

```
We know, (n+1)b = c*360
lets assume, gcd(n+1, c) = p
then, ((n+1) / p)b = (c / p)*360
or mb = d*360
where m, d, p are integers
So, we may say there's such p such that n+1 = m*p and c = d*p
Here, m and d just breaks the condition stated above
But if gcd(n+1, c) = 1, then p = 1 and n+1 = m and c = d
So, c should be such that gcd(n+1, c) = 1, which holds the condition
```

#### Determining 'b'
```
Now, (n+1)b = c*360
so, b = c*360 / (n+1)
```

#### Determining 'c'
Let's find 'c'

```
as stated above 0<=b<=180
to cover the maximum distance c has to be as maximum as possible
so, by replacing b with 180
(n+1)*180 = c*360
or, c = (n+1)/2
as, c is an integer, it would be an integer division
```
```
As previously stated gcd(n+1, c) should be 1
And we know that between 1 to 10^9 the maximum known prime gap is 222
So, we may test gcd(n+1, c) by decreasing c until find desired result
```

#### Finding chord length
```
chord_length = 2*r*sin(b/2) (simple circle geometry)
```

#### Maximum path
```
The maximum path would be = (n+1) * chord_length
```