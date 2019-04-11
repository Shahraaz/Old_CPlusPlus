#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> Lucky(1024);
int index = 0;
long int Power(int power){
    if(power==0) return 1;
    long int temp = Power(power/2);
    temp = temp * temp;
    if(power&1) return temp*10;
    return temp;
}
void Generate_Lucky(int size){
    if(size>8) return;
    int j,i,length = index;
    long int limit=Power(size-1);
    for(i=0;i<length;i++){
        if(Lucky[i] >= limit) break;
    }
    limit = Power(size);
    j=i;
    for(;i<length;i++)
        Lucky[index++] = (4*limit+Lucky[i]);
    for(i=j;i<length;i++)
        Lucky[index++] = (7*limit+Lucky[i]);
    Generate_Lucky(size+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Lucky[index++] = (4);
    Lucky[index++] = (7);
    Lucky[index++] = (44);
    Lucky[index++] = (47);
    Lucky[index++] = (74);
    Lucky[index++] = (77);
    Generate_Lucky(2);
    int l,r,i,length = index;
    Lucky[index++] = (1000000001);
    cin >> l >> r;
    for(i=0;i<length;i++)
        if(Lucky[i]>=l) break;
    unsigned long long int sum = 0;
    for(l;l<=r;l++){
        if(l>Lucky[i] || i>=length){i++;if(i>=length)break;}
        sum += Lucky[i];
    } 
    if(l<=r)
        sum += (long long)4444444444*(r-l+1);
    cout << sum;
    return 0;
}