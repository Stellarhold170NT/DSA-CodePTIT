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
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

class Data {
public:
	int x, y;
	int c;
	bool operator < (const Data& other) const {
		return this->c > other.c;
	}
};

int n, m;
int edge[501][501];
int dx[] = { 0 , -1, 0 , 1 };
int dy[] = { 1, 0, -1, 0 };
int dist[501][501];

bool isSafe(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
	return false;
}

void dijkstra() {
	priority_queue<Data> q;
	q.push({ 1, 1, 0 });

	while (!q.empty()) {
		Data current = q.top();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = current.x + dx[i];
			int ny = current.y + dy[i];

			if (isSafe(nx, ny)) {
				int nw = dist[current.x][current.y] + edge[nx][ny];
				if (nw < dist[nx][ny]) {
					dist[nx][ny] = nw;
					q.push({ nx, ny, dist[nx][ny] });
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dist[i][j] = 10000000;
				cin >> edge[i][j];
			}
		}
		dist[1][1] = edge[1][1];

		dijkstra();

		cout << dist[n][m] << endl;
	}

	return 0;
}