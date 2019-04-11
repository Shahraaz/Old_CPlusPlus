#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

constexpr int P = 1000000007;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    k--;
    int v = w - 1;

    int s[8][3] = {};
    for (int k = 0; k < 1 << v; k++) {
        int b = 1;
        for (int j = 0; j < v - 1; j++) {
            if (!(~(k >> j) & 3)) b = 0;
        }
        if (b) {
            int l[3] = { k << 1, ~(k ^ k << 1), k };
            for (int j = 0; j < w; j++) {
                for (int x = 0; x < 3; x++) {
                    if (l[x] >> j & 1) s[j][x]++;
                }
            }
        }
    }
    //for (int j = 0; j < w; j++) {
    //    for (int x = 0; x < 3; x++) {
    //        cout << s[j][x] << ' ';
    //    }
    //    cout << '\n';
    //}

    ll p[8] = { 1 }, q[8];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            q[j] = 0;
            for (int x = 0; x < 3; x++) {
                if (s[j][x]) q[j] += p[j - 1 + x] * s[j][x];
            }
        }
        for (int j = 0; j < w; j++) {
            p[j] = q[j] % P;
        }
    }

    cout << p[k] << endl;

    return 0;
}