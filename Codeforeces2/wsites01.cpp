//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    fast;
    int n,i,cblock,cunblock,minlen,j;
    char op;
    string str;
    vector<string> Unblocked,Blocked;
    set<string> filter;
    set<char> Open;
    cin >> n;
    for(i=0;i<n;++i){
        cin >> op >> str;
        if(op=='+') Unblocked.pb(str);
        else Blocked.pb(str);
    }
    if((cblock=Blocked.size())==0) cout << 0 ;
    else if((cunblock=Unblocked.size())==0){
        for(i=0;i<cblock;++i)
            Open.insert(Blocked[i][0]);
        cout << Open.size() << '\n';
        for(set<char>::iterator it=Open.begin();it!=Open.end();++it)
            cout << *it << '\n';
    }
    else{
        sort(Unblocked.begin(),Unblocked.end());
        sort(Blocked.begin(),Blocked.end());
        vector<string>::iterator low,up;
        for(i=0;i<cblock;++i){
            low = lower_bound(Unblocked.begin(),Unblocked.end(),Blocked[i]);
            str = "";
            int maxlencommon = 1;
            if(low!=Unblocked.end()){
                minlen = min(Blocked[i].length(),(*low).length());
                for(j=0;j<minlen;++j)
                    if((*low)[j]!=Blocked[i][j]) break;
                if(j==minlen){
                    cout << -1 ; 
                    return 0;
                }
                maxlencommon = max(maxlencommon,j+1);
            }
            if(low!=Unblocked.begin()){
                --low;
                minlen = min(Blocked[i].length(),(*low).length());
                for(j=0;j<minlen;++j)
                    if((*low)[j]!=Blocked[i][j]) break;
                maxlencommon = max(maxlencommon,j+1);
            }
            for(int k=0;k<maxlencommon;++k)
                    str += Blocked[i][k];
            filter.insert(str);
        }
        cout << filter.size() << '\n';
        for(set<string>::iterator it=filter.begin();it!=filter.end();++it)
            cout << *it << '\n';
    }
    return 0;
}