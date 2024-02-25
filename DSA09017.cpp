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

bool visited[1001] = { false };
bool check = true;

void bfs(int s, int n, vector<int> edges[]) {
	queue<int> q;
	visited[s] = true;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto x : edges[cur]) {
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
		int n;
		cin >> n;

		vector<int> edges[1001];
		memset(visited, false, sizeof visited);

		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		check = true;

		bfs(1, n, edges);

		for (int i = 1; i <= n && check; i++) {
			if (!visited[i]) {
				check = false;
			}
		}

		if (check) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}