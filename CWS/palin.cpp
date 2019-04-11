#include<iostream>
#include<cstring>
using namespace std;
void addbin(char* s,int n)
{      
    if(n==0)
    { 
        s[0]=='9';
        return;
    }
    if(s[n]=='9')
    {
        s[n] = '0';
        return addbin(s,n-1);
    }
    s[n]++;
}
int main()
{
    int t,i,len,flag;
    char num[1000001],num2[1000001];
    cin >> t;
    while(t--)
    {
        cin >> num;
        for(len=0;num[len];len++);
        for(i=0,flag=0;i<len/2;i++)
            if(num[i]!=num[len-i-1])
            {
                flag = 1;
                break;
            }
        if(flag)
        {
            addbin(num,len/2-(len+1)%2);
            for(i=len/2+len%2;i<len;i++)
                num[i] = num[len-i-1] ;
            cout << num << endl ;
        }
        else
        {
            if()num[len/2-(len+1)%2]
        }
    }
    return 0;
}