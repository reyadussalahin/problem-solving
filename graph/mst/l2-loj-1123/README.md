## Solutions
#### 1
##### Source Code
```java
// problem_name: Trail Maintenance 
// problem_link: http://lightoj.com/volume_showproblem.php?problem=1123
// contest_link: (?)
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: medium


import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.PrintWriter;
 
import java.io.IOException;
 
import java.util.Collections;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
 
public class Solution {
    static Reader in;
    static PrintWriter out;
   
    static class Edge implements Comparable<Edge> {
        int u, v, w;
        Edge(int u, int v, int w) { this.u = u; this.v = v; this.w = w; }
        public int compareTo(Edge e) { return this.w - e.w; }
    }
    static int[] p = new int[200];
    static int find(int i) { return (i == p[i]) ? i:(p[i] = find(p[i])); }
 
    static int n, cost;
    static int[][] adj = new int[200][200];
    static boolean[] visited = new boolean[200];
    static List<Edge> path = new ArrayList<>();
    static boolean dfs(int s, int e) {
        if(visited[s])  return false;
        visited[s] = true;
        if(s == e)  return true;
        for(int i=0; i<n; i++) {
            if(adj[s][i] != 0)  {
                if(dfs(i, e))   {
                    path.add(new Edge(s, i, adj[s][i]));
                    return true;
                }
            }
        }
        return false;
    }
    static void fix(int u, int v, int w) {
        for(int i=0; i<n; i++)  visited[i] = false;
        path.clear();
        dfs(u, v);
        Edge max = null;
        for(Edge e: path) {
            if(max == null) max = e;
            else {
                if(e.w > max.w) max = e;
            }
        }
        if(max.w <= w)  return;
        cost = cost + w - adj[max.u][max.v];
        adj[max.u][max.v] = 0;
        adj[max.v][max.u] = 0;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    static void solve() throws IOException {
        int cc, tc, ne;
        int i, j, m, u, v, w;
 
        tc = in.nextInt();
        for(cc=0; cc<tc; cc++) {
            ne = 0;
            cost = 0;
            n = in.nextInt();
            m = in.nextInt();
            for(i=0; i<n; i++) {
                p[i] = i;
                for(j=0; j<n; j++)  adj[i][j] = 0;
            }
            out.println("Case " + (cc+1) +":");
            for(i=0; i<m; i++) {
                u = in.nextInt()-1;
                v = in.nextInt()-1;
                w = in.nextInt();
                if(find(u) != find(v)) {
                    p[find(u)] = find(v);
                    ne++;
                    cost += w;
                    adj[u][v] = w;
                    adj[v][u] = w;
                }
                else {
                    fix(u, v, w);
                }
                if(ne == n-1) out.println(cost);
                else out.println(-1);
            }
        }
    }
    public static void main(String[] args) {   
        try {
            OutputStreamWriter osw = new OutputStreamWriter(System.out);
            BufferedWriter bw = new BufferedWriter(osw);
            in = new Reader();
            out = new PrintWriter(bw);
 
            solve();
 
            in.close();
            out.close();
            bw.close();
            osw.close();
        }
        catch(IOException e) {
            e.printStackTrace();
        }
    }
    static class Reader {
        InputStreamReader isr;
        BufferedReader br;
        StringTokenizer tk;
        String str;
        Reader() {
            br = new BufferedReader((isr = new InputStreamReader(System.in)));
            tk = new StringTokenizer("");
        }
        String nextLine() throws IOException {
            while(((str = br.readLine()) != null) && (str.length() == 0));
            return str;
        }
        String next() throws IOException {
            if(!tk.hasMoreTokens()) {
                if(nextLine() == null)  return null;
                tk = new StringTokenizer(str);
            }
            return tk.nextToken();
        }
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        void flush() {
            tk = new StringTokenizer("");
        }
        void close() throws IOException {
            br.close();
            isr.close();
        }
    }
}
```
