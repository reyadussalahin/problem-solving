# Organization of solutions and learning materials
Solutions and learning materials have been organized in a careful manner. One must follow the directory hierarchy to contribute in this repo. Organization is pretty simple. The following figure will make it clear:  

<div style="text-align:center">
    <img src="resources/images/directory_hierarchy.png" alt="Project Structure"/>
</div>

### Structuring problem solutions
##### for ojs, those provide unique problem id
 - format: `{category_name}/{sub_category_name}/{oj_name}/{F+problem_id}/{Solution.ext}`  
 - example: `data_structure/segment_tree/codeforces/F558E/Solution.c`

##### for ojs, those provide unique name but does not provide unique problem id
 - format: `{category_name}/{sub_category_name}/{oj_name}/{F+problem_name}/{Solution.ext}`  
 - example: `data_structure/stack/hackerrank/FBalancedBrackets/Solution.c`

##### for contest like codejam, hackercup etc.
 - format: `{CONTEST}/{contest_name}/{Y+year}/{round_name}/{F+problem_name}/{Solution.ext}`  
 - example: `CONTEST/codejam/Y2019/round01A/FAlienRhyme/Solution.c`

##### for acm icpc world finals
 - format: `{CONTEST}/{world_final}/{Y+year}/{F+problem_name}/{Solution.ext}`  
 - example: `CONTEST/world_final/Y2017/FNeedForSpeed/Solution.c`

##### for acm icpc regionals
format: `{CONTEST}/{regional}/{Y+year}/{site}/{F+problem_name}/{Solution.ext}`  
example: `CONTEST/regional/Y2017/dhaka/FMegaMind/Solution.c`

##### for random contests
format: `{CONTEST}/{random_contest}/{Y+year}/{contest_name}/{F+problem_name}/{Solution.ext}`  
example: `CONTEST/random_contest/Y2019/practice_for_preli/FLifeOfPhi/Solution.c`

##### rules to add multiple solutions
If there are multiple solutions, then name the second solution file as Solution001.{ext} such as Solution001.c, and third solution file as Solution002.py and so on ...


### Structuring learning materials
To add editorials for your solved problem, add a README.md file in the folder where you've put your Solution.cpp file.  

