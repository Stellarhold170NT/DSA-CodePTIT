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

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);
		unordered_map<int, int> mp;

		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mp[v[i]]++;
		}

		stack<pair<int, int>> st;

		int R[1000001] = { 0 };
		R[n - 1] = -1;
		st.push({ mp[v.back()] , n - 1 });

		for (int i = n - 2; i >= 0; i--) {
			while (!st.empty() && mp[v[i]] >= st.top().first) {
				st.pop();
			}

			if (st.empty()) {
				R[i] = -1;
			}
			else {
				R[i] = v[st.top().second];
			}


			st.push({ mp[v[i]] , i });
		}

		for (int i = 0; i < n; i++) cout << R[i] << " ";
		cout << endl;
	}

	return 0;
}