#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<long long>v;
    long long p=2;
    for(int i=0;i<63;i++)
    {
        v.push_back(p);
        p*=2;
    }
    for(int cas=1;cas<=t;cas++)
    {
        long long x;
        cin>>x;
        cout<<"Case "<<cas<<": ";
        if(x%2==1)
            cout<<"Impossible";
        else
        {
            long long m;
            for(int i=0;i<v.size();i++)
            {
                long long n=v[i];
                long double a=x/n;
                if(a==(long long)a && (long long)a%2==1)
                {
                    m=n;
                    break;
                }
            }
            cout<<x/m<<' '<<m;
        }
        cout<<endl;
    }
 
}