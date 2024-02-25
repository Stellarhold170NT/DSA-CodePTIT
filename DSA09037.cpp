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

int k, n, m;
vector<int> v;
vector<int> edge[1001];
bool visited[1001];
map<int, int> mp;

void dfs(int s) {
	mp[s]++;
	visited[s] = true;

	for (int x : edge[s]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}

int main() {
	int k, n, m;
	cin >> k >> n >> m;

	v.resize(n);

	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}

	for (int i = 0; i < k; i++) {
		memset(visited, false, sizeof visited);
		dfs(v[i]);
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (mp[i] == k) {
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}