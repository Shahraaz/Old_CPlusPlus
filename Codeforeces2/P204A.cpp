#include<iostream>
using namespace std;
int main()
{
    int n,i,count0=0,count5=0,temp;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> temp;
        if(temp==0) count0++;
        else count5++;
    }
    if(count0==0) cout << -1;
    else{
        if(count5<9)    cout << 0;
        else{
            for(i=0;i<count5/9;i++)
                cout<<"555555555";
            for(i=0;i<count0;i++)
                cout << '0';
        }
    }
    return 0;
}
