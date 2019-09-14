// problem name: New Land
// problem link: http://lightoj.com/volume_showproblem.php?problem=1424
// contest link: (?)
// time: (?)
// author: reyad

import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.PrintWriter;
 
import java.io.IOException;
import java.util.Arrays;
 
 
public class Solution {
    static Reader in;
    static PrintWriter out;
   
    static class Solve {
        class Stack {
            int[] buf = new int[2000];
            int top;
            void offer(int data) { buf[top++] = data; }
            int peek() { return buf[top-1]; }
            int pop() { return buf[--top]; }
            boolean empty() { if(top == 0)  return true;    return false;}
            void clear() { top = 0; }
        }
        Stack s = new Stack();
        int maxArea(int[] arr, int n) {
            int i, max=0, tmax, t;
            s.clear();
            for(i=0; i<n; i++) {
                if(s.empty() || arr[i]>arr[s.peek()])   s.offer(i);
                else {
                    while(!s.empty() && arr[i]<arr[s.peek()]) {
                        t = s.pop();
                        if(s.empty()) tmax = arr[t] * i;
                        else tmax = arr[t] * (i-s.peek()-1);
                        max = Math.max(max, tmax);
                    }
                    s.offer(i);
                }
            }
            while(!s.empty()) {
                t = s.pop();
                if(s.empty())   tmax = arr[t] * n;
                else    tmax = arr[t] * (n-s.peek()-1);
                max = Math.max(max, tmax);
            }
            return max;
        }
        void main() throws IOException {
            int cc, tc, i, j, m, n, mx;
            String str;
            int[] cntPrev = new int[2000];
            int[] cnt = new int[2000];
 
            tc = in.nextInt();
            for(cc=0; cc<tc; cc++) {
                m = in.nextInt();
                n = in.nextInt();
                mx = 0;
                Arrays.fill(cntPrev, 0);
                for(i=0; i<m; i++) {
                    str = in.nextLine();
                    for(j=0; j<n; j++) {
                        if(str.charAt(j) == '0')    cnt[j] = cntPrev[j] + 1;
                        else cnt[j] = 0;
                    }
                    mx = Math.max(mx, maxArea(cnt, n));
                    System.arraycopy(cnt, 0, cntPrev, 0, n);
                }
                out.println("Case " + (cc+1) + ": " + mx);
            }
        }
    }
 
    public static void main(String[] args) {
        try {
            OutputStreamWriter osw = new OutputStreamWriter(System.out);
            BufferedWriter bw = new BufferedWriter(osw);
            in = new Reader();
            out = new PrintWriter(bw);
 
            Solve s = new Solve();
            s.main();
 
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
            while(((str = br.readLine()) != null) && (str.length() == 0)) ;
            return str;
        }
        String next() throws IOException {
            while(tk.hasMoreTokens() == false) {
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
