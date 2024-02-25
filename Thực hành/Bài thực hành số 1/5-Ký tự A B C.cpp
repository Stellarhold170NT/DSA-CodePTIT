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

int n;
vector<string> res;

void Try(string s, int cntA, int cntB, int cntC) {
	if (s.length() <= n) {
		if (cntA && cntB && cntC && cntA <= cntB && cntB <= cntC) res.push_back(s);
		if (s.length() == n) return;
	}

	Try(s + 'A', cntA + 1, cntB, cntC);
	Try(s + 'B', cntA, cntB + 1, cntC);
	Try(s + 'C', cntA, cntB, cntC + 1);
}

int main() {
	cin >> n;

	Try("", 0, 0, 0);

	sort(res.begin(), res.end(), [](string a, string b) {
		if (a.size() == b.size()) return a <= b;
		else return a.size() < b.size();
		});

	for (auto x : res) cout << x << endl;

	return 0;
}