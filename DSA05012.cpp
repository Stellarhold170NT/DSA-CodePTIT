#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

#define MOD (ll) 1000000007
#define ld long double
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int main() {
	int t;
	cin >> t;

	ll c[1001][1001];
	memset(c, 0, sizeof c);

	for (int i = 1; i <= 1000; i++) c[0][i] = 1;
	c[1][1] = 1;

	for (int n = 2; n <= 1000; n++) {
		for (int k = 1; k <= n; k++) {
			c[k][n] = (c[k - 1][n - 1] + c[k][n - 1]) % MOD;
		}
	}

	while (t--) {
		int n, k;
		cin >> n >> k;

		cout << c[k][n] << endl;
	}

	return 0;
}