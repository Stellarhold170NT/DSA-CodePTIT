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

string s;
int k;
string tmp = "";
int dd[100] = { 0 };
vector<string> res;

void Try(int i) {
	if (i == s.length() || tmp.length() == k) {
		if (tmp.length() == k) res.push_back(tmp);
		return;
	}

	for (int j = i; j < s.length(); j++) {
		tmp += s[j];
		Try(j + 1);
		tmp.pop_back();
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> s >> k;

		res.clear();
		memset(dd, 0, sizeof dd);

		Try(0);

		sort(res.begin(), res.end());

		unordered_map<string, int> mp;

		for (auto x : res) {
			if (!mp[x]) {
				mp[x] = 1;
				cout << x << endl;
			}
		}

	}
	return 0;
}