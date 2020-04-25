#include <bits/stdc++.h>
using namespace std;

struct Activity{
    int start, finish, index;
};

bool activityCompare(Activity s1, Activity s2)
{
    return s1.finish < s2.finish;
}

int main() {
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    Activity arr[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i].start;
	        arr[i].index = i;
	    }
	    
	    for(i=0;i<n;i++)
	    cin>>arr[i].finish;
	    sort(arr,arr+n,activityCompare);
	    
	    i = 0;
        cout << arr[i].index+1 << " ";
        for (int j = 1; j < n; j++)
        {
          if (arr[j].start >= arr[i].finish)
          {
              cout << arr[j].index+1<<" ";
              i = j;
          }
        }
        cout<<endl;
	}
	return 0;
}