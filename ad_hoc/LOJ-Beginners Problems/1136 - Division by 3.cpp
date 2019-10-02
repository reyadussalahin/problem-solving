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
#define SLL(n,m) scanf("%lld %lld,&n,&m)
 
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
 
 
#define LIMIT 150010
#define inf INT_MAX
 
int main()
{
    int t;
    fast;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        lli a,b,x,y,ans=0;
        cin>>a>>b;
        x=a%3;
        if(x==0)
            x=1;
        else if(x==1)
            x=3;
        else
            x=2;
        if(a+x<=b)
        {
            if(x==1)
            {
                ans++,a++;
            }
            else if(x==2)
            {
                ans+=2,a+=2;
            }
            else
            {
                ans+=2,a+=3;
            }
        }
        y=b%3;
        if(a<b-y)
        {
            if(y==1)
            {
                b--;
            }
            else if(y==2)
            {
                ans++,b-=2;
            }
            else
                ans+=2,b-=3;
        }
        if(a<b)
        {
            ans+=((b-a+1)/3)*2;
            x=(b-a+1)%3;
            if(x==2)
                ans++;
        }
        else if(a==b)
        {
            x=a%3;
            if(x==2 || x==0)
                ans++;
        }
        cout<<"Case "<<cas<<": "<<ans<<endl;
    }
}