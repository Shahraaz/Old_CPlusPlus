#include<iostream>
// #include<unordered_map>
#include<string>
using namespace std;
int mod = 1e9+7;
long long power(int base,int index){
    if(index==0) return 1;
    long long temp = power(base,index/2);
    temp = (temp*temp)%mod;
    if(index&1) return (temp*base)%mod;
    return temp; 
}
int main(){
    int t,count,i,mod=1e9+7,t6;
    string str;
    int shift,length,length1;
    long long hash1,hash2;
    cin >> t;
    while(t--){
        cin >> str;
        length = str.length();
        str += str;
        hash1 = hash2 = 0;
        length1 = length/2;
        shift = length/2 + (length&1);
        cout << str << '\n';
        for(i=0;i<length1;i++){
            hash1 = ((hash1*27)%mod+(str[i]-'a'))%mod;
            // cout << (str[i]) << '\n';
            hash2 = ((hash2*27)%mod+(str[length-1-i]-'a'))%mod;
            // cout << (str[i+shift]) << '\n';
            //cout << hash1 << '\n';
            //cout << hash2 << '\n';
        }
        count = (hash1==hash2);
        cout << hash1 << '\n';
        cout << hash2 << '\n';    
        long long remover = power(27,length1);
        // cout << count << '\n';
        for(i=1;i<length;i++){
            hash1 = ((hash1*27)%mod + (str[i+length1]-'a')-(remover*(str[i-1]-'a'))%mod)%mod;
            hash2 = ((hash2*27)%mod + (remover*(str[i+shift+length-1]%mod)-'a')-(str[i+shift-1]-'a'))%mod;
            cout << hash1 << '\n';
            cout << hash2 << '\n';
            count += (hash1==hash2); 
        }
        cout << count << '\n';
    }
    return 0;
}