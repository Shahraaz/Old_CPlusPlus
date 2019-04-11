#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,i;
    cin >> n;
    vector<int> Vect(n);
    for(i=0;i<n;i++)
        cin >> Vect[i];
    sort(Vect.begin(),Vect.end());
    if(Vect[0]==Vect[n-1]) cout << 0 << ' ' <<n *(n-1)/2;
    else{
        int c1=0,c2=0;
        for(i=0;i<n;i++)
            if(Vect[i]==Vect[0])    c1++;
            else break;
        for(i=0;i<n;i++)
            if(Vect[n-i-1]==Vect[n-1])    c2++;
            else break;
        cout << Vect[n-1] - Vect[0] <<' '<< c1*c2 ;
    }
    return 0;
}