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

		vector<int> inc(n), dec(n);

		inc[0] = dec[n - 1] = 1;

		for (int i = 1; i < n; i++) {
			if (v[i] > v[i - 1]) inc[i] = inc[i - 1] + 1;
			else inc[i] = 1;
		}

		for (int i = n - 2; i >= 0; i--) {
			if (v[i] > v[i + 1]) dec[i] = dec[i + 1] + 1;
			else dec[i] = 1;
		}

		int ans = -1;
		for (int i = 0; i < n; i++) ans = max(ans, inc[i] + dec[i] - 1);
		cout << ans << endl;
	}
}