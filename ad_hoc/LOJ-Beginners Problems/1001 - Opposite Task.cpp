#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int a;
        cin>>a;
        if(a<=10)
            cout<<"0 "<<a;
        else
            cout<<"10 "<<a-10;
        cout<<endl;
    }
}