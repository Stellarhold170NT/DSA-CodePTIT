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
#define MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 5000000 + 11
#define MOD (ll) 998244353
#define ld long double
#define sz size()
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
		vector<int> arr(n);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		stack<int> st;

		vector<int> res(n);

		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && arr[i] >= st.top()) st.pop();
			if (!st.empty()) {
				res[i] = st.top();
			}
			else {
				res[i] = -1;
			}
			st.push(arr[i]);
		}

		for (auto x : res) cout << x << " ";
		cout << endl;
	}

	return 0;
}