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
vector<string> v;
int dx[] = { 0, -1, -1 , -1, 0, 1, 1, 1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
bool visited[101][101];

bool isSafe(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m && v[x][y] == 'W') return true;
	return false;
}
void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isSafe(nx, ny)) {
			if (!visited[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}

}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	v.resize(n);
	memset(visited, false, sizeof visited);
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, v[i]);
	}
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'W' && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}