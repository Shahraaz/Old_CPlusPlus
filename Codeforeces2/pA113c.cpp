#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
class city{
    public :
    int prefecture,year,index,indexi;
};
bool cmp(city a,city b){
    return a.year < b.year;
}
bool cmp2(city a,city b){
    return a.index < b.index;
}
int main(){
    int n,m,temp1,temp2,i;
    cin >> n >> m;
    vector< city > Vect(m);
    for(i=0;i<m;i++){
        cin >> temp1 >> temp2;
        Vect[i].prefecture = temp1;
        Vect[i].year = temp2;
        Vect[i].index = i;
    }
    sort(Vect.begin(),Vect.end(),cmp);
    vector<int> Vect2(n+1);
    for(i=1;i<n+1;i++) Vect2[i] = 0;
    for(i=0;i<m;i++){
        Vect2[Vect[i].prefecture]++;
        Vect[i].indexi = Vect2[Vect[i].prefecture];
    }
    sort(Vect.begin(),Vect.end(),cmp2);
    for(i=0;i<m;i++)
        printf("%06d%06d\n",Vect[i].prefecture,Vect[i].indexi);
    return 0;
}