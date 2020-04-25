
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,s,k;
        cin>>n>>s>>k;
        int arr[k];
        for(int j=0;j<k;j++)
        cin>>arr[j];
        int rest[s];
        for(int j=0;j<=s;j++)
        {
            rest[j]=1;
        }
        for(int j=0;j<k;j++)
        {
            rest[arr[j]]==0;
        }
    }