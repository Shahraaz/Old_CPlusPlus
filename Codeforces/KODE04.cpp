#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int w,z,i,ni,j,temp;
    long long int count = 0;
    cin >> w >> z;
    vector<int> Vect(w);
    for(i=0;i<w;i++)
        cin >> Vect[i];
    for(i=0;i<z;i++){
        cin >> ni;
        for(j=0;j<ni;j++){
            cin >> temp;
            if(Vect[temp-1]>0){
                count++;
                Vect[temp-1]--;
            }
        }
    }
    cout << count;
    return 0;
}