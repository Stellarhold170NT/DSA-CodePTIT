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
#define N 200

//#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, m;
int arr[N][N];
int visited[N][N];
int dx[2] = { 1, 0 };
int dy[2] = { 0 , 1 };
string road = "";
int cnt = 0;
set<string> res;

bool isSafe(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m) return true;
	return false;
}

void dfs(int x, int y) {
	visited[x][y] = 1;

	if (x == n - 1 && y == m - 1) {
		cnt++;
		//cout << "YES\n";
		return;
	}

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isSafe(nx, ny)) {
			if (!visited[nx][ny]) {
				dfs(nx, ny);
				visited[nx][ny] = 0;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		memset(visited, 0, sizeof visited);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		cnt = 0;
		dfs(0, 0);

		cout << cnt << endl;
	}

	return 0;
}