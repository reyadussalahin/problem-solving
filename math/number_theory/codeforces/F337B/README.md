# Problem Description
### Problem: [Routine Problem](https://codeforces.com/problemset/problem/337/B)

### Contest: [Codeforces Round #196 (Div. 2)](https://codeforces.com/contest/337)

### Statement
Manao has a monitor. The screen of the monitor has horizontal to vertical length ratio a:b. Now he is going to watch a movie. The movie's frame has horizontal to vertical length ratio c:d. Manao adjusts the view in such a way that the movie preserves the original frame ratio, but also occupies as much space on the screen as possible and fits within it completely. Thus, he may have to zoom the movie in or out, but Manao will always change the frame proportionally in both dimensions.  
Calculate the ratio of empty screen (the part of the screen not occupied by the movie) to the total screen size. Print the answer as an irreducible fraction p/q.

#### Constraints
```
1 <= a, b, c, d <= 1000
```
#### Input
A single line contains four space-separated integers a, b, c, d

#### Output
Print the answer to the problem as "p/q", where p is a non-negative integer, q is a positive integer and numbers p and q don't have a common divisor larger than 1


# Solution
To occupy the most out of the screen, we have to fit the image either with the horizontal line or vertical line of the screen. Now, the task is to determine with which side we have to fit the image. This can be easily determine by calcualting h/v(here, h = horizontal_length, and v = vertical length) of both screen and image and then by comparing them.  
Let's say (h/v) of image is greater than (h/v) of screen. Then, we've to fit the horizontal side of image with horizontal side of screen(because image's per unit of growth in vertical line results in a larger growth in horizontal line than screen). Otherwise, we would fit the vertical side.  

```
Let us assume, one unit in image is represented by 'i', and one unit of screen is represented by 's'.
A, B, C, D = a, b, c, d(capital letter is used for clarification)

1. Case 01: Fit horizontal line
Ci = As
or i = (A / C) s
or Di = (D * A / C) s

So, occupied_area = Ci * Di = As * (D * A / C)s (substituting value)
Then, unoccupied_area = As * Bs - occupied_area
or, unoccupied_area = (A * (B * C - D * A)) / C (written without unit)

So, the_ratio = unoccupied_area / total_area
or, the_ratio = (B * C - D * A) / (B * C)

2. Case 02: Fit verical line
Just calculate as done in Case 01, but for vertical line
the ratio would be (D * A - B * C) / (D * A)
```

