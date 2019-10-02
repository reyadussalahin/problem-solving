#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        double r;
        cin>>r;
        double ans=4*r*r-2*acos(0.0)*r*r;
        cout<<fixed<<setprecision(2);
        cout<<"Case "<<cas<<": "<<ans<<endl;
    }
}