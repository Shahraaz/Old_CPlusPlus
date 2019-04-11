#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> Prime;
void ConstrSeive(){
    vector<bool> Arr(1000000,true);
    int i,j;
    for(i=4;i<1000000;i+=2)
        Arr[i] = false;
    for(i=3;i<=1000;i+=2)
        if(Arr[i])
            for(j=i*i;j<=1000000;j+=i)
                Arr[j] = false;
    Prime.push_back(2);
    for(i=3;i<=1000000;i+=2)
        if(Arr[i]) Prime.push_back(i);    
}
int Constr(int *Tree,int *arr, int start,int end,int index){
    if(start==end){
        int i;
        if(arr[start]==1) return Tree[index] = 1;
        else 
            for(i=0;Prime[i]<=arr[start]&&i<Prime.size();i++)
                if(arr[start]%Prime[i]==0)
                   return Tree[index] = Prime[i];
    }
    else{
        int mid = (start+end)/2;
        return Tree[index] = max (Constr(Tree,arr,start,mid,2*index),Constr(Tree,arr,mid+1,end,2*index+1));
    }
}
int Update(int *Tree,int *arr, int l,int r,int start,int end,int index){
    if( end<l || start>r ) return 1;
    if(l<=start && r>=end){
        if(start==end){
            int i;
            if(arr[start]==1) return Tree[index] = 1;
            else{
                    arr[start] /= Tree[index];
                    if(arr[start]==1) return Tree[index] = 1;
                    auto low = lower_bound(Prime.begin(),Prime.end(),Tree[index]);
                    for(i=low-Prime.begin();Prime[i]<=arr[start]&&i<Prime.size();i++)
                        if(arr[start]%Prime[i]==0)
                            return Tree[index] = Prime[i];
            }
        }
    }
    int mid = (start+end)/2;
    return Tree[index] = max (Update(Tree,arr,l,r,start,mid,2*index),Update(Tree,arr,l,r,mid+1,end,2*index+1));
}
int Maxextr(int *Tree,int l, int r,int segstart, int segend,int index){
    if(l<=segstart && r>=segend)
        return Tree[index];
    if(segend < l || segstart > r) return 1;
    int mid = (segstart + segend)/2;
    return max(Maxextr(Tree,l,r,segstart,mid,2*index),Maxextr(Tree,l,r,mid+1,segend,2*index+1));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,i,type,l,r;
    cin >> t;
    ConstrSeive();
    while(t--){
        int Tree[1<<16],arr[100000];
        cin >> n >> m;
        for(i=1;i<=n;i++)
            cin >> arr[i];
        Constr(Tree,arr,1,n,1);
        while(m--){
            cin >> type>> l>> r;
            if(type)
                cout << Maxextr(Tree,l,r,1,n,1) << ' ';
            else Update(Tree,arr,l,r,1,n,1) ;
        }
        cout << '\n';
    }
    return 0;
}