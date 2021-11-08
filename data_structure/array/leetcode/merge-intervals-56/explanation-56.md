Algorithm:
--------

1. sort the intervals by their starting points.
2. we take the *first interval(at index 0)* and store it to **tmpInterval**
3. then inside a loop,staring at index 1,
   tmpInterval: (1,3)  and curr(i) : (2,6)
   If tmpInterval's ending time >= (i) starting time    -> Overlap detected
4. As long as they overlap and as intervals are sorted,just **update maximum Ending index**. of our **tmpInterval**.
5. Once we find a non overlapping interval, we can add
   the **tmpInterval** to result and start next iteration.
6. Finally we merge our last interval.

Sorting takes O(n log(n)) and merging the intervals takes O(n).
So, Time Complexity : **O(n log(n))**