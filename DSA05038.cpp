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
#include <climits>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 1003

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int res = 1;
vector<map<int, int>> dp;

bool check(int len, int x, int y) {
	auto it = dp[len].lower_bound(x);
	if (it == dp[len].begin()) {
		return false;
	}
	it--;
	return it->second < y;
}

void add(int len, int x, int y) {
	auto it = dp[len].lower_bound(x);
	auto tmp = it;
	while (it != dp[len].end() && it->second >= y) {
		it++;
	}
	dp[len].erase(tmp, it);
	dp[len].insert({ x, y });
}

int main() {
	int n;
	cin >> n;

	dp.resize(n + 1);

	add(0, INT_MIN, INT_MIN);

	while (n--) {
		int x, y;
		cin >> x >> y;
		int l = 0, r = res;

		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid, x, y)) {
				l = mid + 1;
			}
			else r = mid - 1;
		}

		if (res == l - 1) res++;
		add(l, x, y);
	}

	cout << res << endl;

	return 0;
}