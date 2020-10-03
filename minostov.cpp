#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)(x).size())
#define unq(x) (x.resize(unique(all(x)) - x.begin()))

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;

const ld PI = 3.1415926535;
const ll N = 2e5 + 7;
const ll INF = 1e18 + 7;

ll h[100001], p[100001];

void Init(ll v) {
    h[v] = 1;
    p[v] = v;
}

ll Find(ll v) {
    while (p[v] != v)
        v = p[v];
    return v;
}

void Union(ll a, ll b) {
    ll god1 = Find(a), god2 = Find(b);
    if (h[god1] == h[god2]) {
        p[god2] = god1;
        h[god1]++;
    } else if (h[god1] > h[god2])
        p[god2] = god1;
    else if (h[god1] < h[god2])
        p[god1] = god2;
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> gr;
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        gr.pb({w, {u, v}});
    }
    sort(all(gr));

    for (int i = 0; i < n; i++)
        Init(i);

    vector<pair<ll, ll>> minost;
    for (int i = 0; i < m; i++) {
        if (Find(gr[i].se.fi) != Find(gr[i].se.se)) {
            Union(gr[i].se.fi, gr[i].se.se);
            minost.pb({gr[i].se.fi, gr[i].se.se});
        }
    }

    for (auto x : minost)
        cout << x.fi + 1 << ' ' << x.se + 1 << '\n';

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
