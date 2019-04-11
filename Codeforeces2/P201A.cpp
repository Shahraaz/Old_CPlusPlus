#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,i;
    cin >> n;
    vector<int> Vect(n);
    i = n;
    while(i--)
        cin >> Vect[i];
    sort(Vect.begin(),Vect.end());
    cout << Vect[n-1] << ' ';
    for(i=1;i<n-1;i++)
        cout << Vect[i] << ' ';
    cout << Vect[0];
    return 0;
}
