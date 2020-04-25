#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }   
    string decrypt;
    cin>>decrypt;
    int row=decrypt.length()/n;
    char a[row][n];
    int find=1;
    int put;
    for(int i=0;i<decrypt.length();i++,find++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j]==find)
            put=j;
        }
        for(int k=0;k<row;k++)
        {    
            a[i][put]=decrypt.at(i);
        }
    }}