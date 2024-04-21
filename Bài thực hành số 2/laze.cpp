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
#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"

const int N = 100;
int n;
int nx, yx;
int x[N], y[N];
char map2D[N][N];

int compress(int a[N], int n) {
	int t[N];
	memcpy(t, a, sizeof t);
	sort(t, t + n);
	int sizeT = unique(t, t + n) - t;
	for (int i = 0; i < n; i++) {
		a[i] = (lower_bound(t, t + sizeT, a[i]) - t);
	}
	return sizeT;
}

struct Point {
	int x, y;
	int dist;
};

int main() {
	cin >> n;

	for (int i = 0; i < n + 2; i++) {
		cin >> x[i] >> y[i];
	}

	nx = compress(x, n + 2);
	yx = compress(y, n + 2);

	vector<Point> row[N];
	vector<Point> col[N];

	for (int i = 1; i < n + 2; i++) {
		row[x[i]].push_back({ x[i], y[i], 0 });
		col[y[i]].push_back({ x[i], y[i], 0 });
	}

	int r[N] = { 0 };
	int c[N] = { 0 };

	queue<Point> q;
	q.push({ x[0], y[0], 0 });

	int ans = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		cout << cur.x << " " << cur.y << endl;

		if (cur.x == x[1] && cur.y == y[1]) {
			ans = cur.dist;
			break;
		}

		if (!r[cur.x]) {
			r[cur.x] = 1;
			for (auto& x : row[cur.x]) {
				if (!c[x.y]) {
					x.dist = cur.dist + 1;
					cout << x.dist << endl;
					q.push(x);
				}
			}
		}

		if (!c[cur.y]) {
			c[cur.y] = 1;
			for (auto& y : col[cur.y]) {
				if (!r[y.x]) {
					y.dist = cur.dist + 1;
					cout << y.dist << endl;
					q.push(y);
				}
			}
		}
	}

	cout << ans - 1 << endl;


	// in
	/*
	memset(map2D, '.', sizeof map2D);

	map2D[x[0]][y[0]] = '*';
	map2D[x[1]][y[1]] = '*';

	for (int i = 0; i < n; i++) {
		int a = i + 2;
		map2D[x[a]][y[a]] = '#';
	}

	for (int i = 0; i <= nx; i++) {
		for (int j = 0; j <= yx; j++) {
			cout << map2D[i][j];
		}
		cout << endl;
	}
	*/
	return 0;
}