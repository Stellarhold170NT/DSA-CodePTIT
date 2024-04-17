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

struct item {
	int value, weight;
	double r;
};

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, w;
		cin >> n >> w;

		vector<item> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i].value >> v[i].weight;
			v[i].r = 1.0 * v[i].value / v[i].weight;
		}

		sort(v.begin(), v.end(), [](item a, item b) {
			return a.r > b.r;
			});

		int idx, sum, totalValue;
		idx = sum = totalValue = 0;

		for (int i = 0; i < n; i++) {
			if (sum < w) {
				sum += v[i].weight;
				totalValue += v[i].value;
				idx = i;
			}
		}

		double res = totalValue;
		if (sum > w) {
			res = 1.0 * totalValue - 1.0 * (sum - w) * v[idx].r;
		}

		cout << stp(2) << res << endl;
	}

	return 0;
}