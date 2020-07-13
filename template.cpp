///Gleb is Always Right

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/*indexed_set s;
s.insert(a);
cout << *s.find_by_order(i) << '\n';
cout << s.order_of_key(k);*/

typedef long long ll;
typedef long double ld;

const ld PI = 3.1415926535;
const ll N = 5e5 + 7;
const ll INF = 1e18 + 7;
const ll d2x[4] = {0, 1, 0, -1};
const ll d2y[4] = {1, 0, -1, 0};
const ll d3x[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const ll d3y[8] = {1, 0, -1, -1, -1, 0, 1, 1};

void indent() {
    cerr << "\n\n\n";
}

void Solve() {
    

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
