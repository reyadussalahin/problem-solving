#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        long long b;
        string a;
        cin>>a>>b;
        long long m=0;
        int i;
        if(a[0]=='-')
            b*=-1,i=1;
        else
            i=0;
        for(;i<a.length();i++)
        {
            m=(m*10)+a[i]-'0';
            m%=b;
        }
        cout<<"Case "<<cas<<": ";
        if(m==0)
        {
            cout<<"divisible"<<endl;
        }
        else
            cout<<"not divisible"<<endl;
    }
}