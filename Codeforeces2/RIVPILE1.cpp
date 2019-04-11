#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>

#include <utility>
#include <algorithm>

using namespace std;

#define ASSERT(A,p,q) assert(p <= A && q >= A)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

static const int inf = 1000000000;

class RMQHelper {
    int M[1024];
    int P[1024];
    int A[256];
    int N;

    void _update(int i, int s, int e, int j, int v) {
        M[i] = min(M[i],v);
        if(s == e) return;
        int m = (s+e)/2;
        if(j >= s && j <= m) _update(2*i + 1, s, m, j, v);
        if(j > m && j <= e) _update(2*i + 2, m+1, e, j, v);
    }

    int _getMin(int i, int s, int e, int ts, int te) {
        if(ts <= s && te >= e) return M[i];
        if(s == e) return M[i];
        if(te < s) return inf;
        if(ts > e) return inf;
        int m = (s+e)/2;
        int res = inf;
        if(ts <= m) res = min(res, _getMin(2*i + 1, s, m, ts, te));
        if(te > m) res = min(res, _getMin(2*i + 2, m+1, e, ts, te));
        return res;
    }
public:
    RMQHelper() {}
    RMQHelper(int _sz) {
        resize(_sz);
    }
    void resize(int _sz) {
        N = _sz;
        FOR(i,0,256) A[i] = inf;
        FOR(i,0,1024) M[i] = inf;
    }
    int getMin(int s, int e) {
        return _getMin(0,0,N-1,s,e);
    }
    void update(int i, int v) {
        _update(0,0,N-1,i,v);
    }
};

int N, M, W;
int X[256], Y[256];
int R[256], C[256];

RMQHelper H[256];
int D[256][256];
int U[256];

void setup() {
    FOR(i,0,N) H[i].resize(M);
    FOR(i,0,N) FOR(j,0,M) D[i][j] = inf;
    FOR(i,0,N) U[i] = M;
}

void do_first() {
    FOR(i,0,N) {
        int j = upper_bound(R,R+M,Y[i]-1)-R;
        if(j == M) continue;
        H[i].update(j,0);
    }
}

bool pick(int &ui) {
    int uj;
    ui = -1;
    FOR(i,0,N) if(U[i]) {
        ui = i;
        uj = U[i]-1;
        break;
    }
    if(ui == -1) return false;
    int m = H[ui].getMin(0,uj);
    FOR(i,0,N) if(U[i]) {
        int _m = H[i].getMin(0,U[i]-1);
        if(_m < m) {
            m = _m;
            ui = i;
            uj = U[i]-1;
        }
    }
    if(m == inf) return false;
    return true;
}

void visit(int ui) {
    int uj = U[ui]-1;
    D[ui][uj] = H[ui].getMin(0,uj);
    int ta = D[ui][uj] + C[uj];
    typedef long long ll;
    FOR(i,0,N) if(i != ui) {
        ll dx = X[i]-X[ui], dy = Y[i]-Y[ui];
        ll d = dx*dx + dy*dy;
        int sd = (int)(ceil(sqrt((double)d)) + 1e-9);
        sd -= R[uj];
        int j = upper_bound(R,R+M,sd-1)-R;
        if(j >= U[i]) continue;
        if(H[i].getMin(0,j) > ta) {
            H[i].update(j,ta);
        }
    }
    U[ui]--;
}

int last_mile() {
    int be = inf;
    FOR(i,0,N) FOR(j,0,M) if(Y[i] + R[j] >= W) be = min(be,D[i][j]+C[j]);
    return be;
}

int dijkstra() {
    setup();
    do_first();
    int ui;
    while(pick(ui)) {
        visit(ui);
    }
    return last_mile();
}

void clean_points() {
    typedef pair<int,int> pi;
    pi A[256];
    FOR(i,0,N) A[i] = pi(X[i],Y[i]);
    sort(A,A+N);
    N = unique(A,A+N)-A;
    FOR(i,0,N) {
        X[i] = A[i].first;
        Y[i] = A[i].second;
    }
}

void clean_disks() {
    typedef pair<int,int> pi;
    pi A[256];
    FOR(i,0,M) A[i] = pi(R[i],C[i]);
    sort(A,A+M);
    int S[256], p = 0;
    S[p++] = 0;
    FOR(i,1,M) {
        while(p && A[i].second <= A[S[p-1]].second) p--;
        S[p++] = i;
    }
    M = p;
    FOR(i,0,M) {
        R[i] = A[S[i]].first;
        C[i] = A[S[i]].second;
    }
}

int main() {
    int T;
    cin >> T;
    ASSERT(T,1,10);
    while(T--) {
        cin >> N >> M >> W;
        ASSERT(N,1,250);
        ASSERT(M,1,250);
        ASSERT(W,2,1000000000);
        FOR(i,0,N) {
            cin >> X[i] >> Y[i];
            ASSERT(X[i],0,1000000000);
            ASSERT(Y[i],1,W-1);
        }
        FOR(j,0,M) {
            cin >> R[j] >> C[j];
            ASSERT(R[j],1,1000000000);
            ASSERT(C[j],1,1000000);
        }

        clean_points();
        clean_disks();

        int res = dijkstra();
        if(res == inf) cout << "impossible" << endl;
        else cout << res << endl;
    }
    return 0;
}

