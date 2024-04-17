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

int r, c;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, 1, -1, 0 };
int a[501][501];

bool isSafe(int x, int y) {
	if (x >= 1 && x <= r && y >= 1 && y <= c && a[x][y] == 1) return true;
	return false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> r >> c;

		int cnt = 0;

		queue<pair<int, int>> q;
		int day[501][501];
		memset(day, 0, sizeof day);

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> a[i][j];
				if (a[i][j] == 2) q.push({ i, j });
				if (a[i][j] == 1) cnt++;
			}
		}

		int ans = -1;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (isSafe(nx, ny) && !day[nx][ny]) {
					cnt--;
					a[nx][ny] = 2;
					day[nx][ny] = day[cur.first][cur.second] + 1;
					if (!cnt) {
						ans = day[nx][ny];
						break;
					}
					q.push({ nx, ny });
				}

			}
		}

		cout << ans << endl;

	}

	return 0;
}