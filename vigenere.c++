#include <bits/stdc++.h> 
using namespace std; 
int kk[2][2];
void multiply(int mat1[][2],  
              int mat2[][2],  
              int res[][2]) 
{ 
    int i, j, k; 
    for (i = 0; i < 2; i++) 
    { 
        for (j = 0; j < 2; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < 2; k++) 
                res[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
        } 
    } 
} 
int main()
{
    string decrypt;
    string th,he;
    cin>>decrypt;
    cin>>th>>he;
    int cinv[2][2];
    cinv[1][1]=th.at(0)-65;
    cinv[1][0]=-(th.at(1)-65);
    cinv[0][1]=-(he.at(0)-65);
    cinv[0][0]=he.at(1)-65;
    int d=(cinv[0][0]*cinv[1][1])-(cinv[0][1]*cinv[1][0]);
    int i;
    for(i=1;i<=25;i++)
    {
        if((i*d)%26==1)
        break;
    }
    int keyinv[2][2];
    int pt[2][2];
    pt[0][0]=19;
    pt[0][1]=7;
    pt[1][0]=7;
    pt[1][1]=4;
    multiply(pt,cinv,kk);
    keyinv[0][0]=(i*kk[0][0])%26;
    keyinv[0][1]=(i*kk[0][1])%26;
    keyinv[1][0]=(i*kk[1][0])%26;
    keyinv[1][1]=(i*kk[1][1])%26;

    if(decrypt.length()%2==1)
    {
        decrypt.append("Z");
    }
    for(int j =0; j<decrypt.length()-1; j+=2)
    {
        int a = (keyinv[0][0]*(decrypt.at(j)-65) + keyinv[0][1]*(decrypt.at(j+1)-65))%26;
        int b = (keyinv[1][0]*(decrypt.at(j)-65) + keyinv[1][1]*(decrypt.at(j+1)-65))%26;
        cout<<(char)(a+65)<<(char)(b+65);
    }







}
