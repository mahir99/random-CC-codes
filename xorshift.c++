#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ct;
    cin>>ct;
    int ctn=ct.length();
    int ptn=(ctn+1)/2;
    int ctarr[ctn];
    //cout<<ptn<<ctn;
    for(int i=0;i<ctn;i++)
    {
        if(ct.at(i)=='a')
        ctarr[i]=10;
        else if(ct.at(i)=='b')
        ctarr[i]=11;
        else if(ct.at(i)=='c')
        ctarr[i]=12;
        else if(ct.at(i)=='d')
        ctarr[i]=13;
        else if(ct.at(i)=='e')
        ctarr[i]=14;
        else if(ct.at(i)=='f')
        ctarr[i]=15;
        else
        ctarr[i]=ct.at(i)-48;
    }
    int ptarr[ptn];
    ptarr[0]=ctarr[0];
    
    for(int i=1;i<ptn;i++)
    {
        int x=0;
        for(int j=0;j<i;j++)
        x^=ptarr[j];
        ptarr[i]=x^ctarr[i];
    }
    //for(int i=0;i<ctn;i++)
    //{
      //cout<<ctarr[i]<<endl;
    //}

    for(int i=0;i<ptn;i++)
    {
        if(ptarr[i]<10)
        cout<<ptarr[i];
        else if(ptarr[i]==10)
        cout<<'a';
        else if(ptarr[i]==11)
        cout<<'b';
        else if(ptarr[i]==12)
        cout<<'c';
        else if(ptarr[i]==13)
        cout<<'d';
        else if(ptarr[i]==14)
        cout<<'e';
        else if(ptarr[i]==15)
        cout<<'f';
    }
}
