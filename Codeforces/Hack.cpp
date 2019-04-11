#include <iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
pair<int,int> cloud[100002];
pair<int,int> town[200002];
/*int lower(int *arr,int low,int high,int key){
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
    return low;
}*/
// Complete the maximumPeople function below.
long long maximumPeople(int tsize,int csize){
    sort(town,town+tsize);
    sort(cloud,cloud+csize);
    int tstart[tsize];
    vector<int> Hash(tsize,0);
    vector<long long> sum(tsize,0);
    int i,j;
    for(i=0;i<tsize;i++)
        tstart[i] = town[i].first;
    for(i=0;i<csize;i++){
        int *low = lower_bound(tstart,tstart+tsize,cloud[i].first-cloud[i].second);
        int *up = upper_bound(tstart,tstart+tsize,cloud[i].first+cloud[i].second);
        Hash[low-tstart]++;
        Hash[up-tstart]--;
    }
    if(Hash[0]==1) sum[0] = town[0].second; 
    for(i=1;i<tsize;i++){
        Hash[i] += Hash[i-1] ;
        sum[i] += sum[i-1] + (Hash[i]==1)? town[i].second : 0;
    }
    long long int answer = 0,max=0,curr;
    for(i=0;i<tsize;i++)
        if(Hash[i]==0) answer += town[i].second;
    //fout << answer << '\n';
    for(i=0;i<csize;i++){
        int low = lower_bound(tstart,tstart+tsize,cloud[i].first-cloud[i].second) - tstart;
        int up = upper_bound(tstart,tstart+tsize,cloud[i].first+cloud[i].second) - tstart;
        if(low==0)
            curr = (up==0) ? 0 : sum[up-1];
        else curr = sum[up-1] - sum[low-1];
        if(curr>max) max = curr;
        //fout << "max " << max << '\n';
    }    
    return answer + max;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> town[i].second;
    for (int i = 0; i < n; i++) 
        cin >> town[i].first ;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> cloud[i].first ;
    for (int i = 0; i < m; i++) {
        cin >> cloud[i].second;
    }
    long long result = maximumPeople(n,m);
    cout << result << "\n";
    return 0;
}
