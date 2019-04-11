#include <iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,m,x,y,Know,Power;
    cin >> t;
    while(t--){
        Power = Know = 1;
        cin >> n >> m >> x >> y ;
        Know = 1+(n-1)/x*x;
        Power = 1+(m-1)/y*y;
        if(Know == n & Power == m)
            cout << "Chefirnemo";
        else if(Know+1 == n & Power+1 == m)
            cout << "Chefirnemo"; 
        else if(Know-x > 0 & Know-x+1 == n & Power+1 == m)
            cout << "Chefirnemo";
        else if(Power-y > 0 & Know+1 == n & Power-y+1 == m)
            cout << "Chefirnemo";
        else if(Know-x > 0 & Power-y > 0 & Know-x+1 == n & Power-y+1 == m)
            cout << "Chefirnemo";
        else cout << "Pofik";
        cout << '\n' ;
    }
	return 0;
}
