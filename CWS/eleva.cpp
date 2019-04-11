#include<iostream>
using namespace std;
int main()
{
    int t,n,v1,v2;
    double root2 = 1.414213562373 ;
    cin >> t;
    while(t--)
    {   
        cin >> n >> v1 >> v2;
        if(root2*v1 <= v2)
            cout << "Elevator" << endl;
        else cout << "Stairs" << endl;
    }
    return 0;
}