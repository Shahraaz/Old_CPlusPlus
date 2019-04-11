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
    ll n;
    cin >> n;
    string A,B,C;
    cin >>A >> B >> C;
    ll cnt = 0;
    for(ll i =0;i<n;i++)
        if(A[i]==B[i])
        {
            if(B[i]!=C[i])
                cnt++;
        }
        else if(A[i]==C[i])
        {
            if(B[i]!=C[i])
                cnt++;
        }
        else if(B[i]==C[i])
        {
            if(A[i]!=B[i])
                cnt++;
        }
        else cnt += 2;
    cout << cnt ;
    return 0;
}