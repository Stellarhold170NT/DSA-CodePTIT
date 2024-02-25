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
bool check;
int visited[1001];

void dfs(int s, vector<int> edges[]) {
	if (check == true) return;
	visited[s] = 1;

	for (auto x : edges[s]) {
		if (!visited[x]) {
			dfs(x, edges);
		}
		else
			if (visited[x] == 1) {
				check = true;
				return;
			}

	}
	visited[s] = 2;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int v, e;
		cin >> v >> e;

		vector<int> edges[1001];
		memset(visited, 0, sizeof visited);

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			//edges[b].push_back(a);
		}

		check = false;

		for (int i = 1; i <= v && !check; i++) {
			if (!visited[i]) {
				dfs(i, edges);
			}
		}

		if (check == true) cout << "YES";
		else cout << "NO";

		cout << endl;
	}

	return 0;
}