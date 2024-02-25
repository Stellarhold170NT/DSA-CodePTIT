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

int V, E;
bool visited[1001];

void dfs(int u, vector<int> edge[]) {
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
		cin >> V >> E;

		vector<int> edge[1001];
		memset(visited, false, sizeof visited);

		FOR(i, 1, E) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		int cnt = 0;

		FOR(i, 1, V) {
			if (!visited[i]) {
				dfs(i, edge);
				cnt++;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}