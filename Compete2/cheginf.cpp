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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string str;
        cin >> n;
        int Universal[26] = {0};
        for(int i=0;i<n;++i)
        {
            bool Hash[26] = {0};
            cin >> str;
            for(char ch : str)
                Hash[ch-'a'] = true;
            for(int j=0;j<26;++j)
                Universal[j] += Hash[j];
        }
        int cnt = 0 ;
        for(int i=0;i<26;++i)
            if(Universal[i]==n)
                cnt++;
        cout << cnt << '\n';
    }
    return 0;
}