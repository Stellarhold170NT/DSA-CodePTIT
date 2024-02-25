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

class Node {
public:
	int s;
	int c;
public:
	bool operator < (const Node& otherNode) const {
		return this->c > otherNode.c;
	}
};

bool cmp(Node& a, Node& b) {
	return a.c > b.c;
}

int v, e, u;
int dist[1000][1000];

void dijkstra(int u, vector<Node> edge[]) {
	priority_queue<Node> q;
	for (int i = 1; i <= v; i++) dist[u][i] = 1000000;
	dist[u][u] = 0;
	q.push({ u, 0 });

	while (!q.empty()) {
		Node current = q.top();
		q.pop();

		for (auto x : edge[current.s]) {
			int nx = x.s;
			int nw = dist[u][current.s] + x.c;

			if (nw < dist[u][x.s]) {
				dist[u][x.s] = nw;
				q.push({ x.s, nw });
			}
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> v >> e >> u;

		vector<Node> edge[10001];

		for (int i = 0; i < e; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edge[a].push_back({ b, c });
			edge[b].push_back({ a, c });
		}

		dijkstra(u, edge);

		for (int i = 1; i <= v; i++) {
			cout << dist[u][i] << " ";
		}
		cout << endl;
	}

	return 0;
}