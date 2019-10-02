#include<bits/stdc++.h>
using namespace std;
 
 
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a[n+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                int x;
                cin>>x;
                a[i].push_back(x);
            }
        }
        int ob[m+1];
        memset(ob,0,sizeof(ob));
       
        int p;
        cin>>p;
        for(int i=0;i<p;i++)
        {
            int x;
            cin>>x;
            ob[x]=true;
        }
        bool ans=true;
        for(int i=1;i<=n;i++)
        {
            bool t=false;
            for(int j=0;j<k;j++)
            {
                int x=a[i][j];
                bool y;
                if(x>0)
                {
                    y=(ob[x]?true:false);
                }
                else
                    y=(ob[-x]?false:true);
                t=t||y;
            }
            ans=t&&ans;
        }
        cout<<"Case "<<cs<<": ";
        cout<<(ans?"Yes":"No")<<endl;
    }
}