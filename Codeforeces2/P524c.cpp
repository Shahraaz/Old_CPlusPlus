#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void fun(int n,int m,int &white,int &black){
    white = (n*m)/2 + ((n*m)%2);
    black = (n*m)/2;
    // cout << white << ' ' << black << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,x1,x2,x3,x4,y1,y2,y3,y4;
    cin >> t;
    while(t--){ 
        int white = 0, black = 0;
        cin >> n >> m;
        fun(n,m,white,black);
        // cout << white << ' ' << black << '\n';
        cin >> x1 >> y1 >> x2 >> y2;
        {    
            int white1 = 0;int black1 = 0;
            if(((x1+y1)%2)==0)
                fun(x2-x1+1,y2-y1+1,white1,black1);        
            else fun(x2-x1+1,y2-y1+1,black1,white1);
            white += black1;
            black -= black1;
        }
        cout << white << ' ' << black << '\n';        
        cin >> x3 >> y3 >> x4 >> y4;
        {
            int white1 = 0;int black1 = 0;
            if(((x3+y3)%2)==0)
                fun(x4-x3+1,y4-y3+1,white1,black1);        
            else fun(x4-x3+1,y4-y3+1,black1,white1);
            black += white1;
            white -= white1;         
        }
        cout << white << ' ' << black << '\n';        
        int lx,ly,rx,ry;
        if(x3<=x1 && x1<=x4){
            lx = x1;
            if(y3<=y1 && y1<=y4){
                ly = y1;
                rx = min(x2,x4);
                ry = min(y2,y4);
                {
                    int white1 = 0;int black1 = 0;
                    if(((lx+rx)%2)==0)
                        fun(rx-lx+1,ry-ly+1,white1,black1);        
                    else fun(rx-lx+1,ry-ly+1,black1,white1);
                    black += white1;
                    white -= black1;
                }
            }
            else if(y1<=y3 && y3<=y2){
                ly = y3;
                rx = min(x2,x4);
                ry = min(y2,y4);
                {
                    int white1 = 0;int black1 = 0;
                    if(((lx+rx)%2)==0)
                        fun(rx-lx+1,ry-ly+1,white1,black1);        
                    else fun(rx-lx+1,ry-ly+1,black1,white1);
                    black += white1;
                    white -= black1;
                }
            }
        }
        else if(x1<=x3 && x3<=x2){
            lx = x3;
            if(y1<=y3 && y3<=y2){
                ly = y3;
                rx = min(x2,x4);
                ry = min(y2,y4);
                {
                    int white1 = 0;int black1 = 0;
                    if(((lx+rx)%2)==0)
                        fun(rx-lx+1,ry-ly+1,white1,black1);        
                    else fun(rx-lx+1,ry-ly+1,black1,white1);
                    black += white1;
                    white -= black1;
                }
            }
            else if(y3<=y1 && y1<=y4){
                ly = y1;
                rx = min(x2,x4);
                ry = min(y2,y4);
                {
                    int white1 = 0;int black1 = 0;
                    if(((lx+rx)%2)==0)
                        fun(rx-lx+1,ry-ly+1,white1,black1);        
                    else fun(rx-lx+1,ry-ly+1,black1,white1);
                    black += white1;
                    white -= black1;
                }
            }
        }
        cout << white << ' ' << black << '\n';
    }
    return 0;
}