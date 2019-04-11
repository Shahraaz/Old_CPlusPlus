#include<iostream>
#include<string>
using namespace std;
int main(){
    int t,sx,sy,ex,ey,i;
    string temp;
    cin >> t >> sx >> sy >> ex >> ey;
    cin >> temp;
    int stepe ,stepn;
    stepe = ex - sx;
    stepn = ey - sy;
    for(i=0;i<t;i++){
        if(temp[i]=='W'&& stepe < 0) stepe++;
        else if(temp[i]=='E'&& stepe > 0) stepe--;
        else if(temp[i]=='S'&& stepn < 0) stepn++;
        else if(temp[i]=='N'&& stepn > 0) stepn--;
        if(stepe==0 && stepn==0){
            cout << i+1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}