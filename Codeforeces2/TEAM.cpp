#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t,n,mod =1e9+7,i;
    cin >> t;
    while(t--){
        cin >> n; 
        vector<int> arr(n);
        for(i=0;i<n;i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end());
        long long int count = 1;
        for(i=n-1;i>=0;){
            /*for(int j=0;j<n;j++)
                cout << arr[j] << ' ';
            cout << '\n';*/
            while(i>=0 && arr[i]==0) i--;
            int value = arr[i],vctr=1;
            if(i>=0){
                i--;
                while(i>=0 && arr[i]==value){
                    i--;
                    vctr++;
                }
                vctr = vctr % mod;
                if(vctr&1){
                    while(i>=0 && arr[i]==0) i--;
                    if(i>=0){
                        int value2 = arr[i],vctr2=1,j2=i-1;
                        while(j2>=0 && arr[j2]==value2){
                            if(arr[j2])vctr2++;
                            j2--;
                        }
                        vctr2 %= mod;
                        arr[i] = 0;
                        count = (count*((long long)vctr * vctr2)%mod)%mod;
                    }    
                }
            }
            vctr = (vctr/2*2);
            //cout << vctr << '\n';
            if(vctr>1)
            count = (count*((long long)vctr*(vctr-1)/2)%mod)%mod;
            //cout << "Count "<< count << '\n';
        }
        cout << count << '\n';
    }
    return 0;
}