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
#define MAX (long long) 1000000000000000000
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

void dfs(int u, vector<int> edge[1001]) {
	visited[u] = true;
	cout << u << " ";
	for (auto x : edge[u]) {
		if (!visited[x]) {
			dfs(x, edge);
		}
	}
}

void bfs(int u, vector<int> edge[1001]) {
	queue<int> q;
	q.push(u);

	visited[u] = true;

	while (!q.empty()) {
		int current_node = q.front();
		q.pop();

		cout << current_node << " ";

		for (auto x : edge[current_node]) {
			if (!visited[x]) {
				visited[x] = true;
				q.push(x);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int V, E, start;
		cin >> V >> E >> start;

		vector<int> edge[1001];

		memset(visited, false, sizeof visited);

		FOR(i, 1, E) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
		}

		bfs(start, edge);
		cout << endl;
	}

	return 0;
}