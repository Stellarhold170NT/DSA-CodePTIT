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

bool visited[1001];
vector<pair<int, int>> res;

void bfs(int s, vector<int> edges[]) {
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int current_node = q.front();
		q.pop();


		for (auto x : edges[current_node]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
				res.push_back({ current_node,x });
			}
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, u;
		cin >> n >> m >> u;

		res.clear();

		vector<int> edges[1001];
		memset(visited, false, sizeof visited);

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		bfs(u, edges);
		if (res.size() == n - 1) {
			for (auto x : res) {
				cout << x.first << " " << x.second << endl;
			}
		}
		else cout << -1 << endl;

	}
}