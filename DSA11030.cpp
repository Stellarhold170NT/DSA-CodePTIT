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
#include <bitset>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'



inline void DFS(int u, vector<int> edge[], int h[], int p[10][1001]) {
	for (auto x : edge[u]) if (x != p[0][u]) {
		h[x] = h[u] + 1;
		p[0][x] = u;
		for (int i = 1; i <= 9; i++) {
			p[i][x] = p[i - 1][p[i - 1][x]];
		}
		DFS(x, edge, h, p);
	}
}

inline int LCA(int u, int v, vector<int> edge[], int h[], int p[10][1001]) {
	if (h[u] < h[v]) swap(u, v);

	int delta = h[u] - h[v];

	for (int i = 0; i <= 9; i++) {
		if ((delta >> i) & 1) {
			u = p[i][u];
		}
	}

	if (u == v) return u;

	for (int i = 9; i >= 0; i--) {
		if (p[i][u] != p[i][v]) {
			u = p[i][u];
			v = p[i][v];
		}
	}

	return p[0][u];
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		vector<int> edge[1001];
		int h[1001];
		int p[10][1001];

		int n;
		cin >> n;

		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		DFS(1, edge, h, p);
		int q;
		cin >> q;

		while (q--) {
			int u, v;
			cin >> u >> v;

			int father = LCA(u, v, edge, h, p);

			cout << h[u] - h[father] + h[v] - h[father] << endl;
		}
	}

	return 0;
}