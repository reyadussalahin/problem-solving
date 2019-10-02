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
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x>0)
                ans+=x;
        }
        cout<<"Case "<<cas<<": "<<ans<<endl;
    }
}