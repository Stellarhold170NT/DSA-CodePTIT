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
		int n, m, k;
		cin >> n >> m >> k;
		string a, b, c;
		cin >> a >> b >> c;

		a = " " + a;
		b = " " + b;
		c = " " + c;

		const int LIM = 101;
		int f[LIM][LIM][LIM];

		memset(f, 0, sizeof f);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int p = 1; p <= k; p++) {
					if (a[i] == b[j] && b[j] == c[p]) f[i][j][p] = f[i - 1][j - 1][p - 1] + 1;
					else {
						vector<int> v;
						v.push_back(f[i - 1][j][p]);
						v.push_back(f[i][j - 1][p]);
						v.push_back(f[i][j][p - 1]);
						v.push_back(f[i - 1][j - 1][p]);
						v.push_back(f[i - 1][j][p - 1]);
						v.push_back(f[i][j - 1][p - 1]);
						sort(v.begin(), v.end());
						f[i][j][p] = v[v.size() - 1];
					}
				}
			}
		}

		cout << f[n][m][k] << endl;
	}

	return 0;
}