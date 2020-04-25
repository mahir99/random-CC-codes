#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
            if(b==1)
            cout<<"YES"<<endl;
            else
            {
                cout<<"NO"<<endl;
            }
           continue; 
        }
        if(a==2||a==3)
        {
            if(b==1||b==2||b==3)
            cout<<"YES"<<endl;
            else
            {
                cout<<"NO"<<endl;
            }
            continue;
        }
        cout<<"YES"<<endl;
    }
}