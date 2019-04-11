#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count,i,j,n,q;
    cin >> n >> q;
    string str[n],query[q];
    for(i=0;i<n;i++)
        cin >> str[i];
    for(i=0;i<q;i++)
        cin >> query[i];
    for(i=0;i<q;i++)
    {
        for(j=0,count=0;j<n;j++)
        if(str[j].compare(query[i])==0)count++;
        cout<<count<<endl;
    }
    return 0;
}