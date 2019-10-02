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
 
inline double distance(double x,double y,double a,double b)
{
    return sqrt(pow(x-a,2)+pow(y-b,2));
}
 
//Direction Array
//int fx[]={1, -1, 0, 0}; int fy[]={0, 0, 1, -1};
//int fx[]={0, 0, 1, -1, -1, 1, -1, 1}; int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};
 
 
#define LIMIT 150010
#define inf INT_MAX
 
struct point
{
    double x,y;
};
 
istream& operator>>(istream& out,point& a)
{
    out>>a.x>>a.y;
    return out;
}
int main()
{
    fast;
    int t;
    //SF(t);
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        point a,b,c,d;
//        scanf("%lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);
//        scanf("%lf %lf %lf %lf",&c.x,&c.y,&d.x,&d.y);
        cin>>a>>b>>c>>d;
        double mn=10000000;
        for(int i=0;i<200;i++)
        {
            point mid1,mid2,mid3,mid4;
            double temp=(b.x-a.x)/3;
            mid1.x=a.x+temp,mid2.x=b.x-temp;
            temp=(b.y-a.y)/3;
            mid1.y=a.y+temp,mid2.y=b.y-temp;
            temp=(d.x-c.x)/3;
            mid3.x=c.x+temp,mid4.x=d.x-temp;
            temp=(d.y-c.y)/3;
            mid3.y=c.y+temp,mid4.y=d.y-temp;
            double d1,d2;
            d1=distance(mid1.x,mid1.y,mid3.x,mid3.y);
            d2=distance(mid2.x,mid2.y,mid4.x,mid4.y);
            mn=min(mn,min(d1,d2));
            if(d1>d2)
                a=mid1,c=mid3;
            else if(d1<d2)
                b=mid2,d=mid4;
            else
                a=mid1,b=mid2,c=mid3,d=mid4;
        }
        cout<<fixed<<setprecision(10);
        cout<<"Case "<<cas<<": "<<mn<<endl;
    }
}