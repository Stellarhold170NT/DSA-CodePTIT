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
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 1003

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

const int LIM = 100;
int n, m;
int edge[LIM][LIM];
bool visited[1001] = { false };
int res = 0;

void dfs(int x, int length) {
	res = max(res, length);
	for (int y = 0; y < n; y++)
		if (edge[x][y]) {
			edge[x][y] = edge[y][x] = 0;
			dfs(y, length + 1);
			edge[x][y] = edge[y][x] = 1;
		}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		memset(visited, false, sizeof visited);
		memset(edge, 0, sizeof edge);
		res = 0;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			edge[a][b] = edge[b][a] = 1;
		}

		for (int i = 0; i < n; i++) {
			dfs(i, 0);
		}

		cout << res << endl;
	}
	return 0;
}