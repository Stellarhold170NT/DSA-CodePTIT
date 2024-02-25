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

string quay_trai(string s) {
	swap(s[0], s[1]);
	swap(s[0], s[4]);
	swap(s[0], s[3]);
	return s;
}

string quay_phai(string s) {
	swap(s[1], s[2]);
	swap(s[1], s[5]);
	swap(s[1], s[4]);
	return s;
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		string a;
		string b;

		for (int i = 0; i < 6; i++) {
			char c;
			cin >> c;
			a += c;
		}

		for (int i = 0; i < 6; i++) {
			char c;
			cin >> c;
			b += c;
		}

		queue<string> q;
		unordered_map<string, int> mp;

		q.push(a);

		while (!q.empty()) {
			string cur = q.front();
			q.pop();

			if (cur == b) {
				cout << mp[b] << endl;
				break;
			}

			string s1 = quay_trai(cur);
			string s2 = quay_phai(cur);

			if (!mp[s1]) {
				mp[s1] = mp[cur] + 1;
				q.push(s1);
			}

			if (!mp[s2]) {
				mp[s2] = mp[cur] + 1;
				q.push(s2);
			}
		}
	}

	return 0;
}