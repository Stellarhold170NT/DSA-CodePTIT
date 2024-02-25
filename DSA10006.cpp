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
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
#define MAX 510
//#define M 100 + 5
#define N 5000000 + 11
#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

vector<pair<int, int>> res;
bool visited[1001];

void dfs(int s, vector<int> edge[]) {
	visited[s] = true;

	for (auto x : edge[s]) {
		if (!visited[x]) {
			res.push_back({ s, x });
			dfs(x, edge);
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int v, e, u;
		cin >> v >> e >> u;

		memset(visited, false, sizeof visited);
		res.clear();

		vector<int> edge[1001];
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		dfs(u, edge);

		if (res.size() == v - 1) {
			for (int i = 0; i < res.size(); i++) {
				cout << res[i].first << " " << res[i].second << endl;
			}
		}
		else cout << -1 << endl;

	}

	return 0;
}