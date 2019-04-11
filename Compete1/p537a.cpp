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

bool isvovel(char ch)
{
    if((ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u') )
        return true;
    return false;
}   

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    string h1,h2;
    cin >> h1 >> h2;
    if(h1.length()!=h2.length())
        cout << "No";
    else
    {
        for(int i=0;i<h1.length();++i)
        {
            bool x = isvovel(h1[i])^isvovel(h2[i]);
            if(x)
            {
                cout << "No"
                ;return 0;
            }
        }
        cout << "Yes";
    }
    return 0;
}