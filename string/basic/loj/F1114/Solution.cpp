// problem name: Easily Readable
// problem link: http://lightoj.com/volume_showproblem.php?problem=1114
// contest link: (?)
// time: (?)
// author: reyad


// other_tags: sorting, binary search, binary search tree
// difficulty_level: easy


#include <bits/stdc++.h>

using namespace std;


char word[10004];
char sent[10004];

map<string, int> mp;


int main() {
    int tc;
    scanf("%d", &tc);
    for(int cc=0; cc<tc; cc++) {
        mp.clear();
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%s", word);
            string w(word);
            int l = w.length();
            if(l > 3) {
                sort(w.begin()+1, w.begin()+l-1);
            }
            mp[w]++;
        }
        int m;
        scanf("%d", &m);
        printf("Case %d:\n", cc+1);
        for(int i=0; i<m; i++) {
            char ch;
            scanf("%c", &ch);
            scanf("%[^\n]", sent);
            int ans = 1;
            istringstream s(sent);
            string w;
            while(s >> w) {
                int l = w.length();
                if(l > 3) {
                    sort(w.begin()+1, w.begin()+l-1);
                }
                ans = ans * mp[w];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}