#include<iostream>
#include<string>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
ll Fun(string str1,string str2,ll h,ll w){
    unsigned long long count = 0;
    ll i,times = h*w;
    for(i=0;i<times;i++)
        if(str1[i]==str2[i])    count++;
    return count;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,h1,h2,w1,w2,h,w,ai,aii,bi,bii,i,j,ia,ja,count;
    string str1,str2;
    cin >> t;
    while(t--){
        count = 0 ;
        string temp1="",temp2="";
        cin >> h1 >> w1 ;
        cin >> str1 ;
        cin >> h2 >> w2 ;
        cin >> str2 ;
        h = lcm(h1,h2) ;
        w = lcm(w1,w2) ;
        ai = h/h1 ;aii = h/h2 ;bi = w/w1 ;bii = w/w2 ;
        for(i=0;i<h1;i++){
            string temp;
            for(j=0;j<w1;j++){
                string expo ;
                if(str1[i*w1+j]=='0'){
                    expo = "0";
                    for(ia=0;ia<bi-1;ia++)
                        expo.append("0",1);
                }
                else{ 
                    expo = "1";
                    for(ia=0;ia<bi-1;ia++)
                        expo.append("1",1);;
                }
                temp.append(expo);
            }
            for(j=0;j<ai;j++)
                temp1.append(temp);
        }
        for(i=0;i<h2;i++){
            string temp;
            for(j=0;j<w2;j++){
                string expo ;
                if(str2[i*w2+j]=='0'){
                    expo = "0";
                    for(ia=0;ia<bii-1;ia++)
                        expo.append("0",1);
                }
                else{ 
                    expo = "1";
                    for(ia=0;ia<bii-1;ia++)
                        expo.append("1",1);
                }
                temp.append(expo);
            }
            for(j=0;j<aii;j++)
                temp2.append(temp);
        }
        cout << Fun(temp1,temp2,h,w) << '\n';
    }
    return 0;
}