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
        int n,x;
        cin>>n>>x;
        int arr[n+x];
        int count[1000]={0};
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            count[arr[i]]++;
        }
        while(x--)
        {
            for(int i=1;i<1000;i++)
            {
                if(count[i]==0)
                {
                    count[i]++;
                    break;
                }
                else
                continue;
            }
        }
        for(int i=1;i<1000;i++)
        {
            if(count[i]==0)
            {
            cout<<--i<<endl;;
            break;
            }
        }
    }
}