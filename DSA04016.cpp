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
//#define N 50000

#define MOD (ll) 123456789
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
		int m, n, k;
		cin >> m >> n >> k;

		vector<int> a(m);
		vector<int> b(n);

		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		vector<int> res;

		int i = 0, j = 0;

		while (i < m && j < n) {
			if (a[i] < b[j]) res.push_back(a[i++]);
			else res.push_back(b[j++]);
		}

		while (i < m) res.push_back(a[i++]);
		while (j < n) res.push_back(b[j++]);

		cout << res[k - 1] << endl;
	}
}