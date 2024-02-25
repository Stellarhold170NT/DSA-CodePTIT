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

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2 , -2, -1 };

struct toa_do {
	int x;
	int y;
};

int dist[9][9];

toa_do get_pos(string s) {
	int x = s[0] - 'a' + 1;
	int y = s[1] - '0';
	return { y, x };
}

bool isSafe(int x, int y) {
	if (x >= 1 && x <= 8 && y >= 1 && y <= 8 && !dist[x][y]) return true;
	return false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string a, b;
		cin >> a >> b;

		memset(dist, 0, sizeof dist);

		toa_do x = get_pos(a);
		toa_do y = get_pos(b);

		queue<toa_do> q;
		q.push(x);

		while (!q.empty()) {
			toa_do cur = q.front();
			q.pop();

			if (cur.x == y.x && cur.y == y.y) {
				cout << dist[y.x][y.y] << endl;
				break;
			}

			for (int i = 0; i < 8; i++) {
				if (isSafe(cur.x + dx[i], cur.y + dy[i])) {
					dist[cur.x + dx[i]][cur.y + dy[i]] = dist[cur.x][cur.y] + 1;
					q.push({ cur.x + dx[i] , cur.y + dy[i] });
				}
			}
		}
	}

	return 0;
}