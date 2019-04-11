#include <iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main() {
    ull t,n,s,a,b,i,x;
    cin >> t;
    while(t--){
        cin >> n >> x >> s;
        while(s--){
            cin >> a >> b;
            if(a==x) x = b;
            else if(b==x) x = a;
        }
        cout << x << '\n';
    }
	return 0;
}
