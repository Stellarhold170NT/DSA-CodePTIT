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
		int n, k;
		cin >> n >> k;

		k = min(k, n - k);

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		int s1 = 0;
		for (int i = 0; i < k; i++) {
			s1 = s1 + v[i];
		}

		int s2 = 0;
		for (int i = k; i < n; i++) {
			s2 = s2 + v[i];
		}

		cout << s2 - s1 << endl;
	}

	return 0;
}