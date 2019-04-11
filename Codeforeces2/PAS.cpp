#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<bool> Vect(10000001,true);
vector<long long int> arr(10000001,10000001);
void Con(){
    int count = 1,i,j;
    Vect[0] = Vect[1] = false;
    arr[0] = arr[1] = 0L;
    arr[2] = 2L;
    for(j=4;j<=10000000;j+=2){
        Vect[j] = false;
        arr[j] = 2;
    }
    for(i=3;i<=3163;i+=2)
        if(Vect[i]){
            arr[i] = i;
            for(j=i*i;j<=10000000;j+=i){
                Vect[j] = false;
                arr[j] = min(arr[j], (long long)i);
            }
        }
    for(i=3165;i<=10000000;i+=2)
        if(Vect[i])
            arr[i] = min(arr[i], (long long)i);
    for(i=1;i<=10000000;i++)
        arr[i] += arr[i-1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Con();
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << arr[(long long)n];
        cout << '\n';
    }
}