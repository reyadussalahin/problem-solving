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
 
#define LIMIT 1000000
#define inf INT_MAX
 
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
 
#define left(n) n*2+1
#define right(n) n*2+2
 
lli tree[LIMIT*4];
lli prop[LIMIT*4];
 
void update(int node,int l,int r,int i,int j,int x)
{
    lli a;
    if(prop[node]!=0)
    {
        a=tree[node]+=(r-l+1)*prop[node];
        if(l!=r){
        a=prop[left(node)]+=prop[node];
        a=prop[right(node)]+=prop[node];
        }
        prop[node]=0;
    }
    if(l>j || r<i)return;
    if(l>=i && r<=j)
    {
        a=tree[node]+=(r-l+1)*x;
        if(l!=r){
        prop[left(node)]+=x;
        prop[right(node)]+=x;
        }
        return;
    }
    int mid=(l+r)/2;
    update(left(node),l,mid,i,j,x);
    update(right(node),mid+1,r,i,j,x);
    a=tree[left(node)]+tree[right(node)];
    tree[node]=a;
}
 
lli query(int node,int l,int r,int i,int j)
{
    lli a;
    if(prop[node]!=0)
    {
        lli x=prop[node];
        a=tree[node]+=(r-l+1)*x;
        if(l!=r){
        prop[left(node)]+=x;
        prop[right(node)]+=x;
        }
        prop[node]=0;
    }
    if(l>j || r<i)return 0;
    if(l>=i && r<=j)
    {
        return tree[node];
    }
    lli mid=(l+r)/2;
    lli p1=query(left(node),l,mid,i,j);
    lli p2=query(right(node),mid+1,r,i,j);
    return p1+p2;
}
 
int main()
{
    int t;
    SF(t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,q;
        SFF(n,q);
        mem(tree,0);
        mem(prop,0);
        printf("Case %d:\n",cas);
        for(int i=0;i<q;i++)
        {
            int f;
            SF(f);
            if(f)
            {
                int x,y;
                SFF(x,y);
                printf("%lld\n",query(0,0,n-1,x,y));
            }
            else
            {
                int x,y,v;
                SFFF(x,y,v);
                update(0,0,n-1,x,y,v);
            }
        }
    }
}