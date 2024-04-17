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


int main() {
	int t;
	cin >> t;

	while (t--) {
		char c[101][101];

		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> c[i][j];
			}
		}

		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;
		startX++; startY++;
		endX++; endY++;

		int f[101][101];
		memset(f, 0, sizeof f);

		queue<pair<int, int>> q;
		q.push({ startX, startY });
		f[startX][startY] = 1;

		int ans = -1;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			if (cur.first == endX && cur.second == endY) {
				ans = f[cur.first][cur.second];
				break;
			}

			int x = cur.first + 1;

			while (x <= n) {
				if (!f[x][cur.second] && c[x][cur.second] == '.') {
					f[x][cur.second] = f[cur.first][cur.second] + 1;
					q.push({ x, cur.second });
				}
				else if (c[x][cur.second] == 'X') break;
				x++;
			}

			x = cur.first - 1;

			while (x >= 1) {
				if (!f[x][cur.second] && c[x][cur.second] == '.') {
					f[x][cur.second] = f[cur.first][cur.second] + 1;
					q.push({ x, cur.second });
				}
				else if (c[x][cur.second] == 'X') break;
				x--;
			}

			int y = cur.second + 1;

			while (y <= n) {
				if (!f[cur.first][y] && c[cur.first][y] == '.') {
					f[cur.first][y] = f[cur.first][cur.second] + 1;
					q.push({ cur.first, y });
				}
				else if (c[cur.first][y] == 'X') break;

				y++;
			}

			y = cur.second - 1;

			while (y >= 1) {
				if (!f[cur.first][y] && c[cur.first][y] == '.') {
					f[cur.first][y] = f[cur.first][cur.second] + 1;
					q.push({ cur.first, y });
				}
				else if (c[cur.first][y] == 'X') break;

				y--;
			}

		}

		cout << ans - 1 << endl;
	}

	return 0;
}