#include<bits/stdc++.h>
using namespace std;
 
#define lli long long
 
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        double n;
        cin>>n;
        lli m=n;
        lli x=(lli)sqrt(n);
        int row,col;
        if(n==x*x)
        {
            if(x%2==1)
                row=1,col=x;
            else
                row=x,col=1;
        }
        else
        {
            n-=x*x;
            x++;
            if(x%2==1)
            {
                if(n>=x)
                    col=x,row=x*x-m+1;
                else
                    row=x,col=n;
            }
            else
            {
                if(n>=x)
                {
                    row=x,col=x*x-m+1;
 
                }
                else
                    col=x,row=n;
            }
        }
        cout<<"Case "<<cas<<": ";
        cout<<row<<' '<<col<<endl;
    }
 
}