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

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int main() {

    return 0;
}
