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
main() {
	int n, m;
	cin >> n >> m;

	const int lim = 10001;
	int a[lim];
	int v[lim];

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> v[i];
	}

	int f[lim][5001];
	memset(f, 0, sizeof f);
	int res = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j >= a[i]) {
				f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + v[i]);
			}
			else f[i][j] = f[i - 1][j];
		}
	}

	cout << f[n][m] << endl;

	return 0;
}