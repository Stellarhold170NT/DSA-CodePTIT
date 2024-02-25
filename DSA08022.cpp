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

		int d0 = 0;
		int d1 = 0;
		int d2 = 0;

		for (auto& i : v) {
			cin >> i;
			if (i % 3 == 1) d1++;
			else if (i % 3 == 2) d2++;
			else d0++;
		}

		sort(v.begin(), v.end(), greater<int>());

		if (d0 == 0) {
			if ((d1 == 0 && d2 < 3) || (d2 == 0 && d1 < 3)) {
				cout << -1 << endl;
				continue;
			}
		}

		if (d1 % 3 != d2 % 3) {
			if ((d1 - 1) % 3 == d2 % 3) d1--;
			else if ((d2 - 1) % 3 == d1 % 3) d2--;
		}

		for (int i = 0; i < n; i++) {
			if (v[i] % 3 == 0 && d0) cout << v[i], d0--;
			else if (v[i] % 3 == 1 && d1) cout << v[i], d1--;
			else if (v[i] % 3 == 2 && d2) cout << v[i], d2--;

			if (d0 == 0 && d1 == 0 && d2 == 0) break;
		}
		cout << endl;

	}
	return 0;
}