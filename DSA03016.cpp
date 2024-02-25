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
		int s, d;
		cin >> s >> d;

		int x = d;

		if (s == 0 && d == 1) cout << 0 << endl;
		else {
			if (s <= d * 9 && s != 0) {
				string ans = "";
				for (int i = 1; i <= d; i++) {
					for (int j = 9; j >= 1; j--) {
						if (s - j <= (d - i) * 9 && (s - j >= 1)) {
							ans = to_string(j) + ans;
							s -= j;
							break;
						}
					}
				}
				if (s) {
					while (ans.length() + 1 <= x - 1) ans = "0" + ans;
					ans = to_string(s) + ans;
				}

				cout << ans << endl;
			}
			else cout << -1 << endl;
		}


	}

	return 0;
}