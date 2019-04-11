#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
    ll k,n,d,i;
    cin >> n >> d;
    vector<long long> Vect(n);
    for(i=0;i<n;i++)
        cin >> Vect[i];
    vector<ll> Answer(n),sum(n,0);
    k = i = 0;
    for(vector<ll>::iterator it=Vect.begin();it!=Vect.end();++it,i++){
        Answer[i] = (ll)(upper_bound(it,Vect.end(),(*it+d)) - it)-1;
        // cout << Answer[i] << ' ';
        if(Answer[i])
            k += Answer[i]*(Answer[i] - 1)/2;
    }
    // cout << '\n';
    cout << k ;
    return 0;
}
