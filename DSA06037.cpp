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

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);

		for (auto& i : v) {
			cin >> i;
		}

		vector<int> n_max(n), n_min(n);

		n_max[0] = v[0];
		n_min[n - 1] = v[n - 1];

		for (int i = 1; i < n; i++) {
			n_max[i] = max(n_max[i - 1], v[i]);
		}

		for (int i = n - 2; i >= 0; i--) {
			n_min[i] = min(n_min[i + 1], v[i]);
		}

		vector<int> ans;

		for (int i = 0; i < n - 1; i++) {
			if (n_max[i] < n_min[i + 1]) {
				ans.push_back(i + 1);
			}
		}

		if (ans.empty()) cout << 0 << endl << endl;
		else {
			cout << ans.size() << endl;
			for (auto x : ans) cout << x << " ";
			cout << endl;
		}
	}

	return 0;
}