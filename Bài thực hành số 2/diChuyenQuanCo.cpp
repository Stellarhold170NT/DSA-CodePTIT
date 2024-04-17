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

int n;
char c[101][101];
int d1[101][101]; // distance of Knight
int d2[101][101]; // distance of King


int dx1[] = { -1, -1, 1, 1, -2, -2, 2 , 2 };
int dy1[] = { -2, 2, -2, 2, -1, 1, -1, 1 };

int dx2[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy2[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

class Position {
public:
	int x;
	int y;
};

bool isSafe(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= n && c[x][y] == '.') return true;
	return false;
}

int main() {
	cin >> n;

	Position kingPos;
	Position knightPos;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'M') {
				knightPos.x = i;
				knightPos.y = j;
			}

			if (c[i][j] == 'T') {
				kingPos.x = i;
				kingPos.y = j;
			}
		}
	}

	memset(d1, 0, sizeof d1);
	memset(d2, 0, sizeof d2);

	queue<Position> q;
	q.push(knightPos);

	int depthSearch = 50;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cur.x + dx1[i];
			int ny = cur.y + dy1[i];

			if (isSafe(nx, ny) && !d1[nx][ny]) {
				d1[nx][ny] = d1[cur.x][cur.y] + 1;
				q.push({ nx, ny });
			}
		}

		if (d1[cur.x][cur.y] + 1 == depthSearch) break;
	}

	queue<Position> q2;
	q2.push(kingPos);

	int ans = 101;

	while (!q2.empty()) {
		auto cur = q2.front();
		q2.pop();

		if (d1[cur.x][cur.y] && abs(d1[cur.x][cur.y] - d2[cur.x][cur.y]) <= 1) {
			ans = min(ans, max(d1[cur.x][cur.y], d2[cur.x][cur.y]));
		}

		for (int i = 0; i < 8; i++) {
			int nx = cur.x + dx2[i];
			int ny = cur.y + dy2[i];

			if (isSafe(nx, ny) && !d2[nx][ny]) {
				d2[nx][ny] = d2[cur.x][cur.y] + 1;
				q2.push({ nx, ny });
			}
		}

		if (d2[cur.x][cur.y] + 1 == depthSearch) break;
	}

	if (ans != 101)
		cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}