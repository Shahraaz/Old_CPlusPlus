#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string dictionary[100],modernphrases[2500];
int binarysearch(int pos,int left,int right)
{
    int mid ;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(dictionary[pos]==modernphrases[mid])
            return mid;
        if(dictionary[pos]<modernphrases[mid])
            right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
int main()
{
    int t,n,k,l,i,count,pos;
    cin >> t;
    while(t--)
    {
        count = 0;
        cin >> n >> k;
        for(i=0;i<n;i++)
            cin >> dictionary[i];
        while(k--)
        {
            cin >> l;
            while(l--)
                cin >> modernphrases[count++];
        }
        sort(modernphrases,modernphrases+count);
        for(i=0;i<n;i++)
        {
            pos = binarysearch(i,0,count-1);
            if(pos>-1)
                cout << "YES ";
            else cout << "NO ";
        }
        cout << endl;
    }
    return 0;
}
