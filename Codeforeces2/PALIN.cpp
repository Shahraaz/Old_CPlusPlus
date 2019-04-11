//Main Algorithm Idea taken from Sahilk
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
string str;
int i,length;
bool end(){
    for(i=length-1;i>=0;--i)
        if(str[i]!='9') return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        length = str.length();
        if(end()){
           cout << 1;
           for(i=0;i<str.length()-1;++i)
               cout << 0;
            cout << 1 << '\n';
        }
        else{
            string half = str;
            for(i=0;i<=length/2;++i)
                half[length-1-i] = half[i]; 
            if(half<=str)
                for(i=(length-1)/2;i>=0;--i)
                    if(half[i]!='9'){
                        // cout << half << "->";
                        half[i]++;
                        half[length-i-1] = half[i];
                        // cout << half << '\n';
                        break;
                    }
                    else
                        half[length-i-1] = half[i] = '0';
            // cout << "answer";
            cout << half << '\n';
        }
    }
}