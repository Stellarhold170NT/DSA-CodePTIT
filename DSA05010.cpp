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

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> v(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			v[i] %= k;
		}

		int f[1000][50];
		memset(f, 0, sizeof f);

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < k; j++) {
				f[i][j] = INT_MIN;
			}
		}

		f[1][v[1]] = 1;

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < k; j++) {
				f[i][j] = max(f[i - 1][j], f[i - 1][(j - v[i] + k) % k] + 1);
			}
		}

		cout << f[n][0] << endl;
	}

	return 0;
}