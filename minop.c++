#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int s[n],f[n];
    int paint[2400]={0};
    int max=-1;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=s[i];j<=f[i];j++)
        {
            paint[j]++;
        }
    }
    for(int i=0;i<2400;i++)
    {
        //cout<<paint[i];
        if(paint[i]>max)
        max=paint[i];
    }
    
    cout<< max;
    }
    return 0;
    
}