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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int z=1;
        for(int i=1;i<n;i++)
        {
        while(arr[i]<arr[i-1])
        {
            arr[i]+=pow(2,z-1);
            z++;
        }
        }
        cout<<z-1<<endl;
    }
}
        