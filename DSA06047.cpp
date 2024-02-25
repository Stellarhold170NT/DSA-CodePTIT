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
#include <bitset>
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
		int n;
		cin >> n;

		vector<ll> v(n);

		map<ll, ll > mp;

		for (auto& i : v) {
			cin >> i;
			i = i * i;
			mp[i] = 1;
		}

		bool flag = false;

		for (int i = 0; i < n && !flag; i++) {
			for (int j = i + 1; j < n && !flag; j++) {
				if (mp[v[i] + v[j]]) {
					cout << "YES\n";
					flag = true;
				}
			}
		}

		if (!flag) cout << "NO\n";
	}

	return 0;
}