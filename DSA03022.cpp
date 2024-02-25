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
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	if (v[0] < 0 && v[1] < 0) {
		int a = v[0] * v[1];

		int tmp1 = a;
		int tmp2 = 0;
		if (v[n - 1] > 0) {
			tmp1 = a * v[n - 1];
		}

		if (v[n - 1] > 0 && v[n - 2] > 0) {
			tmp2 = v[n - 1] * v[n - 2];
			if (v[n - 3] > 0) tmp2 *= v[n - 3];
		}

		cout << max(tmp2, tmp1) << endl;
	}
	else {
		int tmp = v[n - 1] * v[n - 2];
		if (v[n - 3] > 0) tmp *= v[n - 3];
		cout << tmp;
	}

	return 0;
}