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

#define int long long
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

int solve(vector<int> v, int a, int b, int ix) {
	for (int i = ix; i < v.size(); i += 2) {
		a = a * 10 + v[i];
		b = b * 10 + v[i + 1];
	}

	return a + b;
}

main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		if (v.size() % 2 == 1) {
			int a = v[0];
			int b = 0;
			cout << solve(v, a, b, 1);
		}
		else {
			cout << solve(v, 0, 0, 0);
		}
		cout << endl;
	}

	return 0;
}