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

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 1003
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define pii pair<int, int> 

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		ll f[50][50];
		memset(f, 0, sizeof f);

		f[n][m] = 1;

		for (int i = n; i >= 0; i--) {
			for (int j = m; j >= 0; j--) {
				if (i == n && j == m) continue;
				f[i][j] += f[i + 1][j] + f[i][j + 1];
				if ((i == 0 && j == m) || (i == n && j == 0)) {
					//f[0][0] += f[i][j];
					//cout << f[i][j] << endl;
				}
			}
		}

		/*for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				cout << f[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << f[0][0] << endl;
	}

	return 0;
}