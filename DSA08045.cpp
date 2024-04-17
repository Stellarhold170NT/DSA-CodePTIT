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
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"

const int inf = 1e9;
int x[3001], y[3001];
int zx, zy;
int n, m;
int t[3001];
char map2D[6001][6001];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int cnt = 0;

int compress(int x[3001], int z) {
	memcpy(t, x, sizeof t);
	sort(t, t + z);
	int new_z = unique(t, t + z) - t;
	for (int i = 0; i < z; i++) {
		x[i] = (lower_bound(t, t + new_z, x[i]) - t) * 2;
	}

	return new_z * 2;
}

bool isSafe(int x, int y) {
	if (x > 0 && x < zx && y > 0 && y < zy && map2D[x][y] != 'X') return true;
	return false;
}

void DFS(int x, int y) {
	stack<int> stackX, stackY;
	stackX.push(x);
	stackY.push(y);
	map2D[x][y] = 'X';
	cnt = 1;

	while (!stackX.empty()) {
		int x = stackX.top();
		stackX.pop();
		int y = stackY.top();
		stackY.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isSafe(nx, ny)) {
				if (map2D[nx][ny] == 'C') {
					cnt++;
				}
				map2D[nx][ny] = 'X';
				stackX.push(nx);
				stackY.push(ny);
			}
		}
	}
}

int main() {
	faster();
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		int z = 0;
		x[z] = y[z] = -inf;
		z++;
		x[z] = y[z] = inf;
		z++;
		int ex = 2;

		for (int i = 0; i < n; i++) {
			cin >> x[z] >> y[z];
			z++;
			cin >> x[z] >> y[z];
			z++;
		}

		for (int i = 0; i < m; i++) {
			cin >> x[z] >> y[z];
			z++;
		}

		zx = compress(x, z);
		zy = compress(y, z);

		memset(map2D, '.', sizeof map2D);

		for (int i = 0; i < n; i++) {
			int a = i * 2 + ex;
			int b = i * 2 + 1 + ex;

			int x1 = x[a], y1 = y[a], x2 = x[b], y2 = y[b];

			if (x1 == x2) {
				if (y1 > y2) swap(y1, y2);
				for (int j = y1; j <= y2; j++) {
					map2D[x1][j] = 'X';
				}
			}
			else {
				if (x1 > x2) swap(x1, x2);
				for (int j = x1; j <= x2; j++) {
					map2D[j][y2] = 'X';
				}
			}
		}

		for (int i = 0; i < m; i++) {
			int a = i + n * 2 + ex;
			map2D[x[a]][y[a]] = 'C';
		}


		/*for (int i = 0; i <= zx; i++) {
			for (int j = 0; j <= zy; j++) {
				cout << map2D[i][j] << " ";
			}
			cout << endl;
		}*/

		int ans = 0;
		for (int i = 0; i < m; i++) {
			int a = i + n * 2 + ex;
			DFS(x[a], y[a]);
			ans = max(ans, cnt);
		}

		cout << ans << endl;
	}

	return 0;
}