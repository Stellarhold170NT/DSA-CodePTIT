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

	vector<ll> v;

	v.push_back(9);
	ll tmp = 9;

	while (tmp * 10 < 900000000000000000) {
		tmp = tmp * 10;
		int sz = v.size();
		v.push_back(tmp);
		for (int i = 0; i < sz; i++) v.push_back(tmp + v[i]);
	}

	while (t--) {
		int n;
		cin >> n;

		for (auto x : v) {
			if (x % n == 0) {
				cout << x << endl;
				break;
			}
		}
	}
}