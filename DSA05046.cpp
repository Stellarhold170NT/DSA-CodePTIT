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
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 1003
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define pii pair<int, int> 

//https://math.stackexchange.com/questions/1878810/formula-for-1k2k3k-nk-for-n-k-in-mathbbn

ll c[1005][1005];
const ll MOD = 1e9 + 7;

ll POW(ll n, ll x) {
	if (x == 0) return 1;
	if (x == 1) return n % MOD;
	ll tmp = POW(n, x / 2);
	if (x % 2 == 0) return (tmp * tmp) % MOD;
	else return ((((tmp * tmp) % MOD) * n) % MOD);
}

void sinhToHop() {
	memset(c, 0, sizeof c);
	c[0][0] = 1;
	for (int i = 1; i < 1005; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}
int main() {
	sinhToHop();

	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		int dp[1005] = { 0 };
		n %= MOD;
		dp[0] = n;
		ll tmp = n + 1;
		for (int i = 1; i <= k; i++) {
			tmp = (tmp * (n + 1)) % MOD;

			ll sum = 0;
			for (int j = 0; j < i; j++) {
				sum += (c[i + 1][j] * dp[j]) % MOD;
				sum %= MOD;
			}
			dp[i] = (tmp - 1 + MOD) % MOD;
			dp[i] = (dp[i] - sum + MOD) % MOD;
			dp[i] = (dp[i] * POW(i + 1, MOD - 2)) % MOD;
			dp[i] %= MOD;
		}

		cout << dp[k] << endl;
	}

	return 0;
}