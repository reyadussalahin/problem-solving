# Minimum Spanning Tree (Prims)
 
## Solution :
 The problem requires simple solution involving *Minimum Spanning tree*.

 First we have to elimintate any edge(road) between two areas(nodes) that has cost >= cost building an airport. Because for every road with higher cost, we can build an extra airport for the disjoint graph (if resulted for removing the edge) and get minimal total cost with more airports.

 With the updated edges, find MST for every disjoint graph and allocate an airport. The sum of all MST costs and cost aiports (one for each) is optimal answer.
 
## Complexity : 
 I implemented Prim's MST with Adjacency list for which worst time complexity is *(ElogE)*. MST can be implemented in *(ElogV)* using decrease_key operation on Heap. C++ STL priority_queue doesn't support decrease_key.
