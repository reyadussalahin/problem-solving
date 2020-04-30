# Problem Description

### Problem: [1106 - Gone Fishing](http://lightoj.com/volume_showproblem.php?problem=1106)
### Statement
[Go here](http://lightoj.com/volume_showproblem.php?problem=1106)
## Solution
Can be done with a *Dynamic Programming* solution. Taking the **current lake position** and remaining **time** to be spent as two **states** of **DP**. 
Then we can solve the problem *Recursively* or *Iteratively* (hell no!!).
For every state regarding **i-th** lake and **t** time; the optimal number is determined by the recursive formula:

![DP_{i,t}\ =\ \max_{k=1}^{t}\ (\ g_{i,k}\ +\ DP_{i,t-k-travel\_time}\ )](http://www.sciweavers.org/download/Tex2Img_1588278086.jpg)

Where,
* *DP<sub>i,t</sub>* denotes  -  *maximum number of fish caught arriving **ith** lake with **t** time remaining*
* *g<sub>i,k</sub>* denotes  -  *number of fish to be caught at **i-th** lake given **k** time*

Applying some math simplification, we can get:

![g_{i,k}\ =\ k*f_{i}\ -\ b_{i}*\frac{(k-1)*k}{2}](http://www.sciweavers.org/download/Tex2Img_1588277979.jpg)
Where,
* *f<sub>i</sub>* - number of fish expected in initial 5 mins

* *d<sub>i</sub>* - reduction in every 5 mins

