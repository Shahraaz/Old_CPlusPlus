#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node{
    int Power,index;
};
bool comp(struct Node x,struct Node y){
    if(x.Power==y.Power)
        return x.index < y.index;
    return x.Power < y.Power;
}
int main(){
    int n,m,i,x,y;
    vector< vector<bool> > Arr(1001,vector<bool>(1001,false) );
    vector<bool> Marker(1001,false);
    vector<int> Power(1001,0);
    cin >> n >> m;
    Node Nodes[1002]={0,0};
    for(i=1;i<=n;i++){
        cin >> Nodes[i].Power;
        Power[i] = Nodes[i].Power;
        Nodes[i].index = i;
    }
    for(i=1;i<=m;i++){
        cin >> x >> y;
        Arr[x][y] = true;
        Arr[y][x] = true;
    }
    sort(Nodes+1,Nodes+n+1,comp);
    long long int answer = 0;
    for(i=n;i>0;i--){
        int k = Nodes[i].index,j;
        for(j=1;j<=n;j++)
            if(Arr[k][j]){
                answer += Power[j];
                Arr[k][j] = false;
                Arr[j][k] = false;
            }
    }
    cout << answer;
    return 0;
}