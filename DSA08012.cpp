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

bool check(string s) {
	for (int i = 0; i < s.length(); i++) {
		for (int j = i + 1; j < s.length(); j++) {
			if (s[i] == s[j]) return false;
		}
	}

	return true;
}

int main() {
	queue<string> q;
	q.push("");

	vector<int> res;

	while (!q.empty()) {
		string cur = q.front();
		q.pop();

		if (cur == "0") continue;

		for (int i = 0; i <= 5; i++) {
			string tmp = cur + to_string(i);
			if (stoi(tmp) > 100000) break;
			if (check(tmp)) {
				q.push(tmp);
				res.push_back(stoi(tmp));
			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int l, r;
		cin >> l >> r;

		auto idx1 = lower_bound(res.begin(), res.end(), l);
		auto idx2 = upper_bound(res.begin(), res.end(), r);
		cout << idx2 - idx1 << endl;
	}

	return 0;
}