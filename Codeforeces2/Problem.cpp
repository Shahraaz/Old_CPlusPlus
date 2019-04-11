#include<iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main(){
	ll n,i;
	cin >> n;
	if(n==1)
		cout << 1 << '\n' << 1 ;
	else if(n==2)
		cout <<"2 1\n1 2\n" ; 
	else if(n%2==0){
		for(i=2;i<=n/2;i++)
			cout << i << ' ';
		cout << "1 ";
		for(i=n/2+2;i<=n;i++)
			cout << i << ' ';
		cout << n/2 + 1 << '\n';
        cout << n << ' ';
        for(i=1;i<n;i++)
            cout << i << ' ';
	}
	else{
        for(i=2;i<=n/2+1;i++)
			cout << i << ' ';
		cout << "1 ";
		for(i=n/2+3;i<=n;i++)
			cout << i << ' ';
		cout << n/2 + 2 << '\n';
        cout << n << ' ';
        for(i=1;i<n;i++)
            cout << i << ' ';	
    }
	return 0;
}