[N.B.]:  
Currently, we are working on structuring contents for providing learning method in an easy manner. So, if you want to contribute, you may have to wait until decisions are made. But if very eager to contribute, contact [reyad](https://github.com/reyadussalahin).

<!-- 
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
1. To add images for better explanation, keep the images in: *"{category_name}/{resources}/{images}"* directory
2. For other resource categories use: *"{category_name}/{resources}/{resource_category_name}"* directory

### README in sub category
It should explain what the subcategory is. Let us assume segment tree:
1. What is segment tree, the theory behind it
2. Implementation details
3. How to use it to solve problems with examples
4. Modifications of segement tree like using Lazy propagations with examples
etc.

**N.B. :**
1. To add images for better explanation, keep the images in: *"{category_name}/{sub_category_name}/{resources}/{images}"* directory
2. For other resource categories use: *"{category_name}/{sub_category_name}/{resources}/{resource_category_name}"* directory

### README in solution folder
1. It should contain problem link
2. A short problem description(enough to understand the problem)
3. Explanation of the problem to gain insight how to solve the problem
4. Explanation of the solutions one by one

May be some much better way be found out later to explain things more easily. But in the mean time let's follow this procedure.

**N.B. :**
1. To add images for better explanation, keep the images in: *"{category_name}/{sub_category_name}/{oj_name}/{F+problem_id}/{resources}/{images}"* directory
2. For other resource categories use: *"{category_name}/{sub_category_name}/{oj_name}/{F+problem_id}/{resources}/{resource_category_name}"* directory
 -->

# How to write solutions, editorials and learning materials
Writing solutions and learning materials both are pretty easy. Both explained below in details.

### Writing Solutions
1. source file must contain a working solution
2. at top of the source file you should add the followings(you must add these as "comment"):
    - problem name (must)
    - problem link (must)
    - contest link (if exists otherwise put "(?)")
    - time (good if you add, otherwise put "(?)")
    - author (it's good to add author name)

3. below this you should two more things:
    - other_tags: a problem may have various ways to solve, you should add those other tags
    - difficulty_level: you should add one of the following (beginner, intermediate, expert, advanced)  

**Example:**

```c
// problem name: A Simple Task
// problem link: https://codeforces.com/contest/558/problem/E
// contest link: https://codeforces.com/contest/558
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: expert


#include <stdio.h>
#define N 100100


// put your code here
// ....
// ....

```

You can use templates, if you want. You may find the the solution templates [here](templates/SOLUTION_TEMPLATE.md).


### Writing Editorials
Writing editorials are easy as writing solutions. Just put a README.md file with your solution process in the folder where you've put Solution.cpp file. But, you must follow the rules for writing editorials. You've to add the followings to the editorial:
 1. problem link(must)
 2. contest link(if exists otherwise put "(?)")
 3. problem statement
 4. input constraint
 5. output constraint
 6. solution process(only theory, you must not provide any code)

It may seem complex, so we've provided a template for you. You may just copy-paste in proper formatting in that file. You may find the template [here](templates/EDITORIAL_TEMPLATE.md).


### Writing Learning Materials
Writing tutorial is as easy as writing in markdown.  

[N.B.]:  
Currently, we are working on structuring contents for providing learning method in an easy manner. So, if you want to contribute, you may have to wait. But if very eager to contribute, contact [reyad](https://github.com/reyadussalahin).


# Conventions used for Online Judge and Category Names
These conventions are accepted by everyone contributing and one must follow them properly.

### Convention for Online Judge Names
These are the short-codes for "oj_name" that has been (and will be) used to create directory
 - [Codeforces](https://codeforces.com): codeforces
 - [Codechef](https://www.codechef.com/): codechef
 - [Timus](http://acm.timus.ru/): timus
 - [UVa](https://onlinejudge.org/): uva
 - [Hackerrank](https://www.hackerrank.com/): hackerrank
 - [Hackerearth](https://www.hackerearth.com/): hackerearth
 - [Lightoj](http://lightoj.com/): loj
 - [SPOJ](https://www.spoj.com/): spoj
 - [Leetcode](https://leetcode.com): leetcode

### Conventions used for Category and Sub-Category Names
These are the short-codes for "category_name" and "sub_category_name" has been (and will be) used to create directory
 - ad_hoc
     - beginner
     - constructive_algorithms
     - implementation
 - brute_force
     - loop
     - recursion
     - backtracking
 - search
     - binary_search
     - ternary_search
 - sort
     - insertion_sort
     - merge_sort
     - quick_sort
 - math
     - basic
     - probability
     - big_integer
     - combinatorics
     - number_theory
 - dynamic_programming
     - coin_change
     - knapsack
     - lis
     - lcs
     - matrix_chain_mul
     - non_classical
 - greedy
     - basic
     - non_classical
 - data_structure
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
     - sssp
     - bipartite_matching
     - max_flow
 - string
     - basic
     - kmp
     - trie
 - computational_geometry
     - basic
     - convex_hull
     - picks_theorem
     - line_sweep
 - hackercup
 - codejam

##### Round names for codejam, hackercup etc
 - *Codejam* round name convention
     - qualification
     - round01A
     - round01B
     - round01C
     - round02
     - round03
 - *Hackercup* round name convention
     - qualification
     - round01
     - round02
     - round03

More new categories and sub-categories are being introduced regularly and will be added according to needs later.

# How to send pull request
There is a few rules about how to properly send pull requests to this repo, so that it may easier for us to handle your requests properly. For pull request guidelines, read [this guide](PULL_REQUEST.md).
