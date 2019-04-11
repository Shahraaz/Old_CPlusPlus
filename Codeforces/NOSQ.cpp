#include<iostream>
#include<vector>
using namespace std;
vector<int> Vect(1000001,1);
int arr[1000001][10] = {0};
void Con(){
    int count = 1,i,j;
    for(i=2;i<=1000;++i){
        int temp = i*i; 
        for(j=temp;j<=1000000;j+=temp)
            Vect[j] = 0;
    }
    for(i=1;i<=1000000;++i)
        if(Vect[i]){
            int num = i,arr2[10]={0};
            for(;num;num/=10)
                arr2[num%10] = 1;
            for(num=0;num<10;++num)
                arr[i][num] = arr2[num] + arr[i-1][num] ;
        }
        else{
            for(int num=0;num<10;++num)
                arr[i][num] = arr[i-1][num] ;
        } 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Con();
    int t,a,b,d;
    cin >> t;
    while(t--){
        cin >> a >> b >> d;
        cout << arr[b][d] - arr[a-1][d];
        cout << '\n';
    }
}