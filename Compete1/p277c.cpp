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
    int n , p;
    cin >> n >> p;
    p--;
    string str;
    cin >> str;
    vector<int> Vect(n);
    for(int i=0;i<=(n/2);++i)
        Vect[i] = Vect[n-1-i] = min(abs((- str[i] + str[n-1-i]+26)%26),abs((str[i] - str[n-1-i]+26)%26));
    int left = 0,right = n/2 - 1;
    p = min(p,n-1-p);
    while(left<n/2 && (Vect[left]==0))
        left++;
    while(right>=0 && (Vect[right]==0))
        right--;
    ll ans = 0;
    for(int i = left;i<=right;i++)
        ans += Vect[i];
    cout << ans + (ans ? min(abs(p-left),abs(p-right)) + abs(right-left) : 0) ;
    return 0;
}