#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    if(k>=n/2) cout << 1 << '\n' << (n+1)/2 ;
    else{
        int mincount = 1,i,j;
        vector<int> minvect ;
        minvect.push_back(1);
        while(minvect[mincount-1]+2*k+1<=n){
            minvect.push_back(minvect[mincount-1]+2*k+1);
            mincount++;
        }
        for(j=2;j<=k+1;j++){
            int count = 1;
            vector<int> vect ;
            vect.push_back(j);
            while(vect[count-1]+2*k+1<=n){
                vect.push_back(vect[count-1]+2*k+1);
                count++;
            }
            if(vect[count-1]+2*k+1<=n)
            if(mincount>count){
                mincount = count;
                minvect = vect;
            }
        }
        cout << mincount <<'\n';
        for(i=0;i<mincount;i++)
            cout << minvect[i] << " ";
    }
    return 0;
}