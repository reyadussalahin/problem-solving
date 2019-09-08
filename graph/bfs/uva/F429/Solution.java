// problem name: Word Transformation
// problem link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=370
// contest link: (?)
// time: (?)
// author: reyad


import java.io.*;
import java.util.*;

public class Solution {
	static boolean hasEdge(String s, String t) {
		if(s.length() != t.length()) return false;
		int c = 0;
		for(int i=s.length()-1; i>=0; i--) {
			if(s.charAt(i) != t.charAt(i)) c++;
		}
		return (c == 1);
	}

	public static void main(String[] args) {
		String[] wordList = new String[256];
		boolean[][] g = new boolean[256][256];
		int[] q = new int[256];
		int[] lev = new int[256];
		int startLev = 0;

		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			PrintStream out = System.out;

			int tc = Integer.parseInt(br.readLine());
			br.readLine();
			for(int cc=0; cc<tc; cc++) {
				int n = 0;
				String buf = br.readLine();
				while(!buf.equals("*")) {
					wordList[n++] = buf;
					buf = br.readLine();
				}
				for(int i=0; i<n; i++) {
					for(int j=0; j<n; j++) {
						g[i][j] = false;
					}
				}
				for(int i=0; i<n; i++) {
					for(int j=i+1; j<n; j++) {
						if(hasEdge(wordList[i], wordList[j])) {
							g[i][j] = g[j][i] = true;
						}
					}
				}

				if(cc != 0) {
					out.println("");
				}
				buf = br.readLine();
				while(buf != null && buf.length() > 0) {
					StringTokenizer tk = new StringTokenizer(buf);
					String startWord = tk.nextToken();
					String endWord = tk.nextToken();
					int start = -1;
					int end = -1;
					for(int i=0; i<n; i++) {
						if(startWord.equals(wordList[i])) start = i;
						if(endWord.equals(wordList[i])) end = i;
					}

					int s = 0, e = 0;
					q[e++] = start;
					lev[start] = startLev;
					int maxLev = startLev;
					while(s != e) {
						int at = q[s++];
						if(at == end) break;
						for(int i=0; i<n; i++) {
							if(g[at][i] && lev[i] <= startLev) {
								q[e++] = i;
								lev[i] = lev[at] + 1;
								maxLev = Math.max(maxLev, lev[i]);
							}
						}
					}
					out.println(startWord + " " + endWord + " " + (lev[end] - startLev));
					startLev = maxLev + 1;
					buf = br.readLine();
				}
			}
			br.close();
		}
		catch(IOException e) {
			e.printStackTrace();
		}
	}
}