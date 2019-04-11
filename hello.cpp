#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int flag;
    for(int i=3;i<128;i+=2)
    {
        
        flag = 0;
        for(int j=3;j*j<=i;j+=2)
        {
            if(i%j==0)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0) printf("%d, ",i);
    }
}
