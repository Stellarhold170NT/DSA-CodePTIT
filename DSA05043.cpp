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
		string s;
		cin >> s;

		const int LIM = 1001;
		int f[LIM][LIM];
		memset(f, 0, sizeof f);

		for (int i = 0; i < s.length(); i++) f[i][i] = 1;
		for (int i = 0; i < s.length() - 1; i++) f[i + 1][i] = 1;

		int res = 1;

		for (int k = 2; k <= s.length(); k++) {
			for (int i = 0; i <= s.length() - k; i++) {
				if (s[i] == s[i + k - 1]) {
					f[i][i + k - 1] = f[i + 1][i + k - 2];
				}
				else f[i][i + k - 1] = 0;
				if (f[i][i + k - 1]) res = k;
			}
		}

		cout << res << endl;
	}

	return 0;
}