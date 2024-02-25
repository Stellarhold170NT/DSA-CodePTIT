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

int side[1001];
bool check;
bool visited[1001];

void dfs(int s, vector<int> edge[]) {
	visited[s] = true;
	if (!check) return;

	for (auto x : edge[s]) {
		if (!visited[x]) {
			//if (!side[x])
			side[x] = 1 - side[s];
			dfs(x, edge);
		}
		else if (side[x] == side[s]) {
			check = false;
			return;
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int v, e;
		cin >> v >> e;

		vector<int> edge[1001];
		memset(side, 0, sizeof side);
		memset(visited, false, sizeof visited);

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		check = true;

		for (int i = 1; i <= v && check; i++) {
			//memset(visited, false, sizeof visited);
			if (!visited[i]) {
				dfs(i, edge);
			}
		}

		if (check) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}