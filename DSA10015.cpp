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

int v, e;
int par[1001];

class Edge {
public:
	int a, b, c;
};

void init() {
	for (int i = 1; i <= v; i++) par[i] = i;
}

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

bool check(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;
	par[v] = u;
	return true;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> v >> e;

		vector<Edge> edge;

		for (int i = 0; i < e; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edge.push_back({ a, b, c });
		}

		sort(edge.begin(), edge.end(), [](Edge& a, Edge& b) {
			return a.c < b.c;
			});

		int res = 0;

		init();

		for (auto x : edge) {
			if (!check(x.a, x.b)) continue;
			res = res + x.c;
		}

		cout << res << endl;
	}


	return 0;
}