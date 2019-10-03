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
#define inf LONG_MAX
 
struct max_min
{
    lli mx,mn;
};
int n;
max_min tree[3*LIMIT];
lli a[LIMIT];
void init()
{
    for(int i=0;i<=n;i++)
        tree[i].mx=0,tree[i].mn=inf;
}
 
#define left(n) 2*n+1
#define right(n) 2*n+2
 
void make_tree(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].mx=tree[node].mn=a[l];
        return;
    }
    int mid=(l+r)/2;
    make_tree(left(node),l,mid);
    make_tree(right(node),mid+1,r);
    tree[node].mx=max(tree[left(node)].mx,tree[right(node)].mx);
    tree[node].mn=min(tree[left(node)].mn,tree[right(node)].mn);
}
 
max_min query(int node,int l,int r,int i,int j)
{
    max_min x;
    if(l>j || r<i)
    {
        x.mx=0,x.mn=inf;
        return x;
    }
    if(l>=i && r<=j)
    {
        return tree[node];
    }
    max_min y;
    int mid=(l+r)/2;
    x=query(left(node),l,mid,i,j);
    y=query(right(node),mid+1,r,i,j);
    max_min m;
    m.mx=max(x.mx,y.mx);
    m.mn=min(x.mn,y.mn);
    return m;
}
 
int main()
{
    int t;
    SF(t);
    for(int cas=1;cas<=t;cas++)
    {
        int d;
        SFF(n,d);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        init();
        make_tree(0,0,n-1);
        lli ans=0;
        for(int i=0,j=d-1;j<n;j++,i++)
        {
            max_min x=query(0,0,n-1,i,j);
            ans=max(ans,abs(x.mx-x.mn));
        }
        printf("Case %d: %lld\n",cas,ans);
    }
}