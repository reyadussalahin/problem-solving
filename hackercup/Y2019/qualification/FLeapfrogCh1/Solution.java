// problem: https://www.facebook.com/hackercup/problem/656203948152907/
// contest: https://www.facebook.com/hackercup/contest
// author: reyad

import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    static Reader in = null;
    static java.io.PrintWriter out = null;

    static void solve() throws IOException {
        int tc = in.nextInt();
        for(int cc=0; cc<tc; cc++) {
            String b = in.nextLine();

            int nb = 0, nd = 0;
            for(char ch: b.toCharArray()) {
                if(ch == 'A') continue;
                if(ch == 'B') nb++;
                if(ch == '.') nd++;
            }

            if(nb != 0 && nd != 0 && nb >= nd) out.println("Case #" + (cc+1) + ": Y");
            else out.println("Case #" + (cc+1) + ": N");
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
