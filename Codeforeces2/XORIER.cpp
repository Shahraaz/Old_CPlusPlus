#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,temp,tempnext,lengtheven,lengthOdd,i,j,counttemp,countnext,evenleft,oddleft;
    ull counttotal;
    cin >> t;
    while(t--){
        vector<int> Even, Odd;
        cin >> n;
        while(n--){
            cin >> temp;
            if(temp&1) Odd.push_back(temp);
            else Even.push_back(temp);
        }
        sort(Odd.begin(),Odd.end());
        sort(Even.begin(),Even.end());
        lengtheven = evenleft = Even.size();
        lengthOdd = oddleft = Odd.size();
        counttotal = 0;
        for(i=0;i<lengtheven;){
            temp = Even[i];
            counttemp = countnext = 0;
            while(i<lengtheven & temp==Even[i]){
                i++;
                counttemp++;
            }
            evenleft -= counttemp;
            if(i<lengtheven){
                j = i;
                tempnext = Even[j];        
                if(tempnext ^ temp == 2)
                    while(j<lengtheven & tempnext==Even[j]){
                        j++;
                        countnext++;
                    }
            }
            counttotal += (evenleft - countnext)*counttemp;
        }
        for(i=0;i<lengthOdd;){
            temp = Odd[i];
            counttemp = countnext = 0;
            while(i<lengthOdd & temp==Odd[i]){
                i++;
                counttemp++;
            }
            oddleft -= counttemp;
            if(i<lengthOdd){
                j = i;
                tempnext = Odd[j];        
                // if(tempnext ^ temp == 2)
                    while(j<lengthOdd & tempnext==Odd[j]){
                        j++;
                        countnext++;
                    }
            }
            counttotal += (oddleft - countnext)*counttemp;
        }
        cout << counttotal << '\n';
    }
	return 0;
}