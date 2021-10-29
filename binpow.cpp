#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)(x).size())
#define unq(x) (x.resize(unique(all(x)) - x.begin()))

using namespace std;

typedef long long ll;
typedef long double ld;

const ld PI = 3.1415926535;
const ll N = 2e5 + 7;
const ll INF = 1e18 + 7;

ll binpow (ll a, ll g, ll mod) {
    ll res = 1;
    while (g)
        if (g & 1) {
            res *= a;
            res %= mod;
            --g;
        }
        else {
            a *= a;
            a %= mod;
            g >>= 1;
        }
    return res;
}

int main() {

    return 0;
}
