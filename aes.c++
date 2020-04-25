#include<bits/stdc++.h>
using namespace std;
const string S_Box[16][16] = {  
    {"63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"},  
    {"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"},  
    {"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"},  
    {"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"},  
    {"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"},  
    {"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"},  
    {"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"},  
    {"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"},  
    {"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"},  
    {"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"},  
    {"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"},  
    {"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"},  
    {"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"},  
    {"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"},  
    {"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"},  
    {"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"}  
};
const string Rcon[10] = {"01000000", "02000000", "04000000", "08000000", "10000000",  
                 "20000000", "40000000", "80000000", "1B000000", "36000000"};
void leftRotatebyOne(char arr[],int x) 
{ 
    char temp = arr[0], i; 
    for (i = 0; i < x - 1; i++) 
        arr[i] = arr[i + 1]; 
  
    arr[i] = temp; 
} 
void leftRotate(char arr[], int d, int x) 
{ 
    for (int i = 0; i < d; i++) 
        leftRotatebyOne(arr, x); 
}
string DectoHex(int n)
{
    string s="";
    int r=n%16;
    int q=n/16;
    if(q==10)
    s.append("A");
    else if(q==11)
    s.append("B");
    else if(q==12)
    s.append("C");
    else if(q==13)
    s.append("D");
    else if(q==14)
    s.append("E");
    else if(q==15)
    s.append("F");
    else if(q==1)
    s.append("1");
    else if(q==2)
    s.append("2");
    else if(q==3)
    s.append("3");
    else if(q==4)
    s.append("4");
    else if(q==5)
    s.append("5");
    else if(q==6)
    s.append("6");
    else if(q==7)
    s.append("7");
    else if(q==8)
    s.append("8");
    else if(q==9)
    s.append("9");
    if(r==10)
    s.append("A");
    else if(r==11)
    s.append("B");
    else if(r==12)
    s.append("C");
    else if(r==13)
    s.append("D");
    else if(r==14)
    s.append("E");
    else if(r==15)
    s.append("F");
    else if(r==1)
    s.append("1");
    else if(r==2)
    s.append("2");
    else if(r==3)
    s.append("3");
    else if(r==4)
    s.append("4");
    else if(r==5)
    s.append("5");
    else if(r==6)
    s.append("6");
    else if(r==7)
    s.append("7");
    else if(r==8)
    s.append("8");
    else if(r==9)
    s.append("9");
    
    return s;
}
int main()
{
    int n;
    cin>>n;
    string ss=DectoHex(n);
    cout<<ss;
    return 0;
}
int HextoDec(char c)
{
    if (c == 'a')
        return 10;
        else if(c=='b')
        return 11;
        else if(c=='c')
        return 12;
        else if(c=='d')
        return 13;
        else if(c=='e')
        return 14;
        else if(c=='f')
        return 15;
        else
        return c-48;
}
void roundkey(char arr[],int n,int round)
{
    
}
int main()
{
    string pt,k;
    string key[10];
    cin>>pt>>k;
    char w0[8];
    char w1[8];
    char w2[8];
    char w3[8];
    int i=0,s=0;
    for(i=0;i<8;i++)
    {
        w0[i]=k.at(i);
    }
    for(i=0;i<8;i++)
    {
        w1[i]=k.at(i+8);
    }
    for(i=0;i<8;i++)
    {
        w2[i]=k.at(i+16);
    }
        for(i=0;i<8;i++)
    {
        w3[i]=k.at(i+24);
    }
    leftRotate(w0,2,8);
    leftRotate(w1, 2, 8);
    leftRotate(w2, 2, 8);
    leftRotate(w3, 2, 8);
    for(int i=0;i<8;i+=2)
    {
        char t1=S_Box[HextoDec(w0[i])][HextoDec(w0[i+1])].at(0);
         char t2=S_Box[HextoDec(w0[i])][HextoDec(w0[i+1])].at(1);
         w0[i]=t1;
         w0[i+1]=t2;
    }
    for(int i=0;i<8;i+=2)
    {
        char t1=S_Box[HextoDec(w1[i])][HextoDec(w1[i+1])].at(0);
         char t2=S_Box[HextoDec(w1[i])][HextoDec(w1[i+1])].at(1);
         w1[i]=t1;
         w1[i+1]=t2;
    }
    for(int i=0;i<8;i+=2)
    {
        char t1=S_Box[HextoDec(w2[i])][HextoDec(w2[i+1])].at(0);
         char t2=S_Box[HextoDec(w2[i])][HextoDec(w2[i+1])].at(1);
         w2[i]=t1;
         w2[i+1]=t2;
    }
    for(int i=0;i<8;i+=2)
    {
        char t1=S_Box[HextoDec(w3[i])][HextoDec(w3[i+1])].at(0);
         char t2=S_Box[HextoDec(w3[i])][HextoDec(w3[i+1])].at(1);
         w3[i]=t1;
         w3[i+1]=t2;
    }
    int ab=0,rc=0,res;
    ab+=HextoDec(w0[0])*16 + HextoDec(w0[1]);
    rc+=HextoDec(Rcon[0].at(0))*16 + HextoDec(Rcon[0].at(1));
    res=ab^rc;
    string zz=DectoHex(res);
    w0[0]=zz.at(0);
    w0[1]=zz.at(1);
    return 0;
}

