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

#define int long long
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

main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		unordered_map<int, int> mp;

		vector<int> v(n);
		cin >> v[0];
		mp[v[0]] = 1;
		mp[0] = 1;

		bool check = false;

		for (int i = 1; i < n; i++) {
			cin >> v[i];
			v[i] += v[i - 1];
			if (mp[v[i] - k]) check = true;
			mp[v[i]] = 1;
		}

		if (check) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}