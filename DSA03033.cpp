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

#define int long long
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

int calc(int frac, int& cnt) {
	if (frac == 1 || frac == 2 || frac == 3 || frac == 5) return 1;
	if (frac == 4 || frac == 6) {
		cnt *= 2;
		return 2;
	}
	if (frac == 7 || frac == 8) return 2;
	if (frac == 9) {
		cnt *= 3;
		return 3;
	}
	return 0;
}

main() {
	int t;
	cin >> t;

	while (t--) {
		int w, c;
		cin >> w >> c;

		if (w % 1000 != 0) {
			cout << 0 << endl;
		}
		else {
			w /= 1000;

			int moneycount, cnt;
			moneycount = 0;
			cnt = 1;

			while (w && c) {
				int frac = w % 10;
				moneycount += calc(frac, cnt);
				w /= 10;
				c--;
			}

			if (w) {
				moneycount += w / 5;
				if (w % 5 == 4) moneycount += 2;
				else if (w % 5) moneycount += 1;

				if (w == 4 || (w % 5 == 1 && w > 1)) cnt *= 2;
				else
					if (w % 5 == 4 && w > 4) cnt *= 3;
			}
			cout << moneycount << " " << cnt << endl;
		}
	}

	return 0;
}