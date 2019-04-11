#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
    string a,b;
    cin >> a;
    cin >> b;
    reverse(b.begin(),b.end());
    if(a.compare(b)==0) cout << "YES";
    else cout << "NO";
    return 0;
}
