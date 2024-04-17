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
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		ll lim = cbrt(n);
		string nStr = to_string(n);
		string res = "";

		for (ll x = lim; x >= 1; x--) {
			string xStr = to_string(x * x * x);
			int idx = 0;

			for (int i = 0; i < nStr.size(); i++) {
				if (nStr[i] == xStr[idx]) {
					idx++;
				}
			}

			if (idx == xStr.size()) {
				res = xStr;
				break;
			}
		}

		if (res.empty()) {
			cout << -1 << endl;
		}
		else cout << res << endl;
	}
	return 0;
}