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

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;

		cin >> n >> m;

		const int LIM = 1001;
		int arr[LIM][LIM];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
			}
		}

		int f[LIM][LIM];
		memset(f, 0, sizeof f);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = arr[i][j];
				if (i == 1 && j == 1) continue;
				int tmp = 1000000000;
				if (i - 1 > 0) tmp = min(tmp, f[i - 1][j]);
				if (i - 1 > 0 && j - 1 > 0) tmp = min(tmp, f[i - 1][j - 1]);
				if (j - 1 > 0) tmp = min(tmp, f[i][j - 1]);
				f[i][j] += tmp;
			}
		}

		cout << f[n][m] << endl;
	}

	return 0;
}