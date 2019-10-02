#include<bits/stdc++.h>
using namespace std;
 
#define lli long long
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        lli n;
        cin>>n;
        vector<int>v;
 
        while(n>0)
        {
            v.push_back(n%2);
            n/=2;
        }
        v.push_back(0);
//        for(int x:v)
//            cout<<x<<' ';
//        cout<<endl;
        int one=-1;
        int count=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==1)
            {
                one=i;
                count++;
            }
            else if(v[i]==0 && one>=0)
            {
                v[i]=1;
                v[one]=0;
                count--;
                break;
            }
        }
        for(int i=0;i<one;i++)
        {
            if(count>0)
                v[i]=1,count--;
            else
                v[i]=0;
        }
        int ans=0;
//        for(int x:v)
//            cout<<x<<' ';
//        cout<<endl;
        for(int i=0;i<v.size();i++)
        {
            ans+=v[i]*pow(2,i);
        }
        cout<<"Case "<<cas<<": "<<ans<<endl;
    }
}