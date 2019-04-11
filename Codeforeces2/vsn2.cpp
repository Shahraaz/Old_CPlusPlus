#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
long double min(long double a, long double b)
{
    if(a < b)  return a ;
    return  b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long double r,px,py,pz,qx,qy,qz,cx,cy,dx,dy,dz,cz;
    long double root1,root2,c1,c2,c3,k1,k2,k3,f,g,h,i,j,k,a,b,c;
    cin >> t; 
    cout.setf(ios::fixed);
    cout.precision(9);
    while(t--)
    {
        cin >> px >> py >> pz >> qx >> qy >> qz >> dx >> dy >> dz >> cx >> cy >> cz >> r;
        c1 = cx - px ; c2 = cy - py ; c3 = cz - pz;
        k1 = px - qx ; k2 = py - qy ; k3 = pz - qz;
        f = c1*dx + c2*dy + c3*dz ;
        g = c1*k1 + c2*k2 + c3*k3 ;
        h = c1*c1 + c2*c2 + c3*c3 - r*r ;
        i = k1*dx + k2*dy + k3*dz ;
        j = dx*dx + dy*dy + dz*dz ;
        k = k1*k1 + k2*k2 + k3*k3 ;
        a  = f*f - h*j ;
        b = 2*(h*i-f*g) ;
        c = g*g - k*h ;
        if(a==0)
            cout << -c/b << "\n";
        else
        {
            root1 = (-b+sqrt(b*b-4*a*c))/(2*a);
            root2 = (-b-sqrt(b*b-4*a*c))/(2*a);
            if(root1 > 0 & root2 > 0)
                cout << min(root1,root2) << "\n" ;
            else if(root1 > 0)
                cout << root1 << "\n" ;
            else cout << root2 << "\n" ;
        }         
    }
    return 0;
}