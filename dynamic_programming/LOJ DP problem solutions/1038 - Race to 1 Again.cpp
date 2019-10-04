#include<bits/stdc++.h>
using namespace std;
#define asgnarr(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define fast ios_base::sync_with_stdio(false)
#define endl '\n'
#define loop(a,b) for(int i=a;i<b;i++)
#define mem(a,x) memset(a,x,sizeof(a))
#define pii pair<int,int>
#define psi pair<string,int>
#define pss pair<string,string>
#define pll pair<long long,long long>
#define pls pair<long long,string>
#define pis pair<int,string>
#define pcc pair<char,char>
#define pb push_back
#define all(v) v.begin(),v.end()
#define SF(n) scanf("%d",&n);
#define SFF(n,m) scanf("%d %d",&n,&m)
#define SFFF(n,m,l) scanf("%d %d %d",&n,&m,&l)
#define SL(n) scanf("%lld",&n)
#define SLL(n,m) scanf("%lld %lld",&n,&m)
#define rep(i,x,n) for(int i=x;i<n;i++)
#define rrep(i,x,n) for(int i=x;i>n;i--)
#define forcas for(int cas=1;cas<=t;cas++)
#define printcas cout<<"Case "<<cas<<':'
 
typedef long long lli;
typedef long li;
typedef unsigned long long ulli;
typedef unsigned long int uli;
typedef unsigned int ui;
typedef long double ld;
 
inline int iseven(int x){return x&1?0:1;}
 
inline bool is_double(double x)
{
    double y=x-(int)x;
    return (y==x?true:false);
}
 
li bigmod(li b,li p,lli m)
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
    for(lli i=0;i<v.size();i++)
        out<<v[i]<<' ';
    return out;
}
 
inline double distance(int x,int y,int a,int b)
{
    return sqrt(pow(x-a,2)+pow(y-b,2));
}
 
//Direction Array
//int fx[]={1, -1, 0, 0}; int fy[]={0, 0, 1, -1};
//int fx[]={0, 0, 1, -1, -1, 1, -1, 1}; int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};
 
 
#define LIMIT 100010
#define inf 1e18
 
double dp[LIMIT];
 
double func(int n)
{
    if(n==1)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    double d=2.0;
    double sum=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i!=n/i)
            {
                d+=2;
                sum+=2+func(i)+func(n/i);
            }
            else
            {
                d++;
                sum+=1+func(i);
            }
        }
    }
    double p=1/d;
    sum+=2;
    sum*=p;
    sum/=(1.0-p);
    return dp[n]=sum;
}
int main()
{
    for(int i=0;i<=LIMIT;i++)
    {
        dp[i]=-1;
    }
    int t;
    cin>>t;
    cout<<fixed<<setprecision(12);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<cas<<": "<<func(n)<<endl;
    }
}