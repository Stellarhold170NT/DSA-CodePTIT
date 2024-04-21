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


inline bool doixung(string s) {
	string tmp = s;
	reverse(tmp.begin(), tmp.end());
	return tmp == s;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int m = n / 2;
		if (n % 2 == 1) m++;

		queue<string> q;

		q.push("6");
		q.push("8");

		vector<string> res;

		res.push_back("6");
		res.push_back("8");

		while (q.front().size() < m) {
			queue<string> tmp;

			while (!q.empty()) {
				res.push_back(q.front() + "6");
				res.push_back(q.front() + "8");
				tmp.push(q.front() + "6");
				tmp.push(q.front() + "8");
				q.pop();
			}

			q = tmp;
		}

		int rz = res.size();
		for (int i = 0; i < rz; i++) {
			string s = res[i];
			if (s.size() * 2 > m && s.size() * 2 <= n) {
				string sr = s;
				reverse(sr.begin(), sr.end());
				res.push_back(s + sr);
			}

			if (s.size() * 2 - 1 > m && s.size() * 2 - 1 <= n) {
				string sr = s;
				sr.pop_back();
				reverse(sr.begin(), sr.end());
				res.push_back(s + sr);
			}
		}

		sort(res.begin(), res.end(), [](string a, string b) {
			return (a.size() < b.size()) || (a.size() == b.size() && a < b);
			});

		for (auto x : res)
			if (doixung(x)) cout << x << endl;
		cout << endl;

	}

	return 0;
}