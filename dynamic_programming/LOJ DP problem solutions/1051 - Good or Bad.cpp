#include<bits/stdc++.h>
using namespace std;
#define asgnarr(a,n)            for(int i=0;i<n;i++)cin>>a[i]
#define fast                    ios_base::sync_with_stdio(false)
#define endl                    '\n'
#define loop(a,b)               for(int i=a;i<b;i++)
#define mem(a,x)                memset(a,x,sizeof(a))
#define pii                     pair<int,int>
#define psi                     pair<string,int>
#define pss                     pair<string,string>
#define pll                     pair<long long,long long>
#define pls                     pair<long long,string>
#define pis                     pair<int,string>
#define pcc                     pair<char,char>
#define pb                      push_back
#define all(v)                  v.begin(),v.end()
#define sf(n)                   scanf("%d",&n);
#define sff(n,m)        scanf("%d %d",&n,&m)
#define sfff(n,m,l)         scanf("%d %d %d",&n,&m,&l)
#define sl(n)           scanf("%lld",&n)
#define sll(n,m)        scanf("%lld %lld",&n,&m)
#define rep(i,x,n)          for(int i=x;i<n;i++)
#define rrep(i,x,n)         for(int i=x;i>n;i--)
#define forcas          for(int cas=1;cas<=t;cas++)
#define printcas        cout<<"Case "<<cas<<':'
#define Ignore              cin.ignore();
#define deci(n)             cout<<fixed<<setprecision(n);
#define bug()               cerr<<"*****<>*****\n";
 
typedef long long ll;
typedef long li;
typedef unsigned long long ull;
typedef unsigned long int ul;
typedef unsigned int ui;
typedef long double ld;
 
inline int iseven(int x){return x&1?0:1;}
 
inline bool is_int(double x) {return (x==(int)x?true:false);}
 
li bigmod(li b,li p,ll m)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        return (li)pow(bigmod(b,p/2,m)%m,2)%m;
    }
    return (b%m*bigmod(b,p-1,m)%m)%m;
}
 
template<class T>
ostream& operator<<(ostream &out,vector<T>v)
{
    for(ll i=0;i<v.size();i++)
        out<<v[i]<<' ';
    return out;
}
 
inline double distance(int x,int y,int a,int b){
    return sqrt(pow(x-a,2)+pow(y-b,2));
}
 
template <typename T> inline T LCM(T a,T b){return (a*b)/GCD(a,b);}
 
//Direction Array
//int fx[]={1, -1, 0, 0}; int fy[]={0, 0, 1, -1};
//int fx[]={0, 0, 1, -1, -1, 1, -1, 1}; int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};
 
#define LIMIT 50010
#define inf (1<<20)
 
bool vowel(char ch)
{
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        return true;
    return false;
}
 
string s;
int dp[100][100][100];
 
int func(int i,int cc,int vc)
{
    if(cc==5 || vc==3)
        return dp[i][cc][vc]=1;
    if(i==s.length())
        return 0;
    if(dp[i][cc][vc]!=-1)
        return dp[i][cc][vc];
    int p1=-1,p2=-1;
    if(s[i]=='?')
    {
        p1=func(i+1,cc+1,0);
        p2=func(i+1,0,vc+1);
    }
    else if(vowel(s[i]))
    {
        p2=func(i+1,0,vc+1);
    }
    else
    {
        p1=func(i+1,cc+1,0);
    }
    if(p1==-1 || p2==-1)
        p1==-1?p1=p2:p2=p1;
    if(p1==p2)
        return dp[i][cc][vc]=p1;
    else
        return dp[i][cc][vc]=2;
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
 
    int t;
    cin>>t;
    forcas
    {
        cin>>s;
        mem(dp,-1);
        int x=func(0,0,0);
        printcas;cout<<' ';
        if(x==0)
            cout<<"GOOD";
        else if(x==1)
            cout<<"BAD";
        else
            cout<<"MIXED";
        cout<<endl;
    }
}