#include<bits/stdc++.h>
using namespace std;
#define asgnarr(a,n) for(int i=0;i<n;i++)in>>a[i]
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
 
#define MAX 200000
 
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
 
li n;
li a[MAX];
li tree[4*MAX];
 
void creat_tree(li node,li low,li high)
{
    if(low==high)
    {
        tree[node]=a[low];
        return;
    }
    li left=2*node+1;
    li right=2*node+2;
    li mid=(low+high)/2;
    creat_tree(left,low,mid);
    creat_tree(right,mid+1,high);
    tree[node]=min(tree[left],tree[right]);
}
 
li query(li node,li low,li high,li i,li j)
{
    if(i>high|| j<low)
    {
        return LONG_MAX;
    }
    if(i<=low && j>=high)
        return tree[node];
    li left=2*node+1;
    li right=2*node+2;
    li mid=(low+high)/2;
    return min(query(left,low,mid,i,j),query(right,mid+1,high,i,j));
 
}
int main()
{
    //fast;
    li t;
    scanf("%ld",&t);
 
    for(li cas=1;cas<=t;cas++)
    {
        li q;
        scanf("%ld %ld",&n,&q);
        for(li i=0;i<n;i++)
            scanf("%ld",&a[i]);
        creat_tree(0,0,n-1);
        printf("Case %ld:\n",cas);
        for(li i=0;i<q;i++)
        {
            li x,y;
            scanf("%ld %ld",&x,&y);
            if(x>y)
                swap(x,y);
            printf("%ld\n",query(0,0,n-1,x-1,y-1));
        }
    }
}