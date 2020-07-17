///Gleb is Always Right

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)(x).size())
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define sqr(x) ((x)*(x))
#define count_one __builtin_popcount(x)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

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

vector<ll> gr[N], h(N);
ll lg = 20;
ll up[100001][21];

void dfs(ll v, ll p, ll hi) {
    h[v] = hi;
    up[v][0] = p;
    for (int i = 1; i <= lg; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto x : gr[v])
        if (x != p)
            dfs(x, v, hi + 1);
}

bool upper (ll a, ll b) {
    ll r = h[b] - h[a];
    for (int i = lg; i >= 0; i--) {
        if (r >= (1 << i)) {
            r -= (1 << i);
            b = up[b][i];
        }
    }
    return a == b;
}

ll lca(ll a, ll b) {
    if (upper(a, b))
        return a;
    if (upper(b, a))
        return b;
    for (int i = lg; i >= 0; i--) {
        if (!upper(up[a][i], b))
            a = up[a][i];
    }
    return up[a][0];
}

void Solve() {
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        gr[l].pb(r);
        gr[r].pb(l);
    }
    indent();
    dfs(0, 0, 0);

    ll m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        cout << lca(a, b) + 1 << endl;
    }
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
