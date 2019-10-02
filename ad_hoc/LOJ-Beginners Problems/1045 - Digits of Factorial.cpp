#include<bits/stdc++.h>
using namespace std;
 
double a[1001000];
int main()
{
    int t;
    cin>>t;
    a[0]=a[1]=0;
    for(long int i=2;i<=1000000;i++)
    {
        double x=log(i);
        a[i]=a[i-1]+x;
    }
    for(int cas=1;cas<=t;cas++)
    {
        long int n;
        int b;
        scanf("%ld %d",&n,&b);
        double ans=a[n];
        double x=log(b);
        ans/=x;
        cout<<"Case "<<cas<<": "<<(int)ans+1<<endl;
    }
}