#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        auto x=s.find_last_of('1');
        
if (x != string::npos) {
    cout<<x;
}
else {
    cout<<"-1";
}
    }
}