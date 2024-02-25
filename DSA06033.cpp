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

		for (auto& i : v) cin >> i;

		vector<int> n_max(n);

		n_max[n - 1] = v[n - 1];
		for (int i = n - 2; i >= 0; i--) n_max[i] = max(n_max[i + 1], v[i]);

		int i = 0, j = 0;
		int ans = 0;

		while (i < n && j < n) {
			if (n_max[i] > v[j]) {
				ans = max(ans, i - j);
				i++;
			}
			else j++;
		}

		if (ans)
			cout << ans << endl;
		else cout << -1 << endl;
	}

	return 0;
}