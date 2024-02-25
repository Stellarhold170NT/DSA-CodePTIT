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
		int n;
		cin >> n;

		vector<int> v(n);

		for (auto& i : v) cin >> i;

		vector<int> f_inc(n, 0);
		vector<int> f_dec(n, 0);

		f_inc[0] = v[0];
		f_dec[n - 1] = v[n - 1];

		for (int i = n - 2; i >= 0; i--) {
			f_dec[i] = v[i];
			for (int j = i + 1; j <= n - 1; j++) {
				if (v[i] > v[j] && f_dec[j] + v[i] > f_dec[i]) {
					f_dec[i] = f_dec[j] + v[i];
				}
			}
		}

		for (int i = 1; i <= n - 1; i++) {
			f_inc[i] = v[i];
			for (int j = 0; j < i; j++) {
				if (v[i] > v[j] && f_inc[j] + v[i] > f_inc[i]) {
					f_inc[i] = f_inc[j] + v[i];
				}
			}
		}

		int res = -1;

		for (int i = 0; i < n; i++) {
			res = max(res, f_inc[i] + f_dec[i] - v[i]);
		}

		cout << res << endl;
	}

	return 0;
}