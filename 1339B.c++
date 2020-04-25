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
        sort(arr,arr+n);
        int low=n/2-1;
        int high=n/2;
        for(int i=0;i<n/2;i++)
        {
            cout<<arr[high]<<" "<<arr[low]<<" ";
            high++,low--;
        }
        if(n%2==1)
        cout<<arr[n-1];
        cout<<endl;
    }
}