#include<iostream>
using namespace std;
struct Matrix{
    long long **arr ,mod=1e9+7;
    Matrix (){
        arr = new long long int* [2];
        arr[0] = new long long int[2];
        arr[1] = new long long int[2];
        arr[0][0] = 1; arr[0][1] = 0;
        arr[1][0] = 0; arr[1][1] = 1;
    }
    void operator * (Matrix &temp){
        Matrix res ;
        res.arr[0][0] = ((arr[0][0]*temp.arr[0][0])%mod + (arr[0][1]*temp.arr[1][0])%mod)%mod;
        res.arr[0][1] = ((arr[0][0]*temp.arr[0][1])%mod + (arr[0][1]*temp.arr[1][1])%mod)%mod;
        res.arr[1][0] = ((arr[1][0]*temp.arr[0][0])%mod + (arr[1][1]*temp.arr[1][0])%mod)%mod;
        res.arr[1][1] = ((arr[1][0]*temp.arr[0][1])%mod + (arr[1][1]*temp.arr[1][1])%mod)%mod;
        arr[0][0] = res.arr[0][0];arr[0][1] = res.arr[0][1];
        arr[1][0] = res.arr[1][0];arr[1][1] = res.arr[1][1];
    }
    void power(Matrix &result,Matrix &Mat,int index){
        if(index==0){
            result.arr[0][0] = 1 ;result.arr[1][0] = 0 ;
            result.arr[0][1] = 0 ;result.arr[1][1] = 1 ;
            return ;
        }
        Matrix temp ;
        power(temp,Mat,index/2);
        temp*temp;
        if(index&1) temp*Mat;
        result.arr[0][0] = temp.arr[0][0] ;    
        result.arr[0][1] = temp.arr[0][1] ;
        result.arr[1][0] = temp.arr[1][0] ;
        result.arr[1][1] = temp.arr[1][1] ;
    }
    ~Matrix(){
        delete(arr[0]);
        delete(arr[1]);
        delete(arr);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long  t,n,a,b,mod=1e9+7;
    cin >> t;
    while(t--){
        cin >> a >> b >> n;
        if(n==0) cout << a;
        else if(n==1) cout << b;
        else{
            Matrix Mat,temp; 
            Mat.arr[0][0] = 1 ;Mat.arr[1][0] = 1 ;
            Mat.arr[0][1] = 1 ;Mat.arr[1][1] = 0 ;
            temp.power(temp,Mat,n-1);
            cout << ((a*temp.arr[1][0])%mod + (b*temp.arr[0][0])%mod)%mod ; 
        }        
        cout << '\n';
    }
    return 0;
}