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

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int bit(int x, int y) {
	return ((x >> y) & 1);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		const int LIM = 100001;
		const int n_mask = 1 << 4 + 1;

		int a[4][LIM];
		int f[LIM][n_mask];
		memset(f, 0, sizeof f);
		int check[n_mask] = { 0 };
		int ans = INT_MIN;


		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				ans = max(ans, a[i][j]);
			}
		}

		if (ans < 0) {
			cout << ans << endl;
			continue;
		}

		// sinh ra cac mask hop le
		for (int i = 0; i < 1 << 4; i++) {
			check[i] = 1;
			for (int j = 0; j < 4; j++) {
				if (bit(i, j) && bit(i, j + 1)) {
					check[i] = 0;
					break;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 1 << 4; j++) {
				f[i][j] = INT_MIN;
				if (check[j]) {
					int sum = 0;
					for (int x = 0; x < 4; x++) {
						if (bit(j, x)) sum += a[x][i];
					}

					for (int k = 0; k < 1 << 4; k++) {
						if (check[k] && ((j & k) == 0)) {
							f[i][j] = max(f[i][j], f[i - 1][k] + sum);
						}
					}
				}
				ans = max(ans, f[i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}