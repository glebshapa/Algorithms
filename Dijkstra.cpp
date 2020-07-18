///Gleb is Always Right

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/rope>

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)(x).size())
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define sqr(x) ((x)*(x))
#define count_one __builtin_popcount(x)

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/*indexed_set s;
s.insert(a);
cout << *s.find_by_order(i) << '\n';
cout << s.order_of_key(k);*/

typedef long long ll;
typedef long double ld;

const ld PI = 3.1415926535;
const ll N = 2e5 + 7;
const ll INF = 1e18 + 7;
const ll d2x[4] = {0, 1, 0, -1};
const ll d2y[4] = {1, 0, -1, 0};
const ll d3x[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const ll d3y[8] = {1, 0, -1, -1, -1, 0, 1, 1};

void indent() {
    cerr << "\n\n\n";
}

vector<pair<ll, ll>> gr[100001];

void Solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        gr[l].pb({r, k});
        gr[r].pb({l, k});
    }

    vector<ll> d(n, 1e9);
    set<pair<ll, ll>> s;
    ll start, finish;
    cin >> start >> finish;
    start--; finish--;
    d[start] = 0;
    s.insert({start, 0});
    while(s.size()) {
        auto p = *s.begin();
        s.erase(p);
        ll v = p.fi;
        for (auto x : gr[v]) {
            ll u = x.fi, w = x.se;
            if (d[u] > d[v] + w) {
                s.erase({u, d[u]});
                d[u] = d[v] + w;
                s.insert({u, d[u]});
            }
        }
    }
    cout << d[finish];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tests = 1;
    //cin >> tests;
    while(tests--)
        Solve();
    return 0;
}
