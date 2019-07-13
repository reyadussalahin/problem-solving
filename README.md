# What is this repository about
This repository is created to organize the solutions of problems related to data structures and algorithms. And if possible, provide
an easier way to learn problem solutions as well as the concepts of data structures and algorithms.


# Languages used for solution
- C
- C++
- Java
- Python
- JavaScript(nodejs)


# How to structure the problem solutions
### For ojs, those provide unique problem id
**Format: {category_name}/{sub_category_name}/{oj_name}/{F+problem_id}/{Solution.ext}**  
Example:  
- C: data_structure/segment_tree/codeforces/F558E/Solution.c
- CPP: data_structure/segment_tree/codeforces/F558E/Solution.cpp
- Java: data_structure/segment_tree/codeforces/F558E/Solution.java
- Python: data_structure/segment_tree/codeforces/F558E/Solution.py
### For ojs, those provide unique name
**Format: {category_name}/{sub_category_name}/{oj_name}/{F+problem_name}/{Solution.ext}**  
Example:  
- C: data_structure/stack/hackerrank/FBalancedBrackets/Solution.c
- CPP: data_structure/stack/hackerrank/FBalancedBrackets/Solution.cpp
- Java: data_structure/stack/hackerrank/FBalancedBrackets/Solution.java
- Python: data_structure/stack/hackerrank/FBalancedBrackets/Solution.py
### For contest like codejam, hackercup etc.
**Format: {contest_name}/{Y+year}/{round_name}/{F+problem_name}/{Solution.ext}**  
Example:  
- C: codejam/Y2019/round01A/FAlienRhyme/Solution.c
- CPP: codejam/Y2019/round01A/FAlienRhyme/Solution.cpp
- Java: codejam/Y2019/round01A/FAlienRhyme/Solution.java
- Python: codejam/Y2019/round01A/FAlienRhyme/Solution.py
### For multiple solutions
If there are multiple solutions, then name the second solution file as Solution001.{ext} such as Solution001.c,
and third solution file as Solution002.c and so on ...


# What the source file should contain
1. Source file must contain a working solution
2. At top of the source file add(you must add this in "comment"):
    - problem link (must)
    - contest link (if exists)
    - author name  (it's good to add author name)
    - time         (not mandatory)  
Example:  
```
// problem: https://codeforces.com/contest/558/problem/E
// contest: https://codeforces.com/contest/558
// author: reyad
#include <stdio.h>
#define N 100100
....
```


# How to provide a way for easy learning
1. Add a README.md file in the category folder to explain the category
2. Add a README.md file in the sub category folder to explain the sub category
3. Add a README.md file in the solution folder to explain the solutions
### README in category
It should explain what the category. Let us take data structure as an example. We should try to explain:
1. What is data structure
2. Why it is needed
3. Some examples of data structures
4. Some use case of data structures
etc.

**N.B. :**
1. To add images for better explanation, keep the images in:
 - {category_name}/{resources}/{images} directory
2. For other resource categories use:
 - {category_name}/{resources}/{resource_category_name} directory

### README in sub category
It should explain what the subcategory is. Let us assume segment tree:
1. What is segment tree, the theory behind it
2. Implementation details
3. How to use it to solve problems with examples
4. Modifications of segement tree like using Lazy propagations with examples
etc.

**N.B. :**
1. To add images for better explanation, keep the images in:
 - {category_name}/{sub_category_name}/{resources}/{images} directory
2. For other resource categories use:
 - {category_name}/{sub_category_name}/{resources}/{resource_category_name} directory

### README in solution folder
1. It should contain problem link
2. A short problem description(enough to understand the problem)
3. Explanation of the problem to gain insight how to solve the problem
4. Explanation of the solutions one by one

May be some much better way be found out later to explain things more easily. But in the mean time let's follow this procedure.

**N.B. :**
1. To add images for better explanation, keep the images in:
 - {category_name}/{sub_category_name}/{oj_name}/{F+problem_id}/{resources}/{images} directory
2. For other resource categories use:
 - {category_name}/{sub_category_name}/{oj_name}/{F+problem_id}/{resources}/{resource_category_name} directory


# OJ list:
Here oj_name has been used to create directory
- [Codeforces:](https://codeforces.com)
    - oj_name: codeforces
- [Codechef:](https://www.codechef.com/)
    - oj_name: codechef
- [Timus:](http://acm.timus.ru/)
    - oj_name: timus
- [UVa:](https://uva.onlinejudge.org/)
    - oj_name: uva
- [Hackerrank:](https://www.hackerrank.com/)
    - oj_name: hackerrank
- [Hackerearth:](https://www.hackerearth.com/)
    - oj_name: hackerearth
- [Lightoj:](http://lightoj.com/)
    - oj_name: loj
- [SPOJ:](https://www.spoj.com/)
    - oj_name: spoj


# Category and Sub-Category list
Here category_name and sub_category_name has been used to create directory
- complete_search:
    - loop
    - recursion
- binary_search:
- math:
    - ad_hoc
    - probability
    - big_integer
    - combinatorics
    - number_theory
- dynamic_programming:
    - coin_change
    - knapsack
    - lis
    - lcs
    - matrix_chain_mul
    - random
- greedy:
- data_structure:
    - array
    - list
    - stack
    - queue
    - heap
    - segment_tree
    - sqrt_decomposition
    - treap
- graph
    - bfs
    - dfs
    - scc
    - articulation_point
    - articulation_bridge
- string
- computational_geometry
- hackercup
- codejam

#### Round names for codejam, hackercup etc
- Codejam round name convention:
    - qualification
    - round01A
    - round01B
    - round01C
    - round02
    - round03
- Hackercup round name convention:
    - qualification
    - round01
    - round02
    - round03

More categories and sub categories will be added with time


**Any one is welcome to contribute!!!**

