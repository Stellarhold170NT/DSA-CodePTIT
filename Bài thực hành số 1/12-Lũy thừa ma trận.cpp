#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, k;

struct matrix {
	ll f[11][11];

	matrix() {
		memset(f, 0, sizeof f);
	}

	matrix operator * (const matrix& other) const {
		matrix res;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					(res.f[i][j] += this->f[i][k] * other.f[k][j]) %= MOD;
				}
			}
		}

		return res;
	}
};

matrix I;


matrix calc(matrix m, ll k) {
	if (k == 0) return I;
	if (k == 1) {
		return m;

	}

	matrix tmp = calc(m, k / 2);


	if (k % 2 == 0) return tmp * tmp;
	else return tmp * tmp * m;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		matrix m;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> m.f[i][j];
			}

		for (int i = 0; i < n; i++) I.f[i][i] = 1;
		matrix res = calc(m, k);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += res.f[i][i];
		}
		cout << ans % MOD << endl;
	}
	return 0;
}