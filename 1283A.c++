#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    for(cin>>t;t--;)
    {
        int h,m;
        cin>>h>>m;
        cout<<(24-h)*60-m<<endl;
    }
}