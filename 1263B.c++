#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    long long n,k;
    for(cin>>t;t--;)
    {
        cin>>n>>k;
        if(n%k<=floor(k/2))
        cout<<n<<endl;
        else
            cout<<(n/k)*k + (int)floor(k/2)<<endl;
    }
}
