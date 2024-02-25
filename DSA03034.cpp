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

		vector<int> a(n), b(m), c(k);

		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		for (int i = 0; i < k; i++) cin >> c[i];

		int i = 0, j = 0, p = 0;

		bool flag = false;

		while (i < n && j < m && p < k) {
			if (a[i] == b[j] && a[i] == c[p]) {
				cout << a[i] << " ";
				flag = true;
				i++;
				j++;
				p++;
			}

			if (!(i < n && j < m && p < k)) break;
			int tmp = max(a[i], max(b[j], c[p]));

			while (i < n && a[i] < tmp) i++;
			while (j < m && b[j] < tmp) j++;
			while (p < k && c[p] < tmp) p++;

		}

		if (!flag) cout << "NO";
		cout << endl;
	}

	return 0;
}