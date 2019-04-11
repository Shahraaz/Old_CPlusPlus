//Optimise Yourself
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n,a,b,x,c1,c2,c3;
    cin >> n >> a >> b;
    c1 = c2 = c3 = 0;
    while(n--){
        cin >> x ;
        if(x<=a) c1++;
        else if(x>b) c3++;
        else c2++;
    }
    cout << min(c1,min(c2,c3));
    return 0;
}