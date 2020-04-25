#include<bits/stdc++.h>
using namespace std;
int pl,ml;
int last(int a[],int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    if(a[i]==1)
    break;
    return i;
}
void reduce(int a[],int n)
{
    for(int i=0;i<n;i++)
    a[i]=a[i]%2;
}
int main()
{
    string fx,gx,mx;
    cin>>fx>>gx>>mx;
    int fxarr[fx.length()],gxarr[gx.length()],mxarr[mx.length()];
    for(int i=fx.length()-1;i>=0;i--)
    fxarr[i]=fx.at(i)-48;
    for(int i=gx.length()-1;i>=0;i--)
    gxarr[i]=gx.at(i)-48;
    for(int i=mx.length()-1;i>=0;i--)
    mxarr[i]=mx.at(i)-48;
    ml=mx.length();
    pl=fx.length()+gx.length()-1;
    int product[pl] = {0};
    for(int i=0;i<fx.length();i++)
    {
        for(int j=0;j<gx.length();j++)
        {
            product[i+j]+=fxarr[i]*gxarr[j];
        }
    }
    //cout<<last(product,pl);
    //for(int i=0;i<pl;i++)
    //product[i]=product[i]%2;
    int final[pl];
    for(int i=0;i<fx.length()+gx.length()-1;i++)
    {
       //product[i]=product[i]%2;
      cout<<product[i];
    }
    //while(last(product,pl)>=last(mxarr,ml))
   // {
    //    int shift=last(product,pl)-last(mxarr,ml);
        //cout<<shift;
     //   for(int i=0;i<pl;i++)
     //   {
     //       if(i-shift>=0)
      //      product[i]=product[i]+mxarr[i-shift];
      //      else
       //     {
       //         continue;
       //     }
            
       // }
        //for(int i=0;i<pl;i++)
        //cout<<product[i];
    //}
    //for(int i=0;i<fx.length()+gx.length()-1;i++)
    //{
     // product[i]=product[i]%2;
    //  cout<<product[i]<<endl;
   // }
    
    return 0;
}