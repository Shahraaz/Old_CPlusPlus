#include<iostream>
#include<set>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,a,b,i;
    cin >> n >> a >> b;
    set<int> Set;
    for(i=0;i<=b;i++)
        Set.insert(n-i);
    for(i=1;i<=a;i++)
        Set.erase(i);
    cout << Set.size();
    return 0;
}
