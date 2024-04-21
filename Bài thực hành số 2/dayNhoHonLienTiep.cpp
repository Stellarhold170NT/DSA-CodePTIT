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
#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		stack<pair<int, int>> st;

		vector<int> v(n);
		for (auto& i : v) cin >> i;

		for (int i = 0; i < n; i++) {
			while (st.size() && v[i] >= st.top().first) {
				st.pop();
			}

			if (st.empty()) {
				cout << i + 1 << " ";
			}
			else {
				cout << i - st.top().second << " ";
			}

			st.push({ v[i], i });
		}

		cout << endl;
	}

	return 0;
}