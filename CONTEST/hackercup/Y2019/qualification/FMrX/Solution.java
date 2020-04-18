// problem: https://www.facebook.com/hackercup/problem/589264531559040/
// contest: https://www.facebook.com/hackercup/contest
// author: reyad

import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    static Reader in = null;
    static java.io.PrintWriter out = null;

    static boolean isOperator(char ch) {
        return (ch == '&' || ch == '|' || ch == '^');
    }

    static char getOpposite(char ch) {
        if(ch == '1') return '0';
        if(ch == '0') return '1';
        if(ch == 'X') return 'x';
        return 'X';
    }

    static char and(char a, char b) {
        if(a == '0' || b == '0') return '0';
        if(a == '1') return b;
        if(b == '1') return a;
        if(a == b) return a;
        return '0';
    }

    static char or(char a, char b) {
        if(a == '1' || b == '1') return '1';
        if(a == '0') return b;
        if(b == '0') return a;
        if(a == b) return a;
        return '1';
    }

    static char xor(char a, char b) {
        if(a == b) return '0';
        if(a == getOpposite(b)) return '1';
        if(a == '0') return b;
        if(b == '0') return a;
        if(a == '1') return getOpposite(b);
        return getOpposite(a);
    }

    static void solve() throws IOException {
        char[] stack = new char[512];
        char[] postfix = new char[512];

        int tc = in.nextInt();
        for(int cc=0; cc<tc; cc++) {
            String b = in.nextLine();

            int top = 0;
            int pfc = 0;
            for(char ch: b.toCharArray()) {
                if(ch == '(') stack[top++] = '(';
                else if(ch == ')') {
                    while(top > 0 && stack[top-1] != '(') postfix[pfc++] = stack[--top];
                    --top; // removing '(' bracket from stack
                }
                else if(isOperator(ch)) stack[top++] = ch;
                else postfix[pfc++] = ch;
            }

            // checking postfix
            // out.print("postfix: ");
            // for(int i=0; i<pfc; i++) out.print(postfix[i]);
            // out.println();

            // calculating postfix
            top = 0;
            for(int i=0; i<pfc; i++) {
            	char res = postfix[i];
                if(isOperator(postfix[i])) {
                    char u = stack[--top];
                    char v = stack[--top];
                    if(postfix[i] == '&') res = and(u, v);
                    else if(postfix[i] == '|') res = or(u, v);
                    else res = xor(u, v);
                }
                stack[top++] = res;
            }

            // out.println("value of top(should be always 1): " + top);
            // out.println("last val: " + stack[0]);
            // if(stack[0] == '1' || stack[0] == '0') out.println("cost: 0");
            // else out.println("cost: 1");

            if(stack[0] == '1' || stack[0] == '0') out.println("Case #" + (cc+1) + ": 0");
            else out.println("Case #" + (cc+1) + ": 1");
        }
    }

    public static void main(String[] args) {
        try {
            java.io.OutputStreamWriter osw = new java.io.OutputStreamWriter(System.out);
            java.io.BufferedWriter bw = new java.io.BufferedWriter(osw);
            out = new java.io.PrintWriter(bw, true);

            in = new Reader();
//            in = new Reader("input.txt");

            solve();

            in.close();

            out.close();
            bw.close();
            osw.close();
        }
        catch(java.io.FileNotFoundException e) {
            e.printStackTrace();
        }
        catch(java.io.IOException e) {
            e.printStackTrace();
        }
    }

    static class Reader {
        java.io.Reader reader;
        java.io.BufferedReader br;
        StringTokenizer tk;
        String s;

        Reader() {
            init(new java.io.InputStreamReader(System.in));
        }
        Reader(String file) throws java.io.FileNotFoundException {
            init(new java.io.FileReader(file));
        }

        void init(java.io.Reader rd) {
            reader = rd;
            br = new java.io.BufferedReader(reader);
            tk = new StringTokenizer("");
            s = null;
        }
        String nextLine() throws IOException {
            while((s = br.readLine()) != null && s.length() == 0);
            return s;
        }
        String next() throws IOException {
            if(!tk.hasMoreTokens()) tk = new StringTokenizer(nextLine());
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
        void close() throws IOException {
            br.close();
            reader.close();
        }
    }
}
