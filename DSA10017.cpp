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
bool check;
bool visited[1001];

class Data {
public:
	int x, c;
};

bool bfs(int s, vector<Data> edge[]) {
	visited[s] = true;
	queue<pair<int, int>> q;
	visited[s] = true;
	q.push({ s, 0 });

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (auto x : edge[p.first]) {
			if (!visited[x.x]) {
				visited[x.x] = true;
				q.push({ x.x, p.second + x.c });
			}
			else if (x.x == s && p.second + x.c < 0) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> v >> e;

		vector<Data> edge[1001];
		for (int i = 0; i < e; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edge[a].push_back({ b, c });
			//edge[b].push_back({ a, c });
		}

		check = false;

		for (int i = 1; i <= v && !check; i++) {
			memset(visited, false, sizeof visited);
			check = bfs(i, edge);
		}

		if (check) cout << 1;
		else cout << 0;
		cout << endl;
	}

	return 0;
}