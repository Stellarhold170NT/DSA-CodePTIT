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
#define N 1003

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

		int n = s.size();

		int f[101][101];
		memset(f, 0, sizeof f);
		for (int i = 0; i < n; i++) f[i][i] = 1;

		for (int k = 2; k <= n; k++) {
			for (int i = 0; i <= n - k; i++) {
				if (s[i] == s[i + k - 1]) {
					f[i][i + k - 1] = f[i + 1][i + k - 2] + 2;
				}
				else f[i][i + k - 1] = max(f[i + 1][i + k - 1], f[i][i + k - 2]);
			}
		}

		cout << n - f[0][n - 1] << endl;
	}

	return 0;
}