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

int V, E, start, _end;
bool visited[1001];
int par[1001];

void dfs(int u, vector<int> edge[]) {
	//cout << u << " ";
	visited[u] = true;
	if (u == _end) return;


	for (auto x : edge[u]) {
		if (!visited[x]) {
			par[x] = u;
			dfs(x, edge);
		}
	}

}

void bfs(int u, vector<int> edge[]) {
	queue<int> q;
	q.push(u);
	visited[u] = true;

	while (!q.empty()) {
		int current_node = q.front();
		q.pop();


		for (auto x : edge[current_node]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
				par[x] = current_node;
			}
		}
	}
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> V >> E >> start >> _end;

		vector<int> edge[1001];
		memset(visited, false, sizeof visited);
		memset(par, 0, sizeof par);

		FOR(i, 1, E) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
		}

		bfs(start, edge);
		if (!visited[_end]) {
			cout << -1;
		}
		else {
			vector<int> path;
			path.push_back(_end);

			int tmp = par[_end];
			while (tmp != start) {
				path.push_back(tmp);
				tmp = par[tmp];
			}

			path.push_back(start);
			reverse(path.begin(), path.end());

			for (int j = 0; j < path.size(); j++) {
				cout << path[j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}