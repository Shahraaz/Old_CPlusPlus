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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ld n,r;
    cin >> n >> r;
    cout <<setprecision(8)<< fixed << r*sin(3.14159265358/n)/(1-sin(3.14159265358/n));
    return 0;
}