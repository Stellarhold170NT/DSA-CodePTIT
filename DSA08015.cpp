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

struct Node {
	int x, y, z;
};

Node S, E;

char ch[31][31][31];
int f[31][31][31];

int dx[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 1, -1, 0, 0 };

int a, b, c;

bool isSafe(int x, int y, int z) {
	if (x >= 1 && x <= a && y >= 1 && y <= b && z >= 1 && z <= c && ch[x][y][z] != '#' && !f[x][y][z]) return true;
	return false;
}

int BFS() {
	memset(f, 0, sizeof f);
	f[S.x][S.y][S.z] = 1;
	queue<Node> q;
	q.push({ S.x, S.y, S.z });

	Node cur;

	int ans = 0;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur.x == E.x && cur.y == E.y && cur.z == E.z) {
			ans = f[cur.x][cur.y][cur.z];
			break;
		}

		for (int i = 0; i < 6; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nz = cur.z + dz[i];

			if (isSafe(nx, ny, nz)) {
				f[nx][ny][nz] = f[cur.x][cur.y][cur.z] + 1;
				q.push({ nx, ny, nz });
			}
		}
	}

	return ans - 1;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> a >> b >> c;

		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				for (int k = 1; k <= c; k++) {
					cin >> ch[i][j][k];

					if (ch[i][j][k] == 'S') {
						S = { i, j, k };
					}

					if (ch[i][j][k] == 'E') {
						E = { i, j, k };
					}
				}
			}
		}

		cout << BFS() << endl;
	}

	return 0;
}