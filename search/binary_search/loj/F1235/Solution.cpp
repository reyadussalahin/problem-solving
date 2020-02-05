// problem name: Coin Change (IV)
// problem link: http://lightoj.com/volume_showproblem.php?problem=1235
// contest link: (?)
// time: (?)
// author: reshad hasan


#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int n;
ll k,a[20];
vector<ll>s1,s2;
#define pb push_back
 
void genset1(int i,ll x)
{
    s1.pb(x);
    if(i==n/2)
        return;
    genset1(i+1,x),genset1(i+1,x+a[i]),genset1(i+1,x+2*a[i]);
}
void genset2(int i,ll x)
{
    s2.pb(x);
    if(i==n)
        return;
    genset2(i+1,x),genset2(i+1,x+a[i]),genset2(i+1,x+2*a[i]);
}
 
#define all(v) v.begin(),v.end()
#define endl '\n'
 
#define sf(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
 
int main()
{
    int t;
    sf(t);
    for(int cas=1;cas<=t;cas++)
    {
        sf(n),sl(k);
        for(int i=0;i<n;i++)
            sf(a[i]);
        s1.clear();
        s2.clear();
        genset1(0,0);
        genset2(n/2,0);
        sort(all(s1));
        bool f=false;
        for(int i=0;i<s2.size();i++)
        {
            int x=k-s2[i];
            if(binary_search(all(s1),k-s2[i]))
            {
                f=!f;
                break;
            }
        }
        printf("Case %d: %s\n",cas,(f?"Yes":"No"));
    }
}