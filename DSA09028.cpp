#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
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
#include <bitset>
#include <unordered_set>
using namespace std;

#define ll long long
//#define MAX (long long) 1000000000000000000
//#define M 100 + 5
//#define N 5000000 + 11
#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int v, e, m;
int color[11];

bool isColoring(int s, int c, vector<int> edge[]) {
	for (int x : edge[s]) {
		if (color[x] && c == color[x]) {
			return false;
		}
	}
	return true;
}
bool dfs(int s, vector<int> edge[]) {
	if (s == v + 1) return true;

	for (int i = 1; i <= m; i++) {
		if (isColoring(s, i, edge)) {
			color[s] = i;

			if (dfs(s + 1, edge) == true) return true;

			color[s] = 0;
		}
	}

	return false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> v >> e >> m;

		vector<int> edge[11];
		memset(color, 0, sizeof color);

		for (int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;

			edge[x].push_back(y);
			edge[y].push_back(x);
		}

		if (dfs(1, edge)) cout << "YES\n";
		else cout << "NO\n";

		//for (int i = 1; i <= v; i++) cout << color[i] << " ";
		//cout << endl;
	}

	return 0;
}