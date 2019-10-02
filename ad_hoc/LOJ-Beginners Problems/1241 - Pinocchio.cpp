#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        cin>>n;
        int a[n];
        int ans=0;
        a[0]=2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            int x=a[i]-a[i-1];
            ans+=x/5;
            if(x%5>0)ans++;
        }
        cout<<"Case "<<cas<<": "<<ans<<endl;
    }
}