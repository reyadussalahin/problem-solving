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
        string a,b;
        cin>>a;
        b=a;
        reverse(b.begin(),b.end());
        int n=a.length();
        int prefix[n+10];
        prefix[0]=0;
        int i=1,j=0;
        while(i<n)
        {
            if(b[i]==b[j])
            {
                prefix[i]=prefix[j]+1;
                i++,j++;
            }
            else if(j==0)
            {
                prefix[i]=0;
                i++;
            }
            else
                j=prefix[j-1];
        }
        i=0,j=0;
        while(i<n)
        {
            if(a[i]==b[j])
                i++,j++;
            else if(j==0)
                i++;
            else
                j=prefix[j-1];
        }
        cout<<"Case "<<cs<<": ";
        int ans=n+n-j;
        cout<<ans<<endl;
    }
}