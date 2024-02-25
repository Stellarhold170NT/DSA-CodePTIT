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

int n, m;
bool check;
bool visited[1001] = { false };
vector<int> res;
int path[1001];
int last;

void dfs(int s, vector<int> edges[]) {
	if (check) return;
	visited[s] = true;

	for (auto x : edges[s]) {
		if (!visited[x]) {
			path[x] = s;
			dfs(x, edges);
		}
		else
			if (x == 1 && x != path[s]) {
				check = true;
				last = s;
				return;
			}


	}

}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int v, e;
		cin >> v >> e;

		vector<int> edges[1001];
		memset(visited, false, sizeof visited);
		memset(path, 0, sizeof path);

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		check = false;

		for (int i = 1; i <= v; i++) sort(edges[i].begin(), edges[i].end());

		dfs(1, edges);
		if (!check) cout << "NO";
		else {
			vector<int> res;
			cout << 1 << " ";
			while (path[last]) {
				res.push_back(last);
				last = path[last];
			}

			for (int i = res.size() - 1; i >= 0; i--) {
				cout << res[i] << " ";
			}
			cout << 1;
		}
		cout << endl;
	}

	return 0;
}

/*
Cach 2
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

int n, m;
bool check;
bool visited[1001] = { false };
vector<int> res;

void dfs(int s, int par, vector<int> edges[]) {
	if (check) return;
	visited[s] = true;

	for (auto x : edges[s]) {
		if (x == 1 && x != par) {
			check = true;
			return;
		}
		if (!visited[x]) {
			if (!check) res.push_back(x);
			dfs(x, s, edges);
			if (!check) res.pop_back();
		}
	}

}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int v, e;
		cin >> v >> e;

		res.clear();

		vector<int> edges[1001];
		memset(visited, false, sizeof visited);

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

			for (int i = 1; i <= v; i++) sort(edges[i].begin(), edges[i].end());

		check = false;
		dfs(1, 0, edges);
		if (!check || res.size() == 0) cout << "NO";
		else {
			cout << 1 << " ";
			for (auto x : res) cout << x << " ";
			cout << 1;
		}
		cout << endl;
	}

	return 0;
}

*/