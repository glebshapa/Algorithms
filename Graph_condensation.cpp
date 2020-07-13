#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 1e5 + 5;

vector<ll> v1[N];
vector<ll> v2[N];
vector<ll> v[N];
vector<ll> ts;
ll was[N];

void dfs1(int pos)
{
    was[pos] = 1;
    for(ll x : v1[pos])
        if(!was[x])
            dfs1(x);
    ts.push_back(pos);
}

void dfs2(int pos, int color)
{
    was[pos] = color;
    for(ll x : v2[pos])
        if(!was[x])
            dfs2(x, color);
}

int main ()
{
    ll L[N], R[N];
    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        v1[l].push_back(r);
        v2[r].push_back(l);
        L[i] = l;
        R[i] = r;
    }
    for(int i = 0; i < n; i++)
        if(!was[i])
            dfs1(i);
    reverse(ts.begin(), ts.end());
    ll color = 1;
    for(int i = 0; i < n; i++)
        was[i] = 0;
    for(int i : ts)
        if(!was[i])
            dfs2(i, color++);
    for(int i = 0; i < m; i++)
    {
        ll l = L[i], r = R[i];
        if(was[l] != was[r])
        {
            int l1 = was[l];
            int r1 = was[r];
            v[l1].push_back(r1);
        }
    }
    for(int i = 1; i < color; i++)
    {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    for(int i = 1; i < color; i++)
    {
        cout << i << " : ";
        for(int x : v[i])
            cout << x << ' ';
        cout << '\n';
    }
}