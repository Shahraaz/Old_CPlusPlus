#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    vector< pair<int,int> > Vect(2);
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2 ;
    Vect[0].first = x1;
    Vect[0].second = y1;
    Vect[1].first = x2;
    Vect[1].second = y2;
    sort(Vect.begin(),Vect.end());
    if((Vect[0].first==Vect[1].first) && (Vect[0].second==Vect[1].second))
        cout << -1 << "Here";
    else if(Vect[0].first==Vect[1].first)
        cout << Vect[0].first + (Vect[1].second-Vect[0].second)<< ' ' << Vect[0].second << ' ' << Vect[1].first + (Vect[1].second-Vect[0].second)<< ' ' << Vect[1].second ;
    else if(Vect[0].second==Vect[1].second)
        cout << Vect[0].first << ' ' << Vect[0].second + (Vect[1].first-Vect[0].first)<< ' ' << Vect[1].first << ' ' << Vect[1].second + (Vect[1].first-Vect[0].first);
    else if(abs(Vect[0].first-Vect[1].first) == abs(Vect[0].second-Vect[1].second))
        cout << Vect[0].first << ' ' << Vect[1].second << ' ' << Vect[1].first << ' ' << Vect[0].second ;
    else cout << -1;    
    return 0;
}