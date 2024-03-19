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
		int n;
		cin >> n;

		vector<pii> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}

		sort(v.begin(), v.end());

		int f[101] = { 0 };
		f[0] = 1;
		int mx = 1;

		for (int i = 1; i < n; i++) {
			f[i] = 1;
			for (int j = 0; j < i; j++) {
				if (v[i].first > v[j].second) {
					f[i] = max(f[i], f[j] + 1);
				}
			}
			mx = max(mx, f[i]);
		}

		cout << mx << endl;
	}

	return 0;
}
