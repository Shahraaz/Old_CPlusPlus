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

int tree[1<<20];

int update(int t,int x,int l,int r,int y,int z)
{
    if(l>y || r<y) return tree[x];
    if(l==r) return tree[x] = z;
    int mid = (l+r)/2;
    update(t^1,2*x+1,l,mid,y,z);
    update(t^1,2*x+2,mid+1,r,y,z);
    if(t)
        tree[x] = tree[2*x+1] | tree[2*x+2];
    else    tree[x] = tree[2*x+1] ^ tree[2*x+2];
    return tree[x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int x,y,n,m;
    cin >> n >> m;
    for(int i=0;i<(1<<n);++i)
    {   
        cin >> x;
        update(n&1,0,0,(1<<n)-1,i,x);
    }
    while(m--)
    {
        cin >> x >> y;
        x--;
        cout << update(n&1,0,0,(1<<n)-1,x,y) << '\n';
    }
    return 0;
}