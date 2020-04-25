#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<9;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<s.length();j++)
            {
                if(s.at(j)=='2')
                cout<<"7";
                else
                {
                    cout<<s.at(j);
                }  
            }
            cout<<endl;
        }
    }
}
        