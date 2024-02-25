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
		int m, n;
		cin >> m >> n;

		vector<int> a(m), b(n);

		int cnt[10] = { 0 };

		for (auto& i : a) cin >> i;
		for (auto& i : b) {
			cin >> i;
			if (i < 5) cnt[i]++;
		}

		sort(b.begin(), b.end());

		int res = 0;

		for (auto x : a) {
			if (x == 1) res += cnt[0];
			else if (x > 1) {
				auto idx = upper_bound(b.begin(), b.end(), x);
				int ans = b.begin() + n - idx;
				ans += cnt[0] + cnt[1];
				if (x == 2) ans -= cnt[3] + cnt[4];
				if (x == 3) ans += cnt[2];
				res += ans;
			}
		}

		cout << res << endl;
	}

	return 0;
}