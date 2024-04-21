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

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

const int N = 1001;

int calc(int a[N], int n) {
	stack<int> L;
	stack<int> R;

	int left[N];
	int right[N];

	L.push(0);
	for (int i = 0; i < n; i++) {
		while (L.size() && a[L.top()] >= a[i]) {
			L.pop();
		}

		if (L.empty()) {
			left[i] = 0;
		}
		else left[i] = L.top() + 1;
		L.push(i);
	}

	R.push(n - 1);
	for (int i = n - 1; i >= 0; i--) {
		while (R.size() && a[R.top()] >= a[i]) {
			R.pop();
		}

		if (R.empty()) {
			right[i] = n - 1;
		}
		else right[i] = R.top() - 1;
		R.push(i);
	}

	long long res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, (long long)(right[i] - left[i] + 1) * a[i]);
	}

	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, n;
	cin >> m >> n;

	int a[N];
	int b[N];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = m - a[i];
	}

	ll ans1 = calc(a, n);
	ll ans2 = calc(b, n);

	cout << max(ans1, ans2) << endl;

	return 0;
}