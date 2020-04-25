#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int inp[n];
    int rcvd[n];
    for(int i=0;i<n;i++)
    rcvd[i]=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        inp[i]=x-1;
        if(inp[i]!=-1)
        rcvd[inp[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(inp[i]==-1)
        for(int j=0;j<n;j++)
        {
            if(rcvd[j]==0)
            {
                inp[i]=rcvd[j];
                rcvd[j]=1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
    cout<<inp[i]+1<<" ";
    //cout<<endl;
    //cout<<rcvd[i]+1;
}}
