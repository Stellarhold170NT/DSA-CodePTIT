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

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

struct DATA {
	int x, y;
};

int n, m;
const int LIM = 1005;
int arr[LIM][LIM];

bool isSafe(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		queue<DATA> q;

		q.push({ 0, 0 });
		int dist[LIM][LIM];
		memset(dist, 0, sizeof dist);

		int res = -1;

		while (!q.empty()) {
			DATA cur = q.front();
			int x = cur.x;
			int y = cur.y;
			q.pop();

			if (x == n - 1 && y == m - 1) {
				res = dist[x][y];
				break;
			}

			if (isSafe(x + arr[x][y], y) && !dist[x + arr[x][y]][y]) {
				dist[x + arr[x][y]][y] = dist[x][y] + 1;
				q.push({ x + arr[x][y], y });
			}
			if (isSafe(x, y + arr[x][y]) && !dist[x][y + arr[x][y]]) {
				dist[x][y + arr[x][y]] = dist[x][y] + 1;
				q.push({ x , y + arr[x][y] });
			}
		}

		cout << res << endl;
	}

	return 0;
}