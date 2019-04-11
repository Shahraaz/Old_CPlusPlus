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
ll counter(string &str1,string &str2,ll w1,ll w2,ll iter1,ll iter2){
    ll count = 0,ib,iib,temp,times=lcm(w1,w2),istar=0,iistar=0;
    ll bi = times/w1,bii=times/w2,flag;
    ib = bi; iib = bii;
    for(temp = 0;temp<times;){
        if(str1[iter1+istar]==str2[iter2+iistar])
                flag = 1;
        else    flag = 0;
        cout << iter1+istar << ' ' << iter2+iistar << ' ' << flag <<  " Fun" <<'\n';
        if((ib==bi)&&(iib==bii)){
            if(bi<bii){
                temp += bi;
                iib = bi;
                count += bi*flag;
                istar++;
            }
            else if(bii<bi){
                temp += bii;
                ib = bii;
                count += bii*flag;
                iistar++;
            }   
            else{
                temp += bi;
                count += bi*flag;
                istar++;
                iistar++;
            }
        }
        else if(ib==bi){
            if(ib < (bii-iib)){
                iib += bi;
                temp += bi;
                count += bi*flag;
                istar ++;
            }
            else if(ib > (bii-iib)){
                temp += (bii-iib); 
                ib = (bii-iib);
                iib = bii;
                count += (bii-iib)*flag;
                iistar ++;
            }
            else {
                temp += ib;
                iib = bii;
                count += bi*flag;
                istar++;
                iistar++;
            }
        }
        else if(bii==iib){
            if(iib < (bi-ib)){
                ib += bii;
                temp += bii;
                count += bii*flag;
                iistar ++;
            }
            else if(iib > (bi-ib)){
                temp += (bi-ib); 
                iib = (bi-ib);
                ib = bi;
                count += (bi-ib)*flag;
                istar ++;
            }
            else {
                temp += iib;
                ib = bii;
                count += bii*flag;
                istar++;
                iistar++;
            }
        }
    }
    return count;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,h1,h2,w1,w2,h,w,ai,aii,bi,bii,i,j,ia,ja,iia,iib,ib,count,temp,times,istar,iistar,temp2;
    string str1,str2;
    cin >> t;
    while(t--){
        count = 0 ;
        cin >> h1 >> w1 ;
        cin >> str1 ;
        cin >> h2 >> w2 ;
        cin >> str2 ;
        h = lcm(h1,h2) ;
        w = lcm(w1,w2) ;
        ai = h/h1 ;aii = h/h2 ;bi = w/w1 ;bii = w/w2 ;
        ia=ai;ib=bi;iia=aii;iib=bii;
        times = h;
        istar = iistar = 0;
        for(temp = 0;temp < h;){
            temp2 = counter(str1,str2,w1,w2,istar,iistar);
            cout << istar << ' ' << iistar << ' ' << temp <<  " Main" <<'\n';
            if((ia==ai) & (iia==aii)){
                if(ai<aii){
                    temp += ai;
                    iia = ai;
                    count += temp2*ai;
                    istar += w1;
                }
                else if(aii<ai){
                    temp += iia;
                    ia = aii;
                    count += aii*temp2;
                    iistar += w2;
                }
                else{ 
                    temp += ai;
                    iia = ai;
                    count += aii*temp2;
                    istar += w1;
                    iistar += w2;
                }
            }
            else if(ia==ai){
                if(ai < (aii-iia)){
                    iia += ai;
                    temp += ai;
                    count += ai*temp2;
                    istar += w1;
                }
                else if(ai > (aii-iia)){
                    iia = aii;
                    ai += aii-iia;
                    temp += aii-iia;
                    count += (aii-iia)*temp2;
                    iistar += w2;
                }
                else{
                    iia = aii;
                    temp += ai;
                    count += ai*temp2;
                    istar += w1;
                    iistar += w2;
                }
            }
            else if(iia==aii){
                if(aii < (ai-ia)){
                    ia += aii;
                    temp += aii;
                    count += aii*temp2;
                    iistar += w2;
                }
                else if(aii > (ai-ia)){
                    ia = ai;
                    iia += ai-ia;
                    temp += ai-ia;
                    count += (ai-ia)*temp2;
                    istar += w1;
                }
                else{
                    ia = ai;
                    temp += aii;
                    count += aii*temp2;
                    istar += w1;
                    iistar += w2;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}