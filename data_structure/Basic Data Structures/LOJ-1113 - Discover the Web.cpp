#include<bits/stdc++.h>
using namespace std;
 
double a[1001000];
int main()
{
 
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        stack<string>back,forward;
        string x;
        string cur="http://www.lightoj.com/";
 
        cout<<"Case "<<cas<<":"<<endl;
        while(1)
        {
            cin>>x;
            if(x=="VISIT")
            {
                string v;
                cin>>v;
                back.push(cur);
                cur=v;
                forward=stack<string>();
            }
            else if(x=="BACK")
            {
                if(back.empty())
                {
                    cout<<"Ignored"<<endl;
                    continue;
                }
                forward.push(cur);
                cur=back.top();
                back.pop();
            }
            else if(x=="FORWARD")
            {
                if(forward.empty())
                {
                    cout<<"Ignored"<<endl;
                    continue;
                }
                back.push(cur);
                cur=forward.top();
                forward.pop();
            }
            else
            {
                break;
            }
            cout<<cur<<endl;
        }
        back=stack<string>();
        forward=back;
    }
}