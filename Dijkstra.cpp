#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector< pair<ll, ll> > v[100];

int main ()
{
    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        v[l].push_back({r, k});
        v[r].push_back({l, k});
    }
    vector<int> d(n, 1000000000);
    set< pair<ll, ll> > s;
    ll st, fi;
    cin >> st >> fi;
    st--; fi--;
    d[st] = 0;
    s.insert({0, st});
    while(s.size())
    {
        auto p = *s.begin();
        s.erase(p);
        ll pos = p.second;
        for(auto b : v[pos])
        {
            ll u = b.first, w = b.second;
            if(d[u] > d[pos] + w)
            {
                s.erase({d[u], u});
                d[u] = d[pos] + w;
                s.insert({d[u], u});
            }
        }
    }
    cout << d[fi];
}
