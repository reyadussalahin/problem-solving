#include<bits/stdc++.h>
using namespace std;
 
int n;
int tree[150000];
#define SF(N) scanf("%d",&N)
#define SFF(a,b) scanf("%d %d",&a,&b)
 
void update(int i,int v)
{
    while(i<=n)
    {
        tree[i]+=v;
        i+=i&(-i);
    }
}
 
int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=tree[i];
        i-=i&(-i);
    }
    return sum;
}
 
int main()
{
    int t;
    SF(t);
    for(int cas=1;cas<=t;cas++)
    {
        int q;
        SFF(n,q);
        memset(tree,0,sizeof(tree));
        for(int i=0;i<n;i++)
        {
            int x;
            SF(x);
            update(i+1,x);
        }
//        for(int i=1;i<=n;i++)
//            cout<<tree[i]<<' ';
//        cout<<endl;
        printf("Case %d:\n",cas);
        while(q--)
        {
            int c;
            SF(c);
            int u,v;
            if(c==1)
            {
                SF(u);
                int x=query(u+1);
                int y=query(u);
                update(u+1,-x+y);
                printf("%d\n",x-y);
            }
            else if(c==2)
            {
                SFF(u,v);
                update(u+1,v);
            }
            else
            {
                SFF(u,v);
                int x=query(v+1);
                int y=query(u);
                printf("%d\n",x-y);
            }
//            for(int i=1;i<=n;i++)
//            cout<<tree[i]<<' ';
//        cout<<endl;
        }
    }
}