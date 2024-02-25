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

int n, m;
bool visited[1001] = { false };

void dfs(int s, vector<int> edges[]) {
	visited[s] = true;

	for (auto x : edges[s]) {
		if (!visited[x]) {
			dfs(x, edges);
		}
	}
}

int count(vector<int> edges[]) {
	int lienThong = 0;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, edges);
			lienThong++;
		}
	}

	return lienThong;
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		vector<int> edges[1001];
		memset(visited, false, sizeof visited);

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		int lienThong = count(edges);

		for (int i = 1; i <= n; i++) {
			memset(visited, false, sizeof visited);
			visited[i] = true;
			if (count(edges) > lienThong) cout << i << " ";
		}

		cout << endl;

	}

	return 0;
}