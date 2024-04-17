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

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"


bool check(string a, string b) {
	int cnt = 0;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i]) cnt++;
	}

	return cnt == 1;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string a, b;
		cin >> n >> a >> b;

		unordered_set<string> s;

		for (int i = 0; i < n; i++) {
			string sTmp;
			cin >> sTmp;
			s.insert(sTmp);
		}


		queue<pair<string, int>> q;
		unordered_map<string, int> mp;
		q.push({ a, 1 });
		int ans = 0;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			string tmp = cur.first;

			if (tmp == b) {
				ans = cur.second;
				break;
			}
			for (int i = 0; i < tmp.size(); i++) {
				char originalChar = tmp[i];

				for (char j = 'A'; j <= 'Z'; j++) {
					tmp[i] = j;

					if (s.find(tmp) != s.end() && !mp[tmp]) {
						mp[tmp] = 1;
						q.push({ tmp, cur.second + 1 });
					}
				}
				tmp[i] = originalChar;
			}
		}

		cout << ans << endl;
	}

	return 0;
}