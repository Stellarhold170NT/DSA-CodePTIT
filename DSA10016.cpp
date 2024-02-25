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

class Edge {
public:
	int x, y;
	double c;
};

int n;
vector <pair<double, double>> point;
int par[1001];

void init() {
	for (int i = 1; i <= n; i++) par[i] = i;
}

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

bool check(Edge x) {
	int u = x.x;
	int v = x.y;

	u = find(u);
	v = find(v);

	if (u == v) return false;
	par[v] = u;
	return true;
}


double calc(int i, int j) {
	double x = (point[j].first - point[i].first);
	double y = (point[j].second - point[i].second);
	return sqrt(x * x + y * y);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		point.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			cin >> point[i].first >> point[i].second;
		}

		vector<Edge> edge;

		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				edge.push_back({ i, j, calc(i, j) });
			}
		}

		sort(edge.begin(), edge.end(), [](Edge& a, Edge& b) {
			return a.c < b.c;
			});

		init();

		double res = 0.0;

		for (auto x : edge) {
			if (!check(x)) continue;
			res = res + x.c;
		}

		cout << stp(6) << res << endl;
	}

	return 0;
}