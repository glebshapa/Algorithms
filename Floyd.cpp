#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main ()
{
    ll dist[101][101];
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = 1000000000;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        dist[l][r] = k;
        dist[r][l] = k;
    }
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << dist[i][j] << ' ';
        cout << '\n';
    }
}
