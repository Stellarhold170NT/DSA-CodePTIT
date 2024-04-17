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
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, k;
vector<string> res;

void Try(string s, int cnt0, bool check0) {
	if (s.length() == n + n) {
		if (check0) res.push_back(s);
		return;
	}

	if (cnt0 + 1 == k && !check0) {
		Try(s + '0' + ' ', cnt0 + 1, true);
	}
	else if (cnt0 + 1 < k) {
		Try(s + '0' + ' ', cnt0 + 1, check0);
	}

	Try(s + '1' + ' ', 0, check0);

}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		Try("", 0, false);
		cout << res.size() << endl;
		for (auto x : res) cout << x << endl;
	}

	return 0;
}