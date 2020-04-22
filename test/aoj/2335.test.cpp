#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2335&lang=jp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

#define call_from_test
#include "../../math/Combination.cpp"
#undef call_from_test

int main() {
    init_combination();
    ll N, M, K;
    ll ans = 0;
    cin >> N >> M >> K;
    for(ll kn = 0; kn <= K; kn++) {
        ll km = K - kn;
        ll nowans = combination(N + M + 2 * K, N + 2 * kn);
        nowans *= combination(N + 2 * kn, kn) - combination(N + 2 * kn, kn - 1);
        nowans %= mod;
        nowans += mod;
        nowans %= mod;
        nowans *= combination(M + 2 * km, km) - combination(M + 2 * km, km - 1);
        nowans %= mod;
        nowans += mod;
        nowans %= mod;
        ans = (ans + nowans) % mod;
    }
    cout << ans << endl;
    return 0;
}
