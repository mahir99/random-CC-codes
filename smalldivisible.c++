#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,d;
        cin>>n;
        if(n%9)
        d=n/9 +1;
        else
        {
            d=n/9;
        }
        int res[d+n];
        n -= 1; 
        for (int i=d-1; i>0; i--) 
        { 
            if (n > 9) 
            { 
                res[i] = 9; 
                n -= 9; 
            } 
            else
            { 
                res[i] = n; 
                n = 0; 
            } 
        } 
        res[0] = n + 1;
        for (int i=0; i<d; i++) 
            cout << res[i];
        for(int i=0;i<n;i++)
        cout<<0;
        cout<<endl;    

    }
    return 0;
    
}