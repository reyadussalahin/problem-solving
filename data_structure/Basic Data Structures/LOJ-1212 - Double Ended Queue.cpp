#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int n,m;
        cin>>n>>m;
        int a[1000];
        int l=500,r=501;
        cout<<"Case "<<cas<<":"<<endl;
        string s;
        int x;
        cin.ignore(1,'\n');
        for(int i=0;i<m;i++)
        {
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>x;
                if(r-l-1>=n)
                {
                    cout<<"The queue is full"<<endl;
                    continue;
                }
                    a[l]=x,l--;
                cout<<"Pushed in left: "<<x<<endl;
            }
            else if(s=="pushRight")
            {
                cin>>x;
                if(r-l-1>=n)
                {
                    cout<<"The queue is full"<<endl;
                    continue;
                }
 
                    a[r]=x,r++;
                cout<<"Pushed in right: "<<x<<endl;
            }
            else if(s=="popLeft")
            {
                if(r-l-1<=0)
                {
                    cout<<"The queue is empty"<<endl;
                    continue;
                }
                l++;
                cout<<"Popped from left: "<<a[l]<<endl;
            }
            else
            {
                if(r-l-1<=0)
                {
                    cout<<"The queue is empty"<<endl;
                    continue;
                }
                r--;
                cout<<"Popped from right: "<<a[r]<<endl;
            }
        }
    }
}