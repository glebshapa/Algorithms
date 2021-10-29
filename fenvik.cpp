vector<ll> f(N);
int n;

ll sum(int r) {
    ll s = 0;
    for (; r > 0; r &= (r - 1))
        s += f[r];
    return s;
}

ll add(int i, ll d) {
    for (; i <= n; i = (i | (i - 1)) + 1)
        f[i] += d;
}
