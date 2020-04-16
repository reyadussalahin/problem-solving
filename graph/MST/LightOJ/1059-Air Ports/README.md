# Minimum Spanning Tree (Prims)

## Problem Link :
[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1059)

## Solution :
 The problem requires simple solution involving *Minimum Spanning tree*.

 First, we have to elimintate any edge(road) between two areas(nodes) that has cost >= cost building an airport. Because for every road with higher cost, we can build an extra airport for the disjoint graph (if resulted for removing the edge) and get minimal total cost with more airports.

 With the updated edges, find MST for every disjoint graph and allocate an airport for each spanning tree. The sum of all MST and airports cost the is optimal answer.
 
## Complexity : 
 I implemented Prim's MST with Adjacency list for which worst-case complexity is *O(ElogE)*. MST can be implemented in *O(ElogV)* using decrease_key operation on Heap. C++ STL priority_queue doesn't support decrease_key. Have to implement heap manually for this performance which may be significant for large number of edges. 
