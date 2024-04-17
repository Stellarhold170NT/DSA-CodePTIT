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
#include <bitset>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 101;
int n, m;
int dx[] = { 1, 1, 0 };
int dy[] = { 0, 1, 1 };

bool isSafe(int nx, int ny) {
	if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) return true;
	return false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		int arr[N][N];

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
			}
		}

		int f[N][N];
		memset(f, 0, sizeof f);

		queue<pair<int, int>> q;
		q.push({ 1, 1 });

		int ans = -1;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			if (cur.first == n && cur.second == m) {
				ans = f[n][m];
				break;
			}

			for (int i = 0; i < 3; i++) {
				int x = cur.first + dx[i];
				int y = cur.second + dy[i];

				int len = 0;
				if (isSafe(x, y)) {
					len = abs(arr[x][y] - arr[cur.first][cur.second]);
				}

				if (len > 0) {
					int nx = cur.first + dx[i] * len;
					int ny = cur.second + dy[i] * len;

					if (isSafe(nx, ny) && !f[nx][ny]) {
						f[nx][ny] = f[cur.first][cur.second] + 1;
						q.push({ nx, ny });
					}
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}