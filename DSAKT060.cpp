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
#include <bitset>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int n = 1e5 + 5, prime = 17, mod = 1e9 + 3;
ll Pow[n] = { 0 };
ll fenwick1[n] = { 0 }, fenwick2[n] = { 0 };
ll len = 0;

inline void update(int idx, int x) {
	ll val = Pow[idx] * x;
	for (ll i = idx; i <= len; i += (i & (-i))) {
		fenwick1[i] += val;
	}

	val = Pow[len - idx + 1] * x;

	while (idx) {
		fenwick2[idx] += val;
		idx -= (idx & (-idx));
	}
}

inline ll get1(int idx) {
	ll res = 0;
	while (idx) {
		res += fenwick1[idx];
		idx -= (idx & (-idx));
	}
	return res;
}

inline ll get2(int idx) {
	ll res = 0;
	while (idx <= len) {
		res += fenwick2[idx];
		idx += (idx & (-idx));
	}
	return res;
}


int main() {
	string s;
	int q;

	cin >> s >> q;
	len = s.size();

	s = " " + s;

	Pow[0] = 1;
	for (int i = 1; i <= len; i++) {
		Pow[i] = Pow[i - 1] * prime;
	}

	for (int i = 1; i <= len; i++) {
		update(i, s[i]);
	}

	while (q--) {
		char c;
		cin >> c;

		if (c == 'c') {
			int pos;
			char x;
			cin >> pos >> x;
			update(pos, x - s[pos]);
			s[pos] = x;
		}
		else {
			int l, r;
			cin >> l >> r;
			ll g1 = (get1(r) - get1(l - 1)) * Pow[len - r + 1];
			ll g2 = (get2(l) - get2(r + 1)) * Pow[l];
			if (g1 == g2) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}

	return 0;
}