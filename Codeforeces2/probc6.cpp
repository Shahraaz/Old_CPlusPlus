#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long int n,i,suma=0,sumb=0 ;
    cin >> n ;
    int a[n] , b[n] ,lena = n, lenb = n;
    for(i=0;i<n;i++)
        cin >> a[i] ;
    for(i=0;i<n;i++)
        cin >> b[i] ;
    sort(a,a+n);
    sort(b,b+n);
    while( lena | lenb){
        if(lena==0)
            lenb--;
        else{
            if(lenb==0)
                suma += (long long)a[--lena];
            else if(a[lena-1]>b[lenb-1])
                suma += (long long)a[--lena];
            else lenb--;
        }
        if(lenb==0)
            lena--;
        else{
            if(lena==0)
                sumb += (long long)b[--lenb];
            else if(b[lenb-1]>a[lena-1])
                sumb += (long long)b[--lenb];
            else lena--;
        }
    }
    cout << suma - sumb;
    return 0;
}