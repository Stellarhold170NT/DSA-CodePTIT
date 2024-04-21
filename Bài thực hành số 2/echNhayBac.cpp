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

const int N = 100001;

int main() {
	int n;
	cin >> n;
	int q;
	cin >> q;
	int a[N];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int res[N];
	res[n - 1] = -1;
	stack<int> st;
	st.push(n - 1);

	for (int i = n - 2; i >= 0; i--) {
		if (st.size() && a[i] < a[st.top()]) {
			res[i] = st.top();
			st.push(i);
		}
		else {
			while (st.size() && a[i] >= a[st.top()]) st.pop();
			if (st.size()) res[i] = st.top();
			else res[i] = -1;
			st.push(i);
		}
	}

	while (q--) {
		int x;
		cin >> x;
		x--;
		int cnt = 0;
		while (x != -1) {
			x = res[x];
			cnt++;
		}
		cout << cnt - 1 << endl;
	}

	return 0;
}

