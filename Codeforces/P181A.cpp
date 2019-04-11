#include<iostream>
#include<vector>
using namespace std;
int main(){
    int i,n,zerocount=0,negcount=0,poscount=0,temp,prneg;
    cin >> n;
    vector<int> Neg,Pos;
    while(n--){
        cin >> temp;
        if(temp<0) Neg.push_back(temp),negcount++;
        else if(temp>0) Pos.push_back(temp),poscount++;
        else zerocount++;
    }
    cout << 1 << ' ' << Neg[0] << '\n';
    prneg = (negcount-1)/2;
    cout << prneg*2 + poscount << ' ' ; 
    for(i=1;i<=prneg*2;i++)
        cout << Neg[i] << ' ';
    for(i=0;i<poscount;i++)
        cout << Pos[i] << ' ';
    cout << '\n';
    cout << zerocount + ((negcount-1)&1) << ' ';
    for(i=0;i<zerocount;i++)
        cout << "0 ";
    if((negcount-1)&1) cout << Neg[negcount-1];
    return 0;
}