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
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"

ll len[51];

int Find(int idx, ll n, ll i) {
	ll mid = len[idx - 1] + 1;
	if (i == mid) return n & 1;
	else if (i < mid) return Find(idx - 1, n / 2, i);
	else return Find(idx - 1, n / 2, i - mid);
}

int main() {
	faster();

	int t;
	cin >> t;

	while (t--) {
		ll n, l, r;
		cin >> n >> l >> r;

		ll nCopy = n;

		memset(len, 0, sizeof len);
		int idx = 1;

		while (n) {
			len[idx] = pow((ll)2, (ll)idx) - 1;
			n /= 2;
			idx++;
		}

		int cnt = 0;

		for (ll i = l; i <= r; i++) {
			cnt += Find(idx - 1, nCopy, i);
		}

		cout << cnt << endl;
	}

	return 0;
}