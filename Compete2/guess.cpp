//Optimise
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast()                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ull, ull> pull;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
const long long High = 1e16;

ull inv[60004];
void init()
{
	inv[0] = 1;
	inv[1] = 1;
	for(int i=2;i<=60000;++i)
		inv[i] = (inv[mod%i]*(mod - mod/i))%mod;		
}

ull solve(int n,int k,int m)
{
//	cout << n << ' ' << k << ' ' << m << '\n';
	if(m==0)
	{
		cout << 0;
		return (0);	
	}
	if(n>k && (m!=1))
	{
		if(n%k==0)
			n = k;
		else n = n%k;
		ull t = solve(n,k,m-1);
		return t;
	}
	else
	{
		cout << "(1/" << n << ' ' << "+(" << n-1 << '/' << n << '*' ;
		ull d = solve(n+k,k,m-1);
		cout << ")";
		return (inv[n]*(1 + (n-1)*d % mod))%mod;
	}
}


int main()
{
	//fast();
	init();
	int t,n,k,m;
	cin >> t;
	while(t--)
	{	
		cin >> n >> k >> m;
		ull t = solve(n,k,m);
		cout << '\n';
		cout << t << '\n';
		
	}
	return 0;
}