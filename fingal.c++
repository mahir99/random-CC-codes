#include<bits/stdc++.h>
using namespace std;
int fl,gl,ml,pl;
void rightRotatebyOne(int a[],int n) 
{ 
    int temp=a[n-1];
    for(int i=n-1;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=temp; 
} 
void rightRotate(int arr[], int d, int x) 
{ 
    for (int i = 0; i < d; i++) 
        rightRotatebyOne(arr, x); 
}
void reduce(int a[],int n)
{
    for(int i=0;i<n;i++)
    a[i]=a[i]%2;
}
int last(int a[],int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    if(a[i]==1)
    break;
    return i;
}
int main()
{
    string fx,gx,mx;
    cin>>fx>>gx>>mx;
    fl=fx.length();
    gl=gx.length();
    ml=mx.length();
    pl=fl+gl-1;
    int fxarr[fx.length()],gxarr[gx.length()],mxarr[pl];
    for(int i=0;i<fl;i++)
    {
        fxarr[i]=fx.at(fl-i-1)-48;
    }
    for(int i=0;i<gl;i++)
    {
        gxarr[i]=gx.at(gl-i-1)-48;
    }
    for(int i=0;i<ml;i++)
    {
        mxarr[i]=mx.at(ml-i-1)-48;
    }
    for(int i=ml;i<pl;i++)
    {
        mxarr[i]=0;
    }
    int product[fl+gl-1];
    for(int i=0;i<pl;i++)
    {
        product[i]=0;
    }
    for (int i=0; i<fl; i++) 
    { 
     for (int j=0; j<gl; j++) 
        product[i+j] += fxarr[i]*gxarr[j]; 
    } 
    reduce(product,pl);
   //for(int i=0;i<pl;i++)
   //cout<<product[i]<<endl;

   while(last(product,pl)>last(mxarr,ml))
   {
       int shift=last(product,pl)-last(mxarr,ml);
       //cout<<shift<<endl;
       rightRotate(mxarr,shift,pl);
       for(int i=0;i<pl;i++)
       {
           product[i]+=mxarr[i];
       }
       reduce(product,pl);
   }
   for(int i=last(product,pl);i>=0l;i--)
   {
       cout<<product[i];
   }

   return 0;
} 