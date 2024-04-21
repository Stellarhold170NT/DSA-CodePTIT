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
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

bool visited[1001] = { false };
int par[1001] = { 0 };
vector<int> edge[1001];
int n, m, u, v;

void bfs() {
	queue<int> q;
	q.push(u);

	bool check = false;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur == v) {
			check = true;
			break;
		}

		for (auto x : edge[cur]) {
			if (!visited[x]) {
				q.push(x);
				par[x] = cur;
				q.push(x);
			}
		}
	}

	if (check) {
		stack<int> st;
		while (true) {
			st.push(v);
			if (v == u) break;
			v = par[v];
		}

		while (st.size()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
	else {
		cout << -1 << endl;
	}
}

int main() {
	faster();
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m >> u >> v;

		for (int i = 0; i <= n; i++) ke[i].clear();
		memset(visited, false, sizeof visited);
		memset(par, 0, sizeof par);

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
		}

		bfs();
	}

	return 0;
}