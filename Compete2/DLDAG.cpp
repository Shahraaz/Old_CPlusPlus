//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
struct node{
    vector<ll> parent,child;
    bool visited;
    ll level,indegree,outdegree;
    node() : visited(false),level(0),indegree(0),outdegree(0){   };
};
vector<node> Graph; 
struct compare{
    bool operator()(const ll &a,const ll &b){
        if(Graph[a].indegree == Graph[b].indegree){
            if(Graph[a].level == Graph[b].level)
                return a < b;
            else return (Graph[a].level > Graph[b].level);
        }
        return (Graph[a].indegree > Graph[b].indegree);
    }
};
struct cmp{
    bool operator()(const vector<ll> &a,const vector<ll> &b){
       return (a.size() > b.size());
    }
};
ll *Componentsizes;
vector< vector<ll> > Component;
vector<ll> temp;
vector< queue<ll> >leafs;
set<ll,compare> Primeleafs;
ll n,m,x,y,counter=0;
void dfs(ll v){
    Graph[v].visited = true;
    temp.pb(v);
    for(vector<ll>::iterator it=Graph[v].child.begin();it!=Graph[v].child.end();it++)
        if(Graph[*it].visited==false){
            dfs(*it);
        }
    for(vector<ll>::iterator it=Graph[v].parent.begin();it!=Graph[v].parent.end();it++)
        if(Graph[*it].visited==false){
            dfs(*it);
        }
}
void CompnentDFSdivide(){
    for(ll i=1;i<=n;i++)
        if(Graph[i].visited==false){
            temp.clear();
            dfs(i);
            Component.push_back(temp);
        }
}
ll exractleaf(ll j){
    ll l =  leafs[j].front();
    leafs[j].pop();
    for(ll i=0;i<Graph[l].parent.size();i++){
        Graph[Graph[l].parent[i]].outdegree--;
        if(Graph[Graph[l].parent[i]].outdegree==0)
            leafs[j].push(Graph[l].parent[i]);
    }
    return l;
}
ll exractPRIMEleaf(){
    ll l =  *Primeleafs.begin();
    Primeleafs.erase(l);
    for(ll i=0;i<Graph[l].parent.size();i++){
        Graph[Graph[l].parent[i]].outdegree--;
        if(Graph[Graph[l].parent[i]].outdegree==0)
            Primeleafs.insert(Graph[l].parent[i]);
    }
    return l;    
}
string Removetwo(ll j,ll index){
    string str = "2 "; 
    ll l =  exractleaf(j);
    str += to_string(l) + ' ';
    l =  exractleaf(index);
    str += to_string(l) + ' ';
    Componentsizes[j]--;
    Componentsizes[index]--;
    return str;
}
string removePrime1(ll j){
    string str = "2 ";
    ll l =  exractleaf(j);
    str += to_string(l) + ' ';
    l =  exractPRIMEleaf();
    str += to_string(l) ;
    Componentsizes[0]--;
    Componentsizes[j]--;
    return str;
}
int main(){
    fast;
    cin >> n >> m;
    ll i,j,rem,k,ctr;
    Graph.resize(n+1);
    for(ll i=0;i<m;i++){
        cin >> x >> y;
        Graph[x].child.pb(y); 
        Graph[y].parent.pb(x);
        Graph[y].indegree++;
        Graph[x].outdegree++;
    }
    CompnentDFSdivide();
    sort(Component.begin(),Component.end(),cmp());
    Componentsizes = new ll[Component.size()];
    for(ll k=0;k<Component.size();k++)
        Componentsizes[k]=(Component[k].size());
    queue<ll> temp1;
    for(j=0;j<Component[0].size();j++)
        if(Graph[Component[0][j]].indegree==0) temp1.push(Component[0][j]);
    while(temp1.empty()!=true){
        j = temp1.front();
        temp1.pop();
        for(i=0;i<Graph[j].child.size();i++){
            Graph[Graph[j].child[i]].indegree--;
            Graph[Graph[j].child[i]].level = max(Graph[Graph[j].child[i]].level,Graph[j].level+1);
            if(Graph[Graph[j].child[i]].indegree==0)
                temp1.push(Graph[j].child[i]);
        }
    }
    leafs.resize(Component.size());
    vector<string> Answer;
    for(j=0;j<Component[0].size();j++){
        Graph[Component[0][j]].indegree = Graph[Component[0][j]].parent.size();
        if((Graph[Component[0][j]].outdegree)==0){
            // cout << Component[0][j] << ' ' << Graph[Component[0][j]].indegree << ' ' << Graph[Component[0][j]].outdegree << '\n';
            Primeleafs.insert(Component[0][j]);
            // cout << "Size " << Primeleafs.size() << '\n';
        }
    }
    if(Component.size()>1){
        for(i=1;i<Component.size();i++)
            for(j=0;j<Component[i].size();j++)
                if(Graph[Component[i][j]].outdegree==0)
                    leafs[i].push(Component[i][j]);
        for(j=i-1;j>0;){
            ll index = upper_bound(Componentsizes,Componentsizes+j,Componentsizes[0],greater<ll>()) - Componentsizes;
            cout << "index " << index <<  " j " << j <<  '\n';
/*            for(ll x=0;x<Component.size();x++)
                cout << Componentsizes[x] << ' ' ; cout << '\n';
*/            if(index==j){
                k = Componentsizes[j]/(index);
                rem = Componentsizes[j]%(index);
                for(index--;index>0;index--){
                    ctr = k;
                    while(ctr--)
                        Answer.pb(Removetwo(j,index));
                    if(rem){
                        rem--;
                        Answer.pb(Removetwo(j,index));
                    }           
                }
                ctr = k;
                while(ctr--)
                    Answer.pb(removePrime1(j));
                if(rem){
                    rem--;
                    Answer.pb(removePrime1(j));
                }
                j--;
            }
            else{
                ll diff = Componentsizes[0] - Componentsizes[index],count=index;
                index--;
                if(diff*count>=Componentsizes[j]){
                    k = Componentsizes[j]/diff;
                    rem  = Componentsizes[j]%diff; 
                    for(;index>0;index--){
                        ctr = k;
                        while(ctr--)
                            Answer.pb(Removetwo(j,index));
                        if(rem){
                            rem--;
                            Answer.pb(Removetwo(j,index));
                        }           
                    }
                    ctr = k;
                    while(ctr--)
                        Answer.pb(removePrime1(j));
                    if(rem){
                        rem--;
                        Answer.pb(removePrime1(j));
                    }
                    j--;
                }
                else{
                    for(;index>0;index--){
                        ctr = diff;
                        while(ctr--)
                            Answer.pb(Removetwo(j,index));           
                    }
                    ctr = diff;
                    while(ctr--)
                        Answer.pb(removePrime1(j));
                }
            }
        }
    }
    while(Primeleafs.empty()!=true){
        if(Primeleafs.size()>1){
            ll l = *Primeleafs.begin(),k=*(++Primeleafs.begin());
            Primeleafs.erase(l);Primeleafs.erase(k);
            for(ll i=0;i<Graph[l].parent.size();i++){
                Graph[Graph[l].parent[i]].outdegree--;
                if(Graph[Graph[l].parent[i]].outdegree==0)
                    Primeleafs.insert(Graph[l].parent[i]);
            }
            for(ll i=0;i<Graph[k].parent.size();i++){ 
                Graph[Graph[k].parent[i]].outdegree--;
                if(Graph[Graph[k].parent[i]].outdegree==0)
                    Primeleafs.insert(Graph[k].parent[i]);
            }
            string str = "2 ";
            str += to_string(l) + ' ';
            str += to_string(k);
            Answer.pb(str);
        }
        else{
            string str = "1 ";
            ll l = exractPRIMEleaf();
            str += to_string(l);
            Answer.pb(str);
        }
    }
    cout << Answer.size() << '\n';
    for(i = 0;i<Answer.size();i++)
        cout << Answer[i] << '\n';
    return 0;
}