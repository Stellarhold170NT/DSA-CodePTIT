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

bool check(string s) {
	if (s.empty() || (s.length() == 1 && isalpha(s[0]))) return false;
	stack<char> st;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') st.push(s[i]);
		else if (s[i] == ')') {
			if (!st.empty() && st.top() == '(') st.pop();
			else return false;
		}
	}

	return st.empty();
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		if (check(s)) {
			cout << s << endl;
			continue;
		}

		map<string, bool> mp;

		queue < pair<string, int>> q;
		q.push({ s, 0 });

		vector <string> v;

		bool flag = false;
		int cnt = 0;

		while (!q.empty()) {
			auto tmp = q.front();
			q.pop();


			if (check(tmp.first)) {
				if (!flag) {
					v.push_back(tmp.first);
					flag = true;
					cnt = tmp.second;
				}
				else if (tmp.second == cnt) {
					v.push_back(tmp.first);
				}
			}

			if (flag) continue;


			if (!tmp.first.empty())
				for (int i = 0; i < tmp.first.length(); i++) {
					if (!isalpha(tmp.first[i])) {
						string str = tmp.first.substr(0, i) + tmp.first.substr(i + 1);
						if (!mp[str]) {
							q.push({ str, tmp.second + 1 });
							mp[str] = 1;
						}
					}
				}
		}

		if (!flag) cout << -1;
		sort(v.begin(), v.end());
		for (auto x : v) cout << x << " ";
		cout << endl;
	}

	return 0;
}