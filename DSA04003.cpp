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

map<ll, ll> mp;

ll dem(ll n) {
	if (mp[n]) return mp[n];
	if (n == 1) return mp[n] = 1;

	ll tmp = dem(n / 2) % MOD;
	if (n % 2 == 0) return mp[n] = (tmp * tmp * 2) % MOD;
	else return mp[n] = (tmp * tmp * 4) % MOD;
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		cout << dem(n) << endl;
	}

	return 0;
}