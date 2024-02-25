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
	vector<ll> v;
	v.push_back(1);

	ll tmp = 1;

	while (tmp <= 100000000000000000) {
		tmp *= 10;
		v.push_back(tmp);
		int sz = v.size() - 1;
		for (int i = 0; i < sz; i++) {
			v.push_back(tmp + v[i]);
		}
	}

	//for (auto x : v) cout << x << endl;

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		cout << upper_bound(v.begin(), v.end(), n) - v.begin() << endl;
	}

	return 0;
}
