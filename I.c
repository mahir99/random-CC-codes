#include<stdio.h>
#include<stdlib.h>

int main()
{
    char x[100];
    scanf("%s",&x);
    printf("%d",sizeof(x)/sizeof(x[0]));
}