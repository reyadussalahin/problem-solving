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
#define si(n) scanf("%d",&n);
//#define si(n,m) scanf("%d %d",&n,&m)
#define sl(n) scanf("%lld",&n)
 
#define MAX 150010
 
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
 
int main()
{
    int t;
    si(t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        si(n);
        int a[2*(n+1)][2*(n+1)];
        queue<int>q;
        for(int i=0;i<n;i++)
            q.push(i+1);
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                si(a[i][j])
            }
        }
 
        map<int,int>mp;
        int count=0;
        while(count<n)
        {
            int i;
            for(i=1;i<=n;i++)
            {
                if(mp[i]==0)
                    break;
            }
            for(int j=1;j<=n && mp[i]==0;j++)
            {
                int y=a[i][j];
                if(mp[y]==0){
                    mp[i]=y,mp[y]=i;
                    count++;
                    break;
                }
                else
                {
                    int x1=mp[y];
                    int m;
                    for(int k=1;k<=n;k++)
                    {
                        if(a[y][k]==x1)
                        {
                            break;
                        }
                        else if(a[y][k]==i)
                        {
                            mp[x1]=0;
                            mp[i]=y;
                            mp[y]=i;
                            break;
                        }
                    }
                }
            }
        }
        printf("Case %d: ",cas);
        bool f=false;
        for(int i=1;i<=n;i++){
            if(f)
                printf(" ");
            f=true;
            printf("(%d %d)",i,mp[i]);
        }
        cout<<endl;
    }
}