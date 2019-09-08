// problem name: Efficient Traffic System
// problem link: http://lightoj.com/volume_showproblem.php?problem=1210
// contest link: (?)
// time: (?)
// author: reyad

#include<stdio.h>
#define INF 1111111111
 
int min(int a, int b) { return (a<b) ? a:b; }
 
typedef struct { int x, next; } Edge;
Edge edges[50000];
int list[20000], ec;
void add_edge(int u, int v) {
    edges[ec].x = v;
    edges[ec].next = list[u];
    list[u] = ec++;
}
 
int visited[20000], stack[20000], startTime[20000], inPath[20000];
int top, timer, nscc;
int component[20000];
int dfs(int s) {
    int ast, ei;
    if(visited[s]) {
        if(inPath[s]) return startTime[s];
        return INF;
    }
    visited[s] = 1;
    stack[top++] = s;
    ast = startTime[s] = timer++;
    ei = list[s];
    while(ei != -1) {
        ast = min(ast, dfs(edges[ei].x));
        ei = edges[ei].next;
    }
    if(ast == startTime[s]) {
        do {
            inPath[stack[--top]] = 0;
            component[stack[top]] = nscc;
        } while(stack[top] != s);
        ++nscc;
    }
    return ast;
}
int main() {
    int ans, cc, tc, n, m, i, j, u, v, ni, no, ei;
    int indegree[20000], outdegree[20000];
    scanf("%d", &tc);
    for(cc=0; cc<tc; cc++) {
        scanf("%d %d", &n, &m);
        for(i=0; i<n; i++) {
            list[i] = -1;
            visited[i] = 0;
            inPath[i] = 1;
            indegree[i] = 0;
            outdegree[i] = 0;
        }
        ec = 0;
        for(i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            add_edge(u-1, v-1);
        }
        top = timer = nscc = 0;
        for(i=0; i<n; i++) {
            if(!visited[i]) dfs(i);
        }
        for(i=0; i<n; i++) {
            ei = list[i];
            while(ei != -1) {
                if(component[i] != component[edges[ei].x]) {
                    outdegree[component[i]]++;
                    indegree[component[edges[ei].x]]++;
                }
                ei = edges[ei].next;
            }
        }
        ni = no = 0;
        for(i=0; i<nscc; i++) {
            if(indegree[i] == 0) ni++;
            if(outdegree[i] == 0) no++;
        }
        ans = (ni>no ? ni:no);
        if(nscc == 1) ans = 0;
        printf("Case %d: %d\n", cc+1, ans);
    }
    return 0;
}
