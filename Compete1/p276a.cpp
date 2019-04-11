//Optimise 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int cnt(int a)
{
    if(a==0)
        return 0;
    return (a&1) + cnt(a>>1); 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll a,m;
    cin >> a >> m;
    a %= m;
    ll two = 1;
    for(int i=0;i<32;++i)
    {
        a *= two;
        a %= m;
        if(a==0)
        {
            cout << "Yes";
            return 0;
        }
        two *= 2;
        two %= m;
    }
    cout << "No";
    return 0;
}