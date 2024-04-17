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

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int l1[] = { 3, 0, 2, 7, 4, 1, 6, 8, 5, 9 };
int r1[] = { 0, 4, 1, 3, 8, 5, 2, 7, 9, 6 };
int l2[] = { 1, 5, 2, 0, 4, 8, 6, 3, 7, 9 };
int r2[] = { 0, 2, 6, 3, 1, 5, 9, 7, 4, 8 };

string Change(string s, int t[]) {
	string x = "";
	for (int i = 0; i < 10; i++) {
		x += s[t[i]];
	}
	return x;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string a, b = "1238004765";
		for (int i = 0; i < 10; i++) {
			int x;
			cin >> x;
			a += to_string(x);
		}

		int limit = 14;

		queue<string> q1;
		q1.push(a);

		map<string, int> mp;

		while (!q1.empty()) {
			string cur = q1.front();
			q1.pop();

			string tmp1 = Change(cur, l1);
			string tmp2 = Change(cur, r1);

			if (!mp[tmp1]) {
				mp[tmp1] = mp[cur] + 1;
				q1.push(tmp1);
			}

			if (!mp[tmp2]) {
				mp[tmp2] = mp[cur] + 1;
				q1.push(tmp2);
			}

			if (mp[tmp2] == limit) break;
		}

		queue<pair<string, int>> q2;
		q2.push({ b, 0 });

		int ans = 1e9;

		while (!q2.empty()) {
			pair<string, int> cur = q2.front();
			q2.pop();

			if (mp[cur.first]) {
				ans = min(ans, mp[cur.first] + cur.second);
			}

			q2.push({ Change(cur.first, l2), cur.second + 1 });
			q2.push({ Change(cur.first, r2), cur.second + 1 });
			if (cur.second + 1 == limit) break;
		}

		cout << ans << endl;
	}
	return 0;
}