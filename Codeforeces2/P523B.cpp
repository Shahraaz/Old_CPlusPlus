#include<iostream>
#include<algorithm>
using namespace std;
int lower(int *arr,int low,int high,int key){
    int mid ,result=-1;
    while(low<=high){
        // cout << low << " Low " << high << endl;
        mid = (low+high)/2;
        if(key==arr[mid]){
            result = mid;
            high = mid-1;
        }
        else if(key<arr[mid]) high = mid-1;
        else low = mid+1;
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int arr[n+1],i,j,count,key;
    unsigned long long int answer;
    arr[0] = 0;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    sort(arr+1,arr+n+1);
    answer=0;
    for(i=n;i>1;){
        if(arr[i]==1) break;
        int low = lower(arr,1,i,arr[i]);
        // cout << low << endl;
        if(low<i){
            while(arr[low]>1 && low<i && arr[low]>arr[low-1]){ 
                // cout << - low + i << " Low-i\n" << --arr[low] << " arr[low]--\n";
                answer -= low - i;
                answer += --arr[low];
                i--;
            }
            arr[i] = arr[low];
        }
        else if(low==i){
            // cout << low << " Low=i\n";
            answer += arr[i-1];
            i--;
        }
    }
    cout << answer;
    return 0;
}