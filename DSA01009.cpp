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
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, k;
vector<string> res;

void Try(string s, int cntA, bool checkA) {
	if (s.length() == n) {
		if (checkA) res.push_back(s);
		return;
	}

	Try(s + "B", 0, checkA);

	if (cntA + 1 == k && !checkA) {
		Try(s + "A", cntA + 1, true);
	}
	else if (cntA + 1 < k) {
		Try(s + "A", cntA + 1, checkA);
	}
}

int main() {
	cin >> n >> k;

	Try("", 0, false);

	cout << res.size() << endl;
	sort(res.begin(), res.end());
	for (auto x : res) cout << x << endl;

	return 0;
}