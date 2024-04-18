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
#include <bitset>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n;
const int N = 100001;

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll dp[N][6];
		int a[N] = { 0 }, b[N] = { 0 };

		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
		}

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= 2; j++)
				dp[i][j] = LLONG_MAX;

		dp[0][0] = 0;

		for (int j = 0; j <= 2; j++) {
			dp[1][j] = j * b[1];
		}

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 2; j++) {
				for (int k = 0; k <= 2; k++) {
					if (a[i - 1] + k != a[i] + j)
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + b[i] * j);
				}
			}
		}

		ll res = LLONG_MAX;
		for (int j = 0; j <= 2; j++)
			res = min(res, dp[n][j]);

		cout << res << endl;
	}

	return 0;
}
