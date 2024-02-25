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

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n), v_copy(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		v_copy = v;
		sort(v.begin(), v.end());

		bool flag = true;

		for (int i = 0; i < v_copy.size() / 2; i++) {
			if (v_copy[i] <= v_copy[v_copy.size() - i - 1]) {
				if (v_copy[i] != v[i] || v_copy[v_copy.size() - i - 1] != v[v.size() - i - 1]) {
					flag = false;
					break;
				}
			}
			else {
				if (v_copy[i] != v[v.size() - i - 1] || v_copy[v_copy.size() - i - 1] != v[i]) {
					flag = false;
					break;
				}
			}
		}

		if (!flag) cout << "No\n";
		else cout << "Yes\n";
	}

	return 0;
}