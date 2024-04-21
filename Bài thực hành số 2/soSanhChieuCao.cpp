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
#include <unordered_map>
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

int n, len;
unordered_map<string, unordered_set<string>> mp;
unordered_map<string, int> degree;
bool check = true;

bool kahn() {
	int cnt = 0;

	queue<string> q;
	for (auto x : mp) {
		if (!degree[x.first]) {
			q.push(x.first);
		}
	}

	while (!q.empty()) {
		auto x = q.front();
		q.pop();

		cnt++;

		for (auto u : mp[x]) {
			degree[u]--;
			if (!degree[u]) q.push(u);
		}
	}

	if (cnt == len) {
		return true;
	}
	else return false;
}

int main() {
	cin >> n;

	unordered_map<string, int> dem;

	for (int i = 0; i < n; i++) {
		string a, b;
		char c;
		cin >> a >> c >> b;
		if (c == '>') {
			mp[a].insert(b);
			degree[b]++;
		}
		else {
			mp[b].insert(a);
			degree[a]++;
		}
		dem[a]++;
		dem[b]++;
		if (dem[a] == 1) len++;
		if (dem[b] == 1) len++;
	}

	check = kahn();

	if (check) cout << "possible\n";
	else cout << "impossible\n";

	return 0;
}