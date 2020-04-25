#include<bits/stdc++.h>
using namespace std;
bool poss(int arr[],int n)
{
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==i+1)
        continue;
        else
        {
            return false;
            break;
        }
        
    }
    return true; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        int arr[k];
        for(int i=0;i<k;i++)
        {
            cin>>arr[i];
        }
        int fork1[k-(*max(arr,arr+k))];
        
