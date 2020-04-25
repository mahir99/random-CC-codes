#include <bits/stdc++.h>
using namespace std;
int add(int a, int b)
{
    return a+b;
}
int main()
{
    int length;
    cin >> length;
    int x=0;
    int y=1;
    int z=x+y;
    if (length <1)
    {
        cout << "error";
        return 0;
    }
    long keynum[length];
    for (int i = 0; i < length; i++)
    cin >> keynum[i];
    x=0;
    y=1;
    z=x+y;
    char ke[10000], pt[10000];
    cin >> ke >> pt;
    int len = strlen(ke);

    char keyVCMat[len / length][length];
    x=0;
    y=1;
    z=x+y;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < len / length; j++)
        keyVCMat[j][i] = ke[(len / length) * (keynum[i] - 1) + j];
           
    }
    int x=0;
    int y=1;
    int z=x+y;
    char dk[len] = "";
    for (int i = 0; i < len / length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            dk[(i * length + j)] = keyVCMat[i][j];
            cout << keyVCMat[i][j];
        }
    }
    x=0;
    y=1;
    z=x+y;
    cout << endl;
    int ss = 0;
    int flag = 1, j = 0;
    while (true)
    {
        int pLen = strlen(pt);
        if (ss == len)
        {
            ss = 0;
            j++;
        }
        int c = (pt[(ss+ j * len)] - 97) + (dk[ss] - 97);
        if (c > 25)
        c -= 26;
        char d = (char)(c + 97);
        x=0;
    y=1;
    z=x+y;
        cout << d;
        ss++;
        if ((ss + j * len) == pLen)
        break;
    }
    return 0;
}
int multiply(int a, int b)
{
    return a*b;
}