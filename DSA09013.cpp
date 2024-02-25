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

bool visited[10000];

void dfs(int u, vector<int> edge[1001]) {
	//cout << u << " ";
	visited[u] = true;
	for (auto x : edge[u]) {
		if (!visited[x]) {
			dfs(x, edge);
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int V, E;
		cin >> V >> E;

		vector<int> edge[1001];

		FOR(i, 1, E) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}


		FOR(i, 1, V) {
			for (int j = 0; j < edge[i].size(); j++) {
				int node = edge[i][j];
				edge[i].erase(edge[i].begin() + j);


				dfs(i, edge);

				bool check = false;

				FOR(k, 1, V) if (!visited[k]) {
					check = true;
					break;
				}

				if (check) {
					//cout << i << " " << j << endl;
					if (i < node) cout << i << " " << node << " ";
				}

				edge[i].insert(edge[i].begin() + j, node);
				memset(visited, false, sizeof visited);
			}
			cout << endl;
		}
	}

	return 0;
}

