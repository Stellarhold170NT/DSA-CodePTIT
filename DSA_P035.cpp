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
#include <climits>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200
#define ll long long

#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define vi vector<ll>
#define pii pair<int,ll>
#define fi first
#define se second
#define MAX 1001

const ll INF = 1000000000000000000;


int n, m, k;
vector<pii> edge[MAX];
vi c;
ll d[17][MAX];
ll dp[1 << 17][17];

void dijkstra(int x) {
	for (int i = 1; i <= n; i++) {
		d[x][i] = INF;
	}

	d[x][c[x]] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> p;
	p.push({ 0, c[x] });

	while (!p.empty()) {
		pii cur = p.top();
		p.pop();
		if (cur.first != d[x][cur.se]) continue;

		for (auto i : edge[cur.se]) {
			if (d[x][i.first] > d[x][cur.second] + i.second) {
				d[x][i.first] = d[x][cur.second] + i.second;
				p.push({ d[x][i.first], i.first });
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;

	k++;
	c.resize(k);
	c[0] = 1;
	for (int i = 1; i < k; i++) cin >> c[i];

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edge[a].push_back({ b, w });
	}

	for (int mask = 0; mask < (1 << k); mask++) {
		for (int i = 0; i < k; i++) {
			dp[mask][i] = INF;
		}
	}

	for (int i = 0; i < k; i++) {
		dijkstra(i);
	}

	dp[1][0] = 0;

	for (int mask = 1; mask < (1 << k); mask++)
		if (mask & 1) {
			for (int u = 0; u < k; u++) {
				if ((mask > 1 && u == 0)) continue;
				if (!(mask & 1)) continue;
				if ((mask & (1 << u)) == 0) continue;

				for (int v = 0; v < k; v++) {
					if (u == v) continue;
					if (mask & (1 << v)) continue;

					int next_mask = mask | (1 << v);
					dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + d[u][c[v]]);
				}
			}
		}

	ll ans = INF;
	for (int i = 1; i < k; i++) {
		ans = min(ans, dp[(1 << k) - 1][i] + d[i][1]);
	}

	if (ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}