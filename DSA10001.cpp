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
#define MAX 510
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
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
vector<string> c;
bool visited[MAX][MAX];
bool check;

bool isSafe(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m && c[x][y] != '*') return true;
	return false;
}

int findDir(int dx, int dy) {
	if (dx == 0) {
		return dy > 0 ? 4 : 3;
	}
	else if (dy == 0) {
		return dx > 0 ? 2 : 1;
	}
}

/*
	direction
	1 - up
	2 - down
	3 - left
	4 - right
*/

void dfs(int x, int y, int turn, int direction) {
	//cout << x << " " << y << " " << turn << endl;
	if (check) return;
	if (turn > 2) return;
	if (c[x][y] == 'T' && turn <= 2) {
		//cout << turn << endl;
		check = true;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (isSafe(nextX, nextY)) {
			if (!visited[nextX][nextY]) {
				visited[nextX][nextY] = true;
				int dir = findDir(nextX - x, nextY - y);
				int newTurn = turn;
				if (direction && dir != direction) {
					newTurn++;
				}
				//direction = dir;
				dfs(nextX, nextY, newTurn, dir);
				visited[nextX][nextY] = false;
			}

		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		c.resize(n);
		memset(visited, false, sizeof visited);

		cin.ignore();

		for (int i = 0; i < n; i++) {
			getline(cin, c[i]);
		}

		int x, y;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] == 'S') {
					x = i;
					y = j;
				}
			}
		}
		check = false;
		dfs(x, y, 0, 0);

		if (check) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}