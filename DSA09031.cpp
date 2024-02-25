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
#define MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 5000000 + 11
#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int arr[101][101];
bool visited[101][101];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int n, k, m;
int cnt = 0;
int res = 0;

class toado {
public:
	int x;
	int y;
};

bool operator < (toado a, toado b) {
	return (a.x < b.x || ((a.x == b.x) && (a.y < b.y)));
}

map<pair<toado, toado>, int> mp;
vector<toado> v;

bool isSafe(int x, int y) {
	if (x >= 1 && y >= 1 && x <= n && y <= n) return true;
	return false;
}

void dfs(toado s) {
	//cout << s.x << " " << s.y << endl;
	if (arr[s.x][s.y]) cnt++;
	visited[s.x][s.y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = s.x + dx[i];
		int ny = s.y + dy[i];
		toado ns = { nx, ny };
		if (isSafe(nx, ny)) {
			if (!visited[nx][ny] && !mp[{s, ns}])
				dfs({ nx, ny });
		}
	}
}

int main() {
	cin >> n >> k >> m;
	memset(visited, false, sizeof visited);
	memset(arr, 0, sizeof arr);

	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		toado t1 = { a, b };
		toado t2 = { c , d };
		mp[{t1, t2}] = 1;
		mp[{t2, t1}] = 1;
	}

	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		v.push_back({ a, b });
	}

	int t = 0;

	for (int i = 0; i < k; i++) {
		if (!visited[v[i].x][v[i].y]) {
			dfs(v[i]);
			//cout << cnt << endl;
			res = res + cnt * t;
			t = t + cnt;
			cnt = 0;
		}
	}

	cout << res << endl;

	return 0;
